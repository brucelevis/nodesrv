module('Player', package.seeall)

function connect(player)
    if not player.http_client then
        local http_client = HttpClient:new()
        player.http_client = http_client
        http_client:connect(Config.test.host, Config.test.port)
        http_client:send_open_websock()
        http_client:recv()
    end
end

function send(player, msgname, params)
    params = params or {}
    local msg = Pblua.msgnew(msgname)
    for k, v in pairs(params) do
        msg[k] = v
    end
    local http_client = player.http_client
    if not http_client then
        logerr('not connect')
        return
    end
    local buffer = Buffer:new_local()
    buffer:write_utf8(msg:msgname())
    buffer:write_protobuf(msg)
    http_client:send_binary_frame(buffer)
    loginfo('send msg(%s) success', msg:msgname())
end

--接收消息
function recv(player, expect_msgname)
    if not player.http_client then
        logerr('not connect')
        return
    end
    local http_client = player.http_client
    if not http_client:recv_frame() then
        logerr('recv err')
        return
    end
    local buffer = http_client.buffer
    while true do
        local msgname = buffer:read_utf8()
        local msg = buffer:read_protobuf(msgname, buffer:size())
        if expect_msgname == msgname then
            print('recv a msg', msgname)
            print(msg:debug_string())
            return msg
        end
    end
end
