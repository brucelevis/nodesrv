module('Login', package.seeall)

player_manager = player_manager or {
    --[uid] = player
}

player_count = player_count or 0

function PLAYER_ENTER(scenesrv, uid)
    loginfo('player enter uid(%d)', uid)
    local player = player_manager[uid]
    if not player then
        logerr('player online uid(%d)', uid)
        local player = {
            uid = uid,
            scenesrv = scenesrv,
            time = os.time()
        }
        player_manager[uid] = player
        player_count = player_count + 1
        POST(scenesrv, 'Login.PLAYER_PASS', uid)
    elseif player.scenesrv then
        loginfo('player instead uid(%d)', uid)
        player.instead_scenesrv = scenesrv
        POST(scenesrv, 'Login.PLAYER_INSTEAD', uid)
    else
        logerr('player is not in scenesrv??')
    end
end

function PLAYER_EXIT(scenesrv, uid)
    loginfo('player exit uid(%d)', uid)
    local player = player_manager[uid]
    if not player then
        logerr('player out found uid(%d)', uid)
        return
    end
    if player.scenesrv ~= scenesrv then
        logerr('player exit from a different scene, srvid(%s) from srvid(%s)', player.scenesrv, scenesrv)
        return
    end
    player_manager[uid] = nil
    player_count = player_count - 1
    if player.instead_scenesrv then
        player.scenesrv = player.instead_scenesrv
        player.instead_scenesrv = nil
        player_manager[uid] = player
        player_count = player_count + 1
        POST(player.scenesrv, 'Login.PLAYER_PASS', uid)
    end
end


