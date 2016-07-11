module('Test', package.seeall)

local portfd = nil
local loop = nil

function connect(player)
    if not loop then
        loop = Ae.create(10240)
    end
    if not portfd then
        portfd = Port.create(loop)
        Port.rename(portfd, 'Test')
        Port.on_close(portfd, 'Test.ev_close')
        Port.on_read(portfd, 'Test.ev_read')
    end
end

function ev_read(sockfd, reason)
end

function ev_close(sockfd, host, port, reason)
    log('ev_close')
end

function send(player, msgname, params)
    params = params or {}
    local msg = Pblua.msgnew(msgname)
    for k, v in pairs(params) do
        msg[k] = v
    end
    local sockfd = player.sockfd
    if not sockfd then
        sockfd = Port.syncconnect(portfd, PbClientConf.host, PbClientConf.port)
        if not sockfd or sockfd == 0 then
            logerr('connect fail')
            os.exit(1)
        end
        if sockfd < 0 then
            log('connect fail')
            os.exit(1)
        end
        player.sockfd = sockfd
        WebSockPort.send_open_websock(sockfd, 10)
        WebSockPort.recv_open_websock(sockfd, 10)
    end
    WebSockPort.send(sockfd, msg, 10)
    loginfo('send msg(%s) success', msg:msgname())
end

--接收消息
function recv(player, msgname)
    for i = 1, 10 do
        Ae.run_once(loop)
        local msg = WebSockPort.recv(player.sockfd, 10)
        if msg then
            local msgname = msg:msgname()
            loginfo(string.format('recv msg name(%s)', msg:msgname())) 
            if msg:msgname() == msgname then
                return msg
            end
        end
    end
end
