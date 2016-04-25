
package.path = package.path..';'..'../../framework/nodesrv/?.lua'
require('data/lib')
require('entity/gatesrv')

Node.create_entity_local(nodesrv, 'GateSrvEntity')
