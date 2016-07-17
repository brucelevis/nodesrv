module('Login', package.seeall)

--临时
tmp_player_manager = tmp_player_manager or {
    --[uid] = gatesrv
}
player_manager = player_manager or {
    --[uid] = player
}

player_count = player_count or 0

--功能:进入服务器
function PLAYER_LOGIN(gatesrv, uid)
    loginfo('player enter uid(%d)', uid)
    tmp_player_manager[uid] = gatesrv 
    local player = player_manager[uid]
    if player then
        logerr('player online yet uid(%d)', uid)
        player_logout(player)
        return
    end
    player_login(uid)
end

--功能:退出服务器
function PLAYER_LOGOUT(gatesrv, uid)
    loginfo('player exit uid(%d)', uid)
    tmp_player_manager[uid] = nil
    local player = player_manager[uid]
    if not player then
        logerr('player out found uid(%d)', uid)
        POST(gatesrv, 'Login.PLAYER_LOGOUT', uid)
        return
    end
    player_logout(player)
end

--功能:登陆成功
function player_online(player)
    local uid = player.uid
    local user = player.playerdata.user
    local last_login_time = user.last_login_time
    local rt, err = pcall(Player.init, player)
    if not rt then
        loginfo(err)
    end
    local msg = Pblua.msgnew('login.LOGIN')
    msg.uid = uid
    Player.reply(player, msg)
end

function player_login(uid)
    --开始加载数据
    POST(dbsrv1, 'DbSrv.GET', uid, 'Login.msg_db_srv_get_playerdata', unpack(Config.localsrv.playerdata))
end

--功能:下线
function player_logout(player)
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
    POST(dbsrv1, 'DbSrv.SET', uid, 'Login.msg_db_srv_set_playerdata', unpack(args)) 
end

--功能:保存数据dv_srv返回
--@msg db_srv.SET_REPLY
function msg_db_srv_set_playerdata(dbsrv, uid, result, ...)
    local player = player_manager[uid]
    if not player then
        logerr('player offline yet')
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
    POST(player.gatesrv, 'Login.PLAYER_LOGOUT', uid)

    if tmp_player_manager[uid] then
        player_login(uid)
    end
end

--功能:读取数据返回
function msg_db_srv_get_playerdata(dbsrv, uid, result, ...) 
    --如果没有锁住
    local gatesrv = tmp_player_manager[uid]
    if not gatesrv then
        logerr('tmp player is disconnect')
        return
    end
    local player = player_manager[uid]
    if player then
        logerr('player is online yet')
        return
    end
    if result == 0 then
        POST(gatesrv, 'Login.PLAYER_LOGOUT', uid)
        logerr('load playerdata fail uid(%d)', uid)
        return
    end
    local playerdata = {}
    local args = {...}
    for index, varname in pairs(Config.localsrv.playerdata) do
        playerdata[varname] = args[index]
    end
    POST(gatesrv, 'Login.PLAYER_LOGIN', uid)
    loginfo( '加载数据成功')
    --建立session
    local player = {
        gatesrv = gatesrv, 
        uid = uid,
        playerdata = playerdata,
        last_save_time = os.time(),
    }
    player_manager[uid] = player
    tmp_player_manager[uid] = nil
    player_count = player_count + 1
    local rt, err = pcall(player_online, player)
    if not rt then
        logerr(err)
        player_logout(player)
    end
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
            --POST(dbsrv1, 'DbSrv.SET', uid, 'Login.msg_db_srv_set_playerdata', unpack(args)) 
            --player.last_save_time = timenow
        --end
    --end
--end
