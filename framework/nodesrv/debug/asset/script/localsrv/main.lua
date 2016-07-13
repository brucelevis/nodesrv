

require('localsrv/entity/localsrv')

import('Hall', 'localsrv/module/hall')
import('Login', 'localsrv/module/login')
import('Player', 'localsrv/module/player')

mysrv:create_entity_local('LocalSrvEntity')

local msg = Pblua.msgnew('dbproto.UserData')
msg.uid = 333
POST(3, 'DbSrv.TEST', 'Login.TEST', 11, 22, 33, msg, {11, 22})

--for k, v in pairs(package.loaded) do
    --print(k, v)
--end

--DbSrv.main()
