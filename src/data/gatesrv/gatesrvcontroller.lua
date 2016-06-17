module('GateSrvController', package.seeall)
--[[
脚本组件
--]]

function awake(self)
    print('GateSrvController awake')
    --可以在这里设置成员的值
    local net_component = self:get_component('NetComponent')
    net_component:listen('0.0.0.0', 6666)
    self.xxx = 333
    self:reg_msg(MSG_NET_PACKET)
end

function start(self)

end

is_sent = false

function update(self, tick)
    if not is_sent then
        --local buffer = Buffer:temp()
        --buffer:write_int8(3)
        --buffer:write_int8(3)
        --NodeMgr.send_entity_msg(self.entity, 2, 0, 111, buffer)
        --print('ActorController update', self.xxx)
        --local login_login = RpcMessage.encode('Login.LOGIN', 1, 2, 3, 4)
        --NodeMgr.send_entity_msg(self.entity, 2, 0, 1233, login_login)
        --NodeMgr.create_entity_remote(self.entity, 2, 'GameSrvPrefab')
        --is_sent = true
    end
end

function recv(self, msg)
    print('recv', self, msg, msg.id, msg.data, msg.sid)
    local http_component = self:get_component('HttpComponent')
    http_component:send_string_frame(msg.sid, msg.data)
    --GamesrvRPC.ActorController.hello(1, 2, 3, 4)
end
