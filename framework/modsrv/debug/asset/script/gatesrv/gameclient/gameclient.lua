module('Gameclient', package.seeall)

portfd = portfd or nil
socket_table = socket_table or {
    --[sockfd] = {srvid = 0, srvname =''. host = '', port = 33}
}

function main()
    portfd = RMIPort.create(Ae.main_loop())
    Port.rename(portfd, 'Gamesrv')
    Port.on_close(portfd, 'Gameclient.ev_close')
    Port.on_connect_err(portfd, 'Gameclient.ev_connect_err')
    Port.on_connect_suc(portfd, 'Gameclient.ev_connect_suc')
    check_connections()
end

function ev_connect_err(sockfd, host, port)
    loginfo('ev_connect_err sockfd(%d)', sockfd)
    socket_table[sockfd] = nil
    check_connections()
end

function update()

end

--功能：随机选择一个
function randselect(srvid)
    for k, v in pairs(socket_table) do
        return v
    end
end

function ev_connect_suc(sockfd, host, port)
    loginfo('ev_connect_suc sockfd(%d)', sockfd)
    local game = socket_table[sockfd]
    POST(sockfd, 'Gatesrv.REGIST', Config.srvid, Config.srvname)
end

function ev_close(sockfd, host, port, reason)
    loginfo('ev_close sockfd(%d) reason(%s)', sockfd, reason)
    socket_table[sockfd] = nil
    check_connections();
end

--重连
function check_connections()
    local gamesrv_list = argv.gamesrv_list
    for sockfd, info in pairs(socket_table) do
        local find = false
        for index, conf in pairs(gamesrv_list) do
            if conf.host == info.host and conf.port == info.port then
                find = true
                break
            end
        end
        if not find then
            loginfo('config changed!!')
            Socket.close(sockfd, 'config changed')
        end
    end
    for index, conf in pairs(gamesrv_list) do
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
                socket_table[sockfd] = {sockfd = sockfd, srvid = conf.srvid, host = conf.host, port = conf.port}
            end
        end
    end
end
