

require('datasrv/object/root')
require('datasrv/module/dbsrv/dbsrv')
require('datasrv/module/dbsrv/mysql_conn')
require('datasrv/module/dbsrv/redis_conn')

function main()
    mysrv:create_entity_local('RootObject')
    DbSrv.main()
end


