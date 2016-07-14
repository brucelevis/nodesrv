module('Player', package.seeall)


function REPLY(srvid, uid, msg)
    local player = Login.player_manager[uid]
    if not player then
        logerr('player not found')
        return
    end
    WebSocket.reply(player.sid, msg)
end

