module('Player', package.seeall)

function connect(player)
    if not player.sockfd then
        local sockfd = Socket.socket(Socket.AF_INET, Socket.SOCK_STREAM, 0)
        if sockfd < 0 then
            logerr('socket err')
            os.exit(0)
        end
        player.sockfd  = sockfd 
        if not Socket.connect(player.sockfd, Config.test.host, Config.test.port) then
            logerr('connect err')
            os.exit(0)
        end
    end
end

function send(player, msgname, params)
    params = params or {}
    local msg = Pblua.msgnew(msgname)
    for k, v in pairs(params) do
        msg[k] = v
    end
    local sockfd = player.sockfd
    if not sockfd then
        logerr('not connect')
        return
    end
    Client:send(sockfd, msg, 10)
end

--接收消息
function recv(player, expect_msgname)
    if not player.sockfd then
        logerr('not connect')
        return
    end
    local sockfd = player.sockfd

    while true do
        local msg = Client:recv(sockfd, 10) 
        local msgname = msg:msgname()
        if expect_msgname == msgname then
            return msg
        end
    end
end
