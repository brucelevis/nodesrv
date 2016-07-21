module('Login', package.seeall)

player_manager = player_manager or {
    --[uid] = player
}

player_count = player_count or 0

--功能:进入服务器
function PLAYER_LOGIN(gatesrv, uid)
    loginfo('player enter uid(%d)', uid)
    local player = player_manager[uid]
    if player then
        logerr('player online yet uid(%d)', uid)
        POST(player.gatesrv, 'Login.PLAYER_INSTEAD', uid)
    else
        --建立session
        local player = {
            gatesrv = gatesrv, 
            uid = uid,
        }
        player_manager[uid] = player
        player_count = player_count + 1
        POST(gatesrv, 'Login.PLAYER_LOGIN', uid)
    end
end

--功能:退出服务器
function PLAYER_LOGOUT(gatesrv, uid)
    loginfo('player exit uid(%d)', uid)
    local player = player_manager[uid]
    if not player then
        logerr('player out found uid(%d)', uid)
        POST(gatesrv, 'Login.PLAYER_LOGOUT', uid)
        return
    end
    player_manager[uid] = nil
    player_count = player_count - 1
    POST(gatesrv, 'Login.PLAYER_LOGOUT', uid)
end

function ENTER_SRV(gatesrv, uid, srvid)
    local player = player_manager[uid]
    if not player then
        logerr('player not found')
        return
    end
    if player.scenesrv ~= nil then
        loginfo('exit last scenesrv')
        player.toenter_scenesrv = scenesrv1
        POST(player.scenesrv, 'Login.PLAYER_EXIT', uid)
        return
    end
    POST(scenesrv1, 'Login.PLAYER_ENTER', player.gatesrv, uid)
end

function PLAYER_ENTER(scenesrv, uid)
    local player = player_manager[uid]
    if not player then
        logerr('player not found')
        return
    end
    player.scenesrv = scenesrv
    POST(player.gatesrv, 'Login.PLAYER_ENTER', uid, scenesrv)
end

function PLAYER_EXIT(scenesrv, uid)
    local player = player_manager[uid]
    if not player then
        logerr('player not found')
        return
    end
    if player.scenesrv ~= scenesrv then
        return
    end
    player.scenesrv = nil
    if player.toenter_scenesrv then
        player.toenter_scenesrv = nil
        POST(scenesrv1, 'Login.PLAYER_ENTER', player.gatesrv, uid)
    end
    if player.logout then
        player.logout = true
        player_logout(player)
    end
end
