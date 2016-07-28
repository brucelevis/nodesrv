module('TelnetSrv', package.seeall)
--[[
telnet 协议实现的管理后台
--]]

net_component = net_component or nil 

local sessions = sessions or {}

function awake(self)
    loginfo('awake')
    self:reg_msg(MSG_NEW_CONNECTION)
    self:reg_msg(MSG_CLOSE_CONNECTION)
    self:reg_msg(MSG_NET_RAW_DATA)
    net_component = self:get_component('NetComponent')
    net_component:listen(Config.centersrv.telnetsrv.host, Config.centersrv.telnetsrv.port)
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
    loginfo('recv_new_connection %d', msg.sockfd)
end

function recv_close_connection(self, msg)
    loginfo('recv_close_connection %d', msg.sockfd)
    sessions[msg.sid] = nil
end

function recv_net_raw_data(self, msg)
    loginfo('recv_net_raw_data %d', msg.sockfd)
    local data = msg.data
    --if string.sub(data, -2, -1) == '\r\n' then
        --data = string.sub(data, 1, -3)
    --end
    --local pats = string.split(data, ' ')
    --local funcname = pats[1]
    --if funcname == 'reload' then
        --print('asfasf', #pats, unpack(pats))
        --if Admin[funcname] then
            --pats[1] = nil
            --Admin[funcname](unpack(pats))
        --end
        --return
    --end
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

function help()
    print('hello')
end

function reply(sockfd, reply)
    net_component:send_str(sockfd, reply)
    net_component:send_str(sockfd, '\n>')
end

function update()

end

