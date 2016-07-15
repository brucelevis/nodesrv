
require('gatesrv/entity/gatesrv')
require('gatesrv/web/cms/account/main')
require('lib/http2')
require('gatesrv/component/websocket/websocket')
require('gatesrv/module/login/login')
require('gatesrv/module/player/main')
require('gatesrv/web/account/main')
require('gatesrv/web/admin/main')

Config.httpsrv.template_dir = string.format('%s/script/gatesrv/web/', Config.asset_dir)
Config.httpsrv.static_dir = string.format('%s/script/gatesrv/static/', Config.asset_dir)

mysrv:create_entity_local('GateSrvEntity')

--Login.main()
