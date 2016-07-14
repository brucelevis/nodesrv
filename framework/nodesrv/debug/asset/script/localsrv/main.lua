

require('localsrv/entity/localsrv')

import('localsrv/module/hall')
import('localsrv/module/login')
import('localsrv/module/player')

mysrv:create_entity_local('LocalSrvEntity')

--for k, v in pairs(package.loaded) do
    --print(k, v)
--end

--DbSrv.main()

Login.main()
