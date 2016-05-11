module('SendCreateEntity', package.seeall)

function awake(self)
    print('ActorController awake')
    --可以在这里设置成员的值
    self.xxx = 333
    self.entity = Component.get_entity(self)
end

function update(self, tick)
    NodeMgr.send_create_entity(self.entity, 1, 'Actor1Prefab')
end

