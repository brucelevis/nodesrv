

require('dbsrv/entity/dbsrv')

import('dbsrv/module/dbsrv', true, 'DbSrv')

--require('dbsrv/module/dbsrv/dbsrv')
--require('dbsrv/module/dbsrv/mysql_conn')
--require('dbsrv/module/dbsrv/redis_conn')

mysrv:create_entity_local('DbSrvEntity')

--for k, v in pairs(package.loaded) do
    --print(k, v)
--end

DbSrv.main()


