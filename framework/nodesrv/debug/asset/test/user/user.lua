module('User', package.seeall)

function getuserdata(player)
    Login.login(player)
    Player.send(player, 'user.GET_USER_DATA')
    local reply = Player.recv(player, 'user.GET_USER_DATA')
end


