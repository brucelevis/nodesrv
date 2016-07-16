module('Player', package.seeall)

function RECV(gatesrv, uid, msg)
    local player = Login.player_manager[uid]
    if not player then
        logerr('player not found')
        return
    end
    local msgname = msg:msgname()
    local pats = string.split(msgname, '.')
    local modname = pats[1]
    local funcname = pats[2]
    local mod = _G[string.cap(modname)]
    if not mod then
        logerr('mod(%s) not found', msgname)
        return
    end
    local func = mod['MSG_'..funcname]
    if not func then
        logerr('func(msgname) not found', msgname)
        return
    end
    func(player, msg)
end

function reply(player, msg)
    POST(player.gatesrv, 'Player.REPLY', player.uid, msg)
end



