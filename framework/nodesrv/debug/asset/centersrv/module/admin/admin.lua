module('Admin', package.seeall)

function reload(srvid)
    print('asfaf', srvid)
    RELOAD(srvid)
end

function RELOAD(srvid)
    local node_conf = Config.srvlist[Config.nodeid]
    require(node_conf.mainfile)
end
