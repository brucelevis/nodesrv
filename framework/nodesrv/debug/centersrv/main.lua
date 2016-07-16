

require('centersrv/component/telnetsrv')
require('centersrv/object/root')
require('centersrv/object/telnet')
require('centersrv/module/login/login')
require('centersrv/module/player/player')

require('common/module/admin')

function main()
    mynode:create_gameobject_local('RootObject')
    mynode:create_gameobject_local('TelnetObject')
end


