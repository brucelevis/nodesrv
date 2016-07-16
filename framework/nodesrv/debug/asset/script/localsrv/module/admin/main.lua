module('Admin', package.seeall)

function test()
    return 'affafafaf'
end

function reply(str)
    POST(adminsrv, 'AdminSrv.REPLY', str)
end

function RELOAD(srvid)
    print('realod')
    print('realod')
    print('realod')
    print('realod')
    print('realod')
    print('realod')
    reply('ok')
end
