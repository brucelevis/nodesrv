

require('localsrv/component/telnetsrv')
require('localsrv/object/mainobject')
require('localsrv/module/admin/main')
require('localsrv/module/login/main')
require('localsrv/module/player/main')

function main()
    mynode:create_gameobject_local('MainObject')
end


