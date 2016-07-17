

require('dbsrv/entity/dbsrv')
require('dbsrv/module/dbsrv/dbsrv')
require('dbsrv/module/dbsrv/mysql_conn')
require('dbsrv/module/dbsrv/redis_conn')

function main()
    mysrv:create_entity_local('DbSrvEntity')
    DbSrv.main()
end


