module('Login', package.seeall)

function login(player)
    Player.connect(player)
    Player.send(player, 'login.LOGIN', {uid = player.uid, params = '3333'})
    local reply = Player.recv(player, 'login.LOGIN')

    --Player.send(player, 'login.LOGIN', {uid = player.uid, params = '3333'})
    --local reply = Player.recv(player, 'login.LOGIN')
    Player.send(player, 'login.ENTER', {})
    local reply = Player.recv(player, 'login.ENTER')
    --Player.send(player, 'login.ENTER', {})
    --local reply = Player.recv(player, 'login.ENTER')
end

function ping(player)
    login(player)
    Player.send(player, 'login.PING', {})
    Player.recv(player, 'login.PING')
end

