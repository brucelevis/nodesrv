
require('gatesrv/entity/mainentity')
require('gatesrv/component/websocket/websocket')
require('gatesrv/module/login/main')
require('gatesrv/module/player/main')

function main()
    mysrv:create_entity_local('MainEntity')
end

