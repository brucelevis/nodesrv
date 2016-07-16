
require('gatesrv/object/root')
--require('gatesrv/component/websocket')
require('gatesrv/component/client')
require('gatesrv/module/login')
require('gatesrv/module/player')

function main()
    local obj = mynode:create_gameobject_local('RootObject')
    obj:obj_dump()
end


