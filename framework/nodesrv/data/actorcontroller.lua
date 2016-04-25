module('ActorController', package.seeall)
--[[
脚本组件

--]]

function awake(self)
    print('ActorController awake')
    --可以在这里设置成员的值
    self.xxx = 333
end

function update(self, tick)
--    print('ActorController update', self.xxx)
end



