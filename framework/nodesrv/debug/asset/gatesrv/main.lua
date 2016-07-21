
require('gatesrv/object/root')
--require('gatesrv/component/websocket')
require('gatesrv/component/client')
require('gatesrv/module/login')
require('gatesrv/module/player')

function main()
    mynode:create_gameobject_local('RootObject')
end


