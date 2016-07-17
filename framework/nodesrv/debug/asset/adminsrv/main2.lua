
--[[

POST(adminsrv, 'AdminSrv.REPLY', 'hello world')

--]]

require('adminsrv/entity/entity')

mysrv:create_entity_local('MainEntity')
--Log.closealllevel()


module('AdminSrv', package.seeall)

function read_command()
    io.write('>')
    local command = io.read()
    POST(localsrv, command, 'hello')
end

function REPLY(srvid, str)
    print(str)
    read_command()
end


read_command()
--POST(localsrv, 'Admin.RELOAD', 'hello')
