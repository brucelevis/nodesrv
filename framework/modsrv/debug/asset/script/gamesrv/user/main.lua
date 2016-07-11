module('User', package.seeall)

function MSG_GETDATA(player, msg)
    local playerdata = player.playerdata

    local reply = Pblua.msgnew('user.GETDATA')
    reply.diamond = playerdata.diamond
    reply.coin = playerdata.coin
    reply.headimg = playerdata.headimg
    reply.username = playerdata.username

    Player.reply(player, reply)
end

