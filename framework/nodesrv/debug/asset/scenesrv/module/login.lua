module('Login', package.seeall)

player_manager = player_manager or {
    --[uid] = player
}
player_count = player_count or 0

function PLAYER_ENTER(localsrv, gatesrv, uid)
    local player = player_manager[uid] 
    if player then
        player.gatesrv = gatesrv
        return
    end
    player = {
        gatesrv = gatesrv,
        uid = uid
    }
    player_manager[uid] = player
    POST(datasrv1, 'DbSrv.GET', uid, 'Login.msg_db_srv_get_playerdata', unpack(Config.scenesrv.playerdata))
end

function PLAYER_EXIT(localsrv, uid)
    local player = player_manager[uid] 
    if not player then
        logerr('player not found')
        return
    end
    player_exit(player)
end

--功能:读取数据返回
function msg_db_srv_get_playerdata(dbsrv, uid, result, ...) 
    --如果没有锁住
    local player = player_manager[uid]
    if not player then
        logerr('player is exit')
        return
    end
    if result == 0 then
        logerr('load playerdata fail uid(%d)', uid)
        return
    end
    local playerdata = {}
    local args = {...}
    for index, varname in pairs(Config.localsrv.playerdata) do
        playerdata[varname] = args[index]
    end
    POST(localsrv, 'Login.PLAYER_ENTER', uid)
    loginfo( '加载数据成功')
    --建立session
    player.playerdata = playerdata
    player.last_save_time = os.time()
    player_count = player_count + 1
    local rt, err = pcall(Player.init, player)
    if not rt then
        logerr(err)
        player_exit(player)
    end
end

--功能:下线
function player_exit(player)
    local uid = player.uid
    local rt, err = pcall(Player.close, player)
    if not rt then
        logerr(err)
    end
    --保存数据
    local playerdata = player.playerdata
    local args = {}
    for table_name, msg in pairs(playerdata) do
        --是否有脏标志
        if true or msg:isdirty() then
            loginfo('uid(%d).%s is dirty', uid, table_name)
            table.insert(args, table_name)
            table.insert(args, msg)
        else
            loginfo('uid(%d).%s is clean', table_name)
        end
    end
    POST(datasrv1, 'DbSrv.SET', uid, 'Login.msg_db_srv_set_playerdata', unpack(args)) 
end

--功能:保存数据dv_srv返回
--@msg db_srv.SET_REPLY
function msg_db_srv_set_playerdata(dbsrv, uid, result, ...)
    local player = player_manager[uid]
    if not player then
        logerr('player had exit')
        return 
    end
    if result == 0 then
        logerr('save playerdata fail uid(%d)', uid)
        return
    end
    local playerdata = player.playerdata
    local user = playerdata.user
    local args = {...}
    for _, varname in pairs(args) do
        local msg = playerdata[table_name]
        --msg:setdirty(0)
    end
    --已经下线了
    for k, v in pairs(playerdata) do
        playerdata[k] = nil
    end
    player.playerdata = nil
    --释放数据
    player_manager[uid] = nil
    player_count = player_count - 1
    POST(localsrv, 'Login.PLAYER_EXIT', uid)
end

--功能:定时保存玩家数据
--function timer_check()
    --local timenow = os.time()
    --for uid, player in pairs(player_manager) do
        --local playerdata = player.playerdata
        --if timenow - player.last_save_time > Config.localsrv.save_interval then
            --local args = {}
            --for table_name, msg in pairs(playerdata) do
                --if true or msg:isdirty() then
                    --loginfo('uid(%d).%s is dirty', uid, table_name)
                    --table.insert(args, table_name)
                    --table.insert(args, msg)
                --else
                    --loginfo('uid(%d).%s is clean', table_name)
                --end
            --end
            --POST(datasrv1, 'DbSrv.SET', uid, 'Login.msg_db_srv_set_playerdata', unpack(args)) 
            --player.last_save_time = timenow
        --end
    --end
--end
