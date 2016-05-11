module('ActorController', package.seeall)
--[[
脚本组件
--]]

function awake(self)
    print('ActorController awake')
    --可以在这里设置成员的值
    self.xxx = 333
    self:reg_msg(MSG_NET_PACKET)
    print(self:get_component('HttpComponent'))
end

function start(self)

end

function update(self, tick)
--    print('ActorController update', self.xxx)
end

function recv(self, msg)
    print('recv', self, msg, msg.id, msg.data, msg.sid)
    local http_component = self:get_component('HttpComponent')
    http_component:send_string_frame(msg.sid, msg.data)
end



