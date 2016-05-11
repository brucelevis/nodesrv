
print('==========nodesrv=================')
print('author:LJW')
print('date:2016.04.08')
print('nodeid:333333333')
print('==========nodesrv=================')
print('')

require('data/lib')
require('data/node2/actor2')
require('data/node2/sendcreateentity')

print('create entity local', Node.create_entity_local(nodesrv, 'Actor2Prefab'))
--print('connect', Node.connect(nodesrv, '127.0.0.1', 9090))
