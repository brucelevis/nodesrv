
require('gatesrv/entity/gatesrv')
require('lib/http2')
require('lib/mydb')
require('gatesrv/component/websocket/websocket')
require('gatesrv/module/login/login')
require('gatesrv/module/player/main')
require('gatesrv/web/account/main')
require('gatesrv/web/admin/main')
require('gatesrv/web/admin/server/main')
require('gatesrv/web/cms/account/main')
require('gatesrv/web/cms/default/main')
require('gatesrv/web/cms/default/model')

Config.httpsrv.template_dir = string.format('%s/script/gatesrv/web/', Config.asset_dir)
Config.httpsrv.static_dir = string.format('%s/script/gatesrv/static/', Config.asset_dir)

mydb.connect(Config.mydbconf)

mysrv:create_entity_local('GateSrvEntity')

--Login.main()
