module('Admin', package.seeall)

function help()
    return [[

reload  热更新
help    显示此帮助

    ]]
end

--热更新
function reload(srvname)
    if not srvname then
        --热更新全部
        for _, srvconf in pairs(Config.srvlist) do
            if NodeMgr:find_node(srvconf.nodeid) then
                POST(_G[srvconf.srvname], 'Admin.RELOAD')
            end
        end
        return
    end

    local srvid = _G[srvname]
    local srvconf = nil
    for _, _srvconf in pairs(Config.srvlist) do
        if _srvconf.srvname == srvname then
            srvconf = _srvconf
            break
        end
    end
    if not srvconf then
        return string.format('%s not found', srvname)
    end
    if NodeMgr:find_node(srvconf.nodeid) then
        POST(_G[srvname], 'Admin.RELOAD')
    else
        return string.format('%s not found', srvname)
    end
end

--热更新
function RELOAD()
    local node_conf = Config.srvlist[Config.nodeid]
    require(node_conf.mainfile)
end



