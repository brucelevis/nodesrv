module('Admin', package.seeall)

function RELOAD(sockfd, msgname)
    for k, argv in pairs(Config.srvconf.srvdef) do
        local mod = reimport(argv[1])
    end
    REPLY(sockfd, 'OK')
end
