

require('localsrv/component/telnetsrv')
require('localsrv/entity/mainentity')
require('localsrv/module/admin/main')
require('localsrv/module/hall/main')
require('localsrv/module/login/main')
require('localsrv/module/player/main')

mysrv:create_entity_local('MainEntity')

--for k, v in pairs(package.loaded) do
    --print(k, v)
--end

--DbSrv.main()
Login.main()
