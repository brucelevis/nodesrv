module('Player', package.seeall)

function reply(player, msg)
    POST(player.gatesrv, 'Player.REPLY', player.uid, msg)
end



