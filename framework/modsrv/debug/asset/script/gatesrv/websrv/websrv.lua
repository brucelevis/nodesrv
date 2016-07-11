module('Websrv', package.seeall)

portfd = nil

socket_manager = socket_manager or {}
tmp_socket_manager = tmp_socket_manager or {}

function main()
    portfd = WebSockPort.create(Ae.main_loop())
    listen()
end

function ev_read(sockfd, msgname, msg)
    loginfo('dispatch msgname(%s)', msgname)
    local pats = string.split(msgname, '.')
    local mod_name = pats[1]
    local func_name = pats[2]
    local timenow = os.time()
    local player = socket_manager[sockfd]
    --防止刷包
    if player then
        player.packet_counter = player.packet_counter + 1
        if player.packet_counter > argv.packet_count_threshold then
            if timenow - player.last_check_packet_time < argv.packet_time_threshold then
                logwarn('packet hack')
                local msg = pbc.msgnew('login.DISCONNECT')
                msg.errno = 14
                reply(player.sockfd,  msg)
                disconnect(player.sockfd, 'packet hack')
                return
            end
            player.last_check_packet_time = timenow
            player.packet_counter = 0
        end
    end
    --1.分发消息
    local mod = _G[string.cap(mod_name)]
    if mod then
        local func = mod['MSG_'..func_name]
        if func then
            func(player or sockfd, msg)
            return
        end
    end
    local route = argv.route[mod_name]
    route = route or argv.route[msgname]
    --2.分发消息到gamesrv
    if player and player.srvid and not route then
        Gameclient.forward(player, msg)
        return
    end
    --3.分发消息到globalsrv
    if route then
        --末认证
        if route.need_auth and not player then
            logerr('not auth')
            return
        end
        local uid = player and player.uid or 0
        POST(route.srvid, 'Gatesrv.FORWARD', uid, msg)
        return
    end
end

function close(sockfd, reason) 
    Port.close(portfd, sockfd, reason);
end

function ev_close(sockfd, host, port, reason)
    loginfo('ev_close sockfd(%d)', sockfd)
    local player = socket_manager[sockfd]
    if player then
        loginfo('client close from uid(%d) ip(%s) reason(%s)', player.uid, host, reason)
        --保存数据 
        Login.player_disconnect(player)
        player.sockfd = nil
        socket_manager[sockfd] = nil
        return
    end
    if tmp_socket_manager[sockfd] then
        tmp_socket_manager[sockfd] = nil
    end
end

function ev_accept(sockfd, host, port)
    loginfo('accept a client sockfd(%d) host(%s) port(%d)', sockfd, host, port)
    tmp_socket_manager[sockfd] = {time = os.time()}
end

function listen()
    loginfo('listen on host(%s) port(%d)', argv.host, argv.port)
    Port.rename(portfd, "Websrv")
    if not Port.listen(portfd, argv.port) then
        error('listen fail')
    end
    Port.on_accept(portfd, 'Websrv.ev_accept')
    Port.on_close(portfd, 'Websrv.ev_close')
    Port.on_read(portfd, 'Websrv.ev_read')
end

function update()
    --timer_check()
end

--功能:定时检测链接上来后, 没有发消息登陆的socket
function timer_check()
    local timenow = os.time()
    for sockfd, v in pairs(tmp_socket_manager) do
        local timebefore = v.time
        if timenow - timebefore > argv.tmp_sock_idle_sec then
            --太久没有验证成功的socket, 要关闭了
            Port.close(portfd, sockfd, 'tmp to long')
            loginfo('tmp to long ip(%s)', Port.getpeerip(sockfd))
        end
    end
    return 1
end

function reply(sockfd, msg)
    WebSockPort.post(sockfd, msg)
end
