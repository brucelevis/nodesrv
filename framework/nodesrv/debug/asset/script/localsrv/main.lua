

require('localsrv/entity/localsrv')

import('Hall', 'localsrv/module/hall')
import('Login', 'localsrv/module/login')
import('Player', 'localsrv/module/player')

mysrv:create_entity_local('LocalSrvEntity')

--for k, v in pairs(package.loaded) do
    --print(k, v)
--end

--DbSrv.main()

Login.main()
