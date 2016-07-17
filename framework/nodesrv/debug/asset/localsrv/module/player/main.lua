module('Player', package.seeall)


function reply(player, msg)
    POST(player.srvid, 'Player.REPLY', player.uid, msg)
end

