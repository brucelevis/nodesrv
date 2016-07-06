module('Globalclient', package.seeall)

portfd = nil
socket_table = socket_table or {}

function main()
    portfd = RMIPort.create(Ae.main_loop())
    Port.rename(portfd, "Globalsrv")
    Port.on_close(portfd, 'Globalclient.ev_close')
    Port.on_connect_err(portfd, 'Globalclient.ev_connect_err')
    Port.on_connect_suc(portfd, 'Globalclient.ev_connect_suc')
    check_connections()
end

function ev_connect_err(sockfd, host, port)
    socket_table[sockfd] = nil
    check_connections()
end

function ev_connect_suc(sockfd, host, port)
    loginfo('ev_connect_suc sockfd(%d)', sockfd)
    local srvid = nil
    local globalsrv_list = argv.globalsrv_list
    for index, conf in pairs(globalsrv_list) do
        if conf.host == host and port == conf.port then
            srvid = conf.srvid
            if conf.alias then
                _G[conf.alias] = sockfd
                loginfo('alias srvid(%d) to sockname(%s)', srvid, conf.alias)
            end
            break
        end
    end
    POST(sockfd, 'Gamesrv.REGIST', Config.srvid, Config.srvname)
    --POST(srvid, 'Gamesrv.REGIST', Config.srvconf.srvname)
    --POST(sockfd, 'Dbsrv.GET', 333, 'Globalclient.test_db_get', 'user')
end

function test_db_set(srvid, uid, result)
    loginfo('test_db_set result(%d)', result)
end

function test_db_get(sockfd, uid, result, msg)
    --loginfo(msg)
    loginfo('uid(%d) result(%d)', uid, result)
    loginfo('debug_string(%s)', msg:debug_string())
    POST(sockfd, 'Dbsrv.SET', 333, 'Globalclient.test_db_set', 'user', msg) 
end

function ev_close(sockfd, host, port, reason)
    loginfo('ev_close sockfd(%d) reason(%s)', sockfd, reason)
    for _, conf in pairs(argv.globalsrv_list) do
        if conf.host == host and conf.port == port then
            if conf.alias then
                _G[conf.alias] = nil
                loginfo('del srvid(%d) to alias(%s)', srvid, conf.alias)
            end
            break
        end
    end
    socket_table[sockfd] = nil
    check_connections()
end

--重连
function check_connections()
    local globalsrv_list = argv.globalsrv_list
    for sockfd, info in pairs(socket_table) do
        local find = false
        for index, conf in pairs(globalsrv_list) do
            if conf.host == info.host and conf.port == info.port then
                find = true
                break
            end
        end
        if not find then
            loginfo('config changed!!')
            Port.close(portfd, sockfd, 'config changed')
        end
    end
    for index, conf in pairs(globalsrv_list) do
        local find = false
        for sockfd, info in pairs(socket_table) do
            if conf.host == info.host and conf.port == info.port then
                find = true
                break
            end
        end
        if not find then
            local sockfd = Port.connect(portfd, conf.host, conf.port)
            loginfo('to connect sockfd(%d) host(%s) port(%d)', sockfd, conf.host, conf.port)
            if sockfd then
                socket_table[sockfd] = {sockfd = sockfd, host = conf.host, port = conf.port}
            end
        end
    end
end
