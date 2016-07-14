
require('gatesrv/entity/gatesrv')
require('lib/http2')

import('gatesrv/component/websocket', true, 'WebSocket')
import('gatesrv/module/login')
import('gatesrv/module/player')
import('gatesrv/web/account')
import('gatesrv/web/admin')

mysrv:create_entity_local('GateSrvEntity')

--Login.main()
