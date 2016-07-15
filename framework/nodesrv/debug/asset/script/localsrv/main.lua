

require('localsrv/entity/localsrv')
require('localsrv/module/hall/main')
require('localsrv/module/login/main')
require('localsrv/module/player/main')

mysrv:create_entity_local('LocalSrvEntity')

--for k, v in pairs(package.loaded) do
    --print(k, v)
--end

--DbSrv.main()

Login.main()
