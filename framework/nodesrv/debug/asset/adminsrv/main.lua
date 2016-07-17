
require('adminsrv/entity/entity')
require('lib/http2')
require('lib/mydb')
require('adminsrv/component/websocket')
require('adminsrv/web/account/main')
require('adminsrv/web/admin/main')
require('adminsrv/web/admin/server/main')
require('adminsrv/web/cms/account/main')
require('adminsrv/web/cms/default/main')
require('adminsrv/web/cms/default/model')

Config.httpsrv.template_dir = string.format('%s/script/adminsrv/web/', Config.asset_dir)
Config.httpsrv.static_dir = string.format('%s/script/adminsrv/static/', Config.asset_dir)

function main()
    mydb.connect(Config.mydbconf)
    --local r = mydb.test:select('select * from user')
    --print(Json.encode(r))
    mysrv:create_entity_local('MainEntity')
end

