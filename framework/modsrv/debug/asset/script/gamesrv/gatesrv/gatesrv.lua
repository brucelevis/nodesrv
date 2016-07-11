module('Gatesrv', package.seeall)

portfd = port or nil

gate_manager = gate_manager or {
    --[srvid] = {srvid = srvid, srvname = srvname, sockfd, time}
}

function main()
    portfd = RMIPort.create(Ae.main_loop())
    listen()
end

function reply(sockfd, uid, msg)
    POST(sockfd, 'Login.REPLY', uid, msg)
end

function ev_close(sockfd, reason)
    loginfo('ev_close sockfd(%d) reason(%s)', sockfd, reason)
    for _, gate in pairs(gate_manager) do
        if gate.sockfd == sockfd then
            gate_manager[gate.srvid] = nil
            loginfo('gate disconnect srvname(%s)', gate.srvname)
            break
        end
    end
end

function ev_read(sockfd, uid, msgname, msg)
    loginfo('ev_read uid(%d) msgname(%s)', uid, msgname)
    local player = Login.player_manager[uid]
    if player then
        local pats = string.split(msgname, '.')
        local modname = pats[1]
        local msgname = pats[2]
        local mod = _G[string.cap(modname)]
        if not mod then
            logwarn('mod(%s) not found', modname)
            return
        end
        local func = mod['MSG_'..msgname]
        if not func then
            logwarn('func(%s) not found', msgname)
            return
        end
        func(player, msg)
    end
end

function ev_accept(sockfd)
    loginfo('accept a gate sockfd(%d)', sockfd)
end

function listen()
    loginfo('listen on host(%s) port(%d)', argv.host, argv.port)
    Port.rename(portfd, "Gatesrv")
    if not Port.listen(portfd, argv.port) then
        error('listen fail')
    end
    Port.on_read(portfd, 'Gatesrv.ev_read')
    Port.on_accept(portfd, 'Gatesrv.ev_accept')
    Port.on_close(portfd, 'Gatesrv.ev_close')
end

--功能:game_srv上线
--@srvname 服务名称
function REGIST(sockfd, srvid, srvname)
    if gate_manager[srvid] ~= nil then
        logerr('game(%s) is connected yet', srvid)
        return 
    end
    local srv = {
        srvname = srvname,
        sockfd = sockfd,
        srvid = srvid,
        time = os.time()
    }
    gate_manager[srvid] = srv 
    loginfo('a gate regist srvname(%s)', srvname)
end

