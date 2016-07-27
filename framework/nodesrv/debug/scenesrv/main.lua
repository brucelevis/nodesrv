
require('scenesrv/object/root')
require('scenesrv/object/tank')
require('scenesrv/module/login')
require('scenesrv/module/player/player')
require('scenesrv/module/user/user')
require('scenesrv/component/tankcontroller')

function main()
    local root = mynode:create_gameobject_local('RootGameObject')
    mynode:create_gameobject_local('TankGameObject')
    root:obj_dump()
end

