module('Login', package.seeall)

player_manager = player_manager or {}

function main()
end

function REPLY(sockfd, uid, msg)
    local player = player_manager[uid]
    if not player then
        logerr('player not found uid(%d)', uid)
        return
    end
    Websrv.reply(player.sockfd, msg)
end

--功能：进入游戏服
function MSG_ENTER(player, msg)
    local srvid = msg.srvid
    local gamesrv = nil
    if srvid == 0 then
        gamesrv = Gameclient.randselect() 
    end
    if not gamesrv then
        logerr('game_srv not found')
        msg.errno = 11
        Websrv.reply(player.sockfd, msg)
        return
    end
    player.srvid = gamesrv.srvid
    player.servname = gamesrv.srvname
    player.gamesrvsockfd = gamesrv.sockfd
    POST(player.gamesrvsockfd, 'Login.PLAYER_ENTER', player.uid)
end

--功能：进入游戏服,切换服务器
function PLAYER_ENTER(srvid, uid, srvid)
    local player = player_manager[uid]
    if not player then
        logerr('player is offline uid(%d)', uid)
        return
    end
    player.srvid = srvid
    POST(srvid, 'Login.PLAYER_ENTER', player.uid)
end

--功能:登陆
function MSG_LOGIN(sockfd, msg)
    local uid = msg.uid
    if uid == nil or uid <= 0 then
        msg.errno = 8
        Websrv.reply(sockfd, msg)
        Websrv.close(sockfd, 'uid is wrong')
        return
    end
    --验证
    if not check_login_token(uid, msg.params) then
        msg.errno = 10
        Websrv.reply(sockfd, msg)
        Websrv.close(sockfd, 'auth fail')
        return
    end
    --加锁
    local player = {
        sockfd = sockfd, 
        uid = uid,
        packet_counter = 0,
        last_check_packet_time = 0,
    }
    player_manager[uid] = player
    Websrv.socket_manager[sockfd] = player
    Websrv.tmp_socket_manager[sockfd] = nil
    msg.errno = 0
    Websrv.reply(sockfd, msg)
    return true 
end

--功能：下线
function player_disconnect(player)
    local srvid = player.srvid
    if not srvid then
        logerr('user is not in gamesrv uid(%d)', player.uid)
        return
    end
    POST(player.gamesrvsockfd, 'Login.PLAYER_EXIT', player.uid)
end


function check_login_token(uid, params)
    if not Config.auth then
        return true
    end
    local kv = {}
    local params = string.split(params, '&')
    for _, param in pairs(params) do
        local pats = string.split(param, '=')
        kv[pats[1]] = os.urldecode(pats[2])
    end
    local time = tonumber(kv.time)
    if Config.sign_expire_sec ~= 0 and os.time() - time / 1000 >= Config.sign_expire_sec then
        logger:error(string.format('user(%d) sign time expire, recv(%d) now(%d)', uid, time, os.time()))
        return false
    end
    local kset = {}
    for k, v in pairs(kv) do
        table.insert(kset, k)
    end
    table.sort(kset)
    local str = ''
    for _, k in pairs(kset) do
        if k ~= 'sig' then
            str = str..k..'='..kv[k]
        end
    end
    str = str..Config.srv_secret
    local token = os.md5(str)
    if token ~= kv.sig or uid ~= tonumber(kv.uid) then
        logger:error(string.format('user(%d) auth fail sign(%s) time(%s) uid(%d) token(%s)', uid, kv.sig, kv.time, kv.uid, token))
        return false
    end
    return true
end

function MSG_PING(player, msg)
    log('hello')
    Websrv.reply(player.sockfd, msg)
end
