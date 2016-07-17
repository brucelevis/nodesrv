module('Admin', package.seeall)

function test()
    return 'affafafaf'
end

function RELOAD(srvid)
    local node_conf = Config.srvlist[Config.nodeid]
    require(node_conf.mainfile)
end
