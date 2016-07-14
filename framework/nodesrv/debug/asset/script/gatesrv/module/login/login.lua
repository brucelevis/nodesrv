module('Login', package.seeall)

player_session = player_session or {
    --[sid] = player
}
player_manager = player_manager or {}

function main()
    local msg = Pblua.msgnew('login.LOGIN')
    msg.uid = 333
    MSG_LOGIN(1, msg)
end

--功能：进入游戏服
function MSG_ENTER(sid, msg)
    local player = player_session[sid]
    if not player then
        logerr('player not found')
        return
    end
end

--功能：进入游戏服,切换服务器
function PLAYER_ENTER(_, uid, srvid)
    local player = player_manager[uid]
    if not player then
        logerr('player is offline uid(%d)', uid)
        return
    end
    player.srvid = srvid
end

--功能:登陆
function MSG_LOGIN(sid, msg)
    local uid = msg.uid
    if uid == nil or uid <= 0 then
        logerr('uid is error')
        msg.errno = 8
        return
    end
    --验证
    if not check_login_token(uid, msg.params) then
        logerr('token is error')
        msg.errno = 10
        return
    end
    --加锁
    local player = {
        sid = sid;
        uid = uid,
        packet_counter = 0,
        last_check_packet_time = 0,
    }
    player_session[sid] = player
    player_manager[uid] = player
    POST(localsrv, 'Login.PLAYER_LOGIN', player.uid)
end

--功能：下线
function player_disconnect(sid)
    local player = player_session[sid]
    if not player then
        logerr('player not found sid(%d)', sid)
        return
    end
    player_manager[player.uid] = nil
    POST(localsrv, 'Login.PLAYER_LOGOUT', player.uid)
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
end
