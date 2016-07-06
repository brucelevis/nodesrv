module('Gamesrv', package.seeall)

portfd = nil

game_manager = game_manager or {
    --[srvid] = {srvid, srvname, time}
}

function test_hello(timerid)
    loginfo('hello')
    loginfo(timerid)
    return 1
end

function main(arg)
    portfd = RMIPort.create(Ae.main_loop())
    listen()
    --local timerid = Timer.addtimer(Ae.main_loop(), 1000, 'Gamesrv.test_hello')
    --print(timerid)
end

function ev_close(sockfd, host, port, reason)
    loginfo('ev_close sockfd(%d) reason(%s)', sockfd, reason)
    for srvid, game in pairs(game_manager) do
        if game.sockfd == sockfd then
            game_manager[srvid] = nil
            loginfo('game disconnect srvname(%s)', game.srvname)
            break
        end
    end
end

function ev_accept(sockfd)
    loginfo('accept a game sockfd(%d)', sockfd)
end

function listen()
    loginfo('listen on host(%s) port(%d)', argv.host, argv.port)
    Port.rename(portfd, "GameSrv")
    if not Port.listen(portfd, argv.port) then
        error('listen fail')
    end
    Port.on_accept(portfd, 'Gamesrv.ev_accept')
    Port.on_close(portfd, 'Gamesrv.ev_close')
    Port.on_read(portfd, 'Gamesrv.ev_read')
end

--功能:game_srv上线
--@srvname 服务名称
function REGIST(sockfd, srvid, srvname)
    if game_manager[srvid] ~= nil then
        logerr('%s is connected yet', srvname)
        return 
    end
    local srv = {
        srvid = srvid,
        srvname = srvname,
        time = os.time(),
        sockfd = sockfd, 
    }
    game_manager[srvid] = srv 
    loginfo('a game regist srvname(%s)', srvname)
end


