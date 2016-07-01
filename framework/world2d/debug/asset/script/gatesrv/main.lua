require('config')
require('deploy')

package.path = string.format('%s;%s/?.lua', package.path, DeployConf.asset_dir)
require('lualib/lib')
require('script/gatesrv/entity/gatesrv')

mynode:create_entity_local('GateSrvEntity')

