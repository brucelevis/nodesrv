module('Client', package.seeall)

gatesrv_component = gatesrv_component or nil

function awake(self)
    loginfo('awake')
    self:reg_msg(MSG_NEW_SESSION)
    self:reg_msg(MSG_CLOSE_SESSION)
    self:reg_msg(MSG_NET_PACKET)
    gatesrv_component = self:get_component('GateSrv')
    if not gatesrv_component then
        logerr('gatesrv component not found')
        os.exit(0)
    end
end

function recv(self, msg)
    local id = msg.header.id
    if id == MSG_NEW_SESSION then
        recv_new_session(self, msg)
    elseif id == MSG_CLOSE_SESSION then
        recv_close_session(self, msg)
    elseif id == MSG_NET_PACKET then
        recv_net_packet(self, msg)
    end
end

function recv_new_session(self, msg)
    loginfo('recv_new_session %d', msg.sid)
end

function recv_close_session(self, msg)
    loginfo('recv_close_session %d', msg.sid)
    Login.player_disconnect(msg.sid)
end

function recv_net_packet(self, msg)
    --loginfo('recv_net_packet %d', msg.payload:size())
    local sid = msg.sid
    local msgname = msg.payload:read_utf8()
    loginfo('RECV NET PACKET %s', msgname)

    local reply = msg.payload:read_protobuf(msgname, msg.payload:size())
    if not reply then
        return
    end
    logmsg(reply:debug_string())

    local pats = string.split(msgname, '.')
    local modname = pats[1]
    local funcname = pats[2]

    local router =  Config.gatesrv.router[modname]
    if router then
        if router.scenesrv then
            local player = Login.player_session[sid]
            if not player then
                logerr('player not found')
                return
            end
            if not player.scenesrv then
                logerr('player is not in scenesrv')
                return
            end
            POST(player.scenesrv, 'Player.RECV', player.uid, reply)
        end
        return
    end

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
    func(msg.sid, reply)

    logmsg('RECV NET PACKET %s FINISH', msgname)
end

function reply(sid, reply)
    gatesrv_component:reply(sid, reply)
end

function update(self)

end

