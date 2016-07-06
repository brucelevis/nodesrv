module('Player', package.seeall)


function reset(player)

end

function init(player)
    loginfo('player init')
end

function close(player)
    loginfo('player close')
end

function reply(player, msg)
    Gatesrv.reply(player.sockfd, player.uid, msg)
end


