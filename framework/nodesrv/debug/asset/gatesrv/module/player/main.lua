module('Player', package.seeall)

function dispatch(player, msg)

end

function disconnect(sid)
    loginfo('disconnect sid %d', sid)
end

function reply(sid, msg)
    WebSocket.reply(sid, msg)
end

function REPLY(srvid, uid, msg)
    local player = Login.player_manager[uid]
    if not player then
        logerr('player not found')
        return
    end
    WebSocket.reply(player.sid, msg)
end

