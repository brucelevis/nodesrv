module('DbSrv', package.seeall)

descriptors = {}

function main()
    --构建descriptor
    for table_name, table_conf in pairs(Config.dbsrv.table_conf) do
        if not table_conf.binary then
            DbSrv.descriptors[table_name] = Pblua.get_descriptor(table_conf.file)
        end
    end
    check_redis_connections()
    check_mysql_connections()
end

function update()

end

--功能:从MYSQL读取数据
--@uid 玩家id
--@table_name 表名
--@return false.出错 nil.没有数据 string.返回数据
local function select_from_mysql(uid, table_name)
    local conn = select_mysql_connection(uid)
    if not conn then
        logerr('mysql not connect')
        return false
    end
    local sql_str = string.format('SELECT * FROM %s where uid=%d', table_name, uid)
    local cursor = conn:select(sql_str)
    if not cursor then
        logerr('table is not data')
        return false
    end
    local result = cursor[1] and cursor[1] or nil
    if not cursor then
        logerr('select %d.%s fail', uid, table_name)
        return false
    end
    local pb_class = Config.dbsrv.table_conf[table_name].class
    local msg = Pblua.msgnew(pb_class)
    if not result then
        return msg, ''
    end
    local descriptor = descriptors[table_name]
    if descriptor then
        local fields = descriptor
        for field_name, field in pairs(fields) do
            if field.type == 'message' then
                local field_msg = msg[field_name]
                if not field_msg:parse_from_string(result[field_name]) then
                    logerr('%d.%s.%s parse fail', uid, table_name, field_name)
                    return false
                end
            else
                msg[field_name] = result[field_name]
            end
        end
        local table_bin = msg:tostring()
        if not table_bin then
            logerr('load from mysql %d.%s tostring fail', uid, table_name)
            return false
        end
        loginfo('load from mysql %d.%s(%d)', uid, table_name, string.len(table_bin))
        return msg, table_bin
    else
        local table_bin = result.bin
        msg:parse_from_string(table_bin)
        loginfo('load from mysql %d.%s(%d)', uid, table_name, string.len(table_bin))
        return msg, table_bin
    end
end

function get_from_redis(srvid, uid, callback, ...)
    local table_array = {...}
    local msg_array = {}
    local hmget_str = string.format('HMGET %d ', uid)
    for _, table_name in pairs(table_array) do
        hmget_str = hmget_str..' '..table_name..' '
    end
    --从redis拉数据
    local conn = select_redis_connection(uid)
    if not conn then
        return
    end
    local redis_reply = Redis.command(conn, hmget_str)
    if not redis_reply then
        logerr('HMGET fail command(%s)', hmget_str, reply_reply.value)
        return
    end
    if redis_reply.type ~= 'array' then
        logerr('HMGET fail command(%s) error(%s)', hmget_str, redis_reply.value)
        return
    end
    local total_size = 0
    if redis_reply and redis_reply.type == 'array' then
        for idx, v in pairs(redis_reply.value) do
            local table_name = table_array[idx]
            if v.type == 'string' then
                local msg = Pblua.msgnew(Config.dbsrv.table_conf[table_name].class)
                msg:parse_from_string(v.value)
                table.insert(msg_array, msg)
                loginfo('load from redis %d.%s(%d)', uid, table_name, string.len(v.value))
                loginfo(msg:debug_string())
                total_size = total_size + string.len(v.value)
            else
                return
            end
        end
    end
    Redis.command(conn, string.format('EXPIRE %d %d', uid, Config.dbsrv.expire_sec))
    POST(srvid, callback, uid, 1, unpack(msg_array))
    return true
end

function get_from_mysql(srvid, uid, callback, ...)
    local total_size = 0
    local table_array = {...}
    local msg_array = {}
    local mset_args = {}
    for _, table_name in pairs(table_array) do
        local msg, table_bin = select_from_mysql(uid, table_name)
        if not msg then
            POST(srvid, callback, uid, 0)
            return
        else
            table.insert(msg_array, msg)
            table.insert(mset_args, table_name)
            table.insert(mset_args, table_bin)
            total_size = total_size + string.len(table_bin)
        end
    end
    loginfo('total_size(%d)', total_size)
    --存到redis
    local conn = select_redis_connection(uid)
    if conn then
        Redis.hmset(conn, uid, unpack(mset_args))
        Redis.command(conn, string.format('EXPIRE %d %d', uid, Config.dbsrv.expire_sec))
    end
    POST(srvid, callback, uid, 1, unpack(msg_array))
