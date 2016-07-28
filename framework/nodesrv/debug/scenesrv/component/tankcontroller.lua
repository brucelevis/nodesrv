
module('TankController', package.seeall)

local gameobject = gameobject or nil

function awake(self)
    gameobject = self.gameobject
end

function update(self, delta)
    --print(delta)
    --local transform = gameobject.transform
    --local position = transform.position
    --position.x = position.x + 1
    --print(position.x)
end
