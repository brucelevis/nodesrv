
require('gatesrv/object/rootobject')
require('gatesrv/component/websocket')
require('gatesrv/module/login')
require('gatesrv/module/player')

function main()
    mysrv:create_entity_local('RootObject')
end

