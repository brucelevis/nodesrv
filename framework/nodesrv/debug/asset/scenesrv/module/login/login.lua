module('Login', package.seeall)


function PLAYER_ENTER(msg, uid)
    print('hello rpc', uid)
    print(msg.header.id)
end


