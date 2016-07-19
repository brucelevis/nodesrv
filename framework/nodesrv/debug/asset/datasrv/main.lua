

require('datasrv/object/root')
require('datasrv/module/dbsrv/dbsrv')
require('datasrv/module/dbsrv/mysql_conn')
require('datasrv/module/dbsrv/redis_conn')

function main()
    mynode:create_gameobject_local('RootObject')
    DbSrv.main()
end


