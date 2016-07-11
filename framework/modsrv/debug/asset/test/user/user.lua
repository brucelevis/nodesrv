module('User', package.seeall)

function getdata(player)
    Login.login(player)
    Test.send(player, 'user.GETDATA')
    Test.recv(player, 'user.GETDATA')
end


