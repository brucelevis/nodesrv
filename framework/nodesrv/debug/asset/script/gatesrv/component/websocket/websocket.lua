module('WebSocket', package.seeall)

http_component = http_component or nil 

function awake(self)
    loginfo('awake')
    self:reg_msg(MSG_NEW_SESSION)
    self:reg_msg(MSG_CLOSE_SESSION)
    self:reg_msg(MSG_NET_PACKET)
    http_component = self:get_component('HttpComponent')
end

function recv(self, msg)
    loginfo('recv %d', msg.header.id) 
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
    local msgname = msg.payload:read_utf8()
    local reply = msg.payload:read_protobuf(msgname, msg.payload:size())
    loginfo(reply:debug_string())

    loginfo('recv_net_packet msgname(%s)', msgname)
    print(string.len(msgname), type(msgname))
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
    func(msg.sid, reply)
end


function reply(sid, reply)
    local buffer = Buffer:new_local()
    buffer:write_utf8(reply:msgname())
    buffer:write_protobuf(reply)
    http_component:send_binary_frame(sid, buffer)
end
