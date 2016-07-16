module('TelnetSrv', package.seeall)
--[[
telnet 协议实现的管理后台
--]]

net_component = net_component or nil 

function hello()
    return 'asfafsd'
end

function awake(self)
    loginfo('awake')
    self:reg_msg(MSG_NEW_CONNECTION)
    self:reg_msg(MSG_CLOSE_CONNECTION)
    self:reg_msg(MSG_NET_RAW_DATA)
    net_component = self:get_component('NetComponent')
end

function recv(self, msg)
    local id = msg.header.id
    if id == MSG_NEW_CONNECTION then
        return recv_new_connection(self, msg)
    elseif id == MSG_CLOSE_CONNECTION then
        return recv_close_connection(self, msg)
    elseif id == MSG_NET_RAW_DATA then
        return recv_net_raw_data(self, msg)
    end
end

function recv_new_connection(self, msg)
    loginfo('recv_new_connection %d', msg.sid)
end

function recv_close_connection(self, msg)
    loginfo('recv_close_connection %d', msg.sid)
end

function recv_net_raw_data(self, msg)
    loginfo('recv_net_raw_data %d', msg.sid)
    local data = msg.data
    local f = loadstring(data)
    if not f then
        reply(msg.sockfd, string.format('FAIL %s', data))
        return msg.datalen
    end
    local result, err = pcall(f)
    if not result then
        reply(msg.sockfd, string.format('ERROR %s', err))
        return msg.datalen
    end
    reply(msg.sockfd, string.format('%s', err or 'OK'))
    return msg.datalen
end


function reply(sockfd, reply)
    net_component:send_str(sockfd, reply)
    net_component:send_str(sockfd, '\n>')
end