end

--功能:取玩家表
function GET(srvid, uid, callback, ...)
    if get_from_redis(srvid, uid, callback, ...) then
        return
    end
    if get_from_mysql(srvid, uid, callback, ...) then
        return
    end
end

--保存到redis
function set_to_redis(srvid, uid, callback, ...)
    local args = {...}
    local mset_args = {}
    local savelist = ''..uid
    for i = 1, #args, 2 do
        local table_name = args[i]
        local msg = args[i + 1]
        local table_bin = msg:tostring()
        table.insert(mset_args, table_name)
        table.insert(mset_args, table_bin)
        savelist = savelist..' '..table_name
    end
    local conn = select_redis_connection(uid)
    --存redis
    local redis_reply = Redis.hmset(conn, uid, unpack(mset_args))
    if not redis_reply or (redis_reply.type == 'status' and redis_reply.value ~= 'OK') then
        logerr('cache %d fail', uid)
        return
    end
    --EXPIRE
    local redis_reply = Redis.command(conn, string.format('EXPIRE %d %d', uid, Config.dbsrv.expire_sec))
    if not redis_reply or redis_reply.value ~= 1 then
        logerr('expire %d fail', uid)
        return
    end
    --存SAVE LIST
    if savelist ~= '' then
        local redis_reply = Redis.lpush(conn, 'savelist', savelist)
        if not redis_reply or redis_reply.type ~= 'integer' then
            logerr('queue %d FAIL', uid)
            return
        end
    end
    loginfo('cache to redis uid(%d) success',  uid)
    return true
end

function set_to_mysql(srvid, uid, callback, ...)
    local total_size = 0
    local args = {...}
    local conn = select_mysql_connection(uid)
    if not conn then
        logerr('select mysql connection fail')
        return
    end
    local timenow = os.time()
    for i = 1, #args, 2 do
        local table_name = args[i]
        local msg = args[i + 1]
        --是否要展开这个表
        local pb_class = Config.dbsrv.table_conf[table_name]
        loginfo(string.format('set_to_mysql uid(%d).%s', uid, table_name))
        if pb_class.binary then
            local table_bin = msg:tostring()
            local sql_str = string.format("replace into %s (uid, bin, updatetime) VALUES (%d, '%s', %d)", table_name, uid, conn:escape(table_bin), timenow)
            loginfo(sql_str)
            if not conn:command(sql_str) then
                logerr('%s replace fail', table_name)
                return
            end
            loginfo('save %d.%s(%d) success', uid, table_name, string.len(table_bin))
        else
            local descriptor = Pblua.get_descriptor(pb_class.class)
            local sql_str = string.format('replace into '..table_name..' (')
            for field_name, field in pairs(descriptor) do
                local value = msg[field_name]
                sql_str = sql_str..field_name..','
            end
            sql_str = sql_str..' updatetime) values ('
            for field_name, field in pairs(descriptor) do
                local value = msg[field_name]
                value = value and value or ''
                if field.type == 'int' then
                    sql_str = sql_str..value..','
                elseif field.type == 'string' then
                    sql_str = sql_str..'\''..conn:escape(value)..'\','
                elseif field.type == 'message' then
                    print(field_name, value)
                    sql_str = sql_str..'\''..conn:escape(value:tostring())..'\','
                end
            end
            sql_str = sql_str..timenow..')'
            loginfo(sql_str)
            if not conn:command(sql_str) then
                logerr('%s expand fail', table_name)
                return
            end
            loginfo('save %d.%s(%d) success', uid, table_name, msg:bytesize())
        end
    end
    return true
end

--功能:存玩家表
--@msg db_srv.SET
function SET(srvid, uid, callback, ...)
    if not set_to_redis(srvid, uid, callback, ...) then
        --写缓存失败，马上写数据库
        if not set_to_mysql(srvid, uid, callback, ...) then
            POST(srvid, callback, uid, 0)
            return
        else
            POST(srvid, callback, uid, 1)
            return
        end
    end
    if not Config.dbsrv.delay_write then
        if not set_to_mysql(srvid, uid, callback, ...) then
            POST(srvid, callback, uid, 0)
            return
        end
    end
    POST(srvid, callback, uid, 1)
end



