module('WebSocket', package.seeall)

http_component = http_component or nil 

function awake(self)
    loginfo('awake')
    self:reg_msg(MSG_NEW_SESSION)
    self:reg_msg(MSG_CLOSE_SESSION)
    self:reg_msg(MSG_NET_PACKET)
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
end

function recv_net_packet(self, msg)
    loginfo('recv_net_packet %d', msg.payload:size())
    local msg_name = msg.payload:read_utf8()
    local reply = msg.payload:read_protobuf(msg_name, msg.payload:size())
    print(reply:debug_string())
end


function reply(msg)

end
