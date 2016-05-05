
print('==========nodesrv=================')
print('author:LJW')
print('date:2016.04.08')
print('nodeid:333333333')
print('==========nodesrv=================')
print('')

require('data/lib')
require('data/node1/actor1')
require('data/actorcontroller')

local entity = Node.create_entity_local(nodesrv, 'Actor1Prefab')
local net_component = Entity.get_component(entity, 'NetComponent')
NetComponent.listen(net_component, '0.0.0.0', 6666)

--print('listen', Node.listen(nodesrv, '127.0.0.1', 9090))
