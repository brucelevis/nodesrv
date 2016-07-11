
--数据库
centersrv_def = {
    {'asyncsrv'},
    {'pblua'},
    {'globalsrv/gamesrv',
        host = '0.0.0.0', port = 1234
    },
    {'centersrv/login'},
    {'centersrv/admin'},
    {'centersrv/adminsrv', 
        host = '0.0.0.0', port = 3336 
    },
}

--数据库
dbsrv_def = {
    {'asyncsrv'},
    {'pblua'},
    {'globalsrv/gamesrv',
        host = '0.0.0.0', port = 1234
    },
    {'dbsrv/dbsrv',
        host = '0.0.0.0', port = 1234,
        expire_sec = 100,
        delay_write = false,
        dbproto = 'dbproto',
        redis_conf = {
            {dbname = '1', host = '127.0.0.1', port = 6379, password = ''},
        },
        mysql_conf = {
            {dbname = 'test', host = '127.0.0.1', user = 'root', port = 3306, password = '0987abc123'},
        },
        --结构表和对象的映射
        table_conf = {
            user = {class = 'dbproto.UserData'},
            task = {class = 'dbproto.TaskData', binary = true},
            achieve = {class = 'dbproto.AchieveData', binary = true},
        },
    },
}

--网关配置
gatesrv_def = {
    {'asyncsrv'},
    {'pblua'},
    {'gatesrv/websrv',
        host = '0.0.0.0', port = 1234,
        tmp_sock_idle_sec = 10,
        packet_count_threshold = 10,
        packet_time_threshold = 10,
        check_interval = 120,
        maxsock = 65536,
        route = {},
    },
    --{'gatesrv/clientsrv',

        --host = '0.0.0.0', port = 1234,
        --tmp_sock_idle_sec = 10,
        --packet_count_threshold = 10,
        --packet_time_threshold = 10,
        --check_interval = 120,
        --maxsock = 65536,
        --route = {},
    --},
    {'gatesrv/login'},
    {'gatesrv/gameclient',
        gamesrv_list = {
            {srvid = 101, host = '127.0.0.1', port = 3332},
        },
    },
}

gamesrv_def = {
    {'asyncsrv'},
    {'pblua'},
    {'gamesrv/gatesrv',
        host = '0.0.0.0', port = 1234,
    },
    {'gamesrv/login',
        save_interval = 3600,
        playerdata = {'user', 'task', 'achieve', },
    },
        {'gamesrv/player',},
    {'gamesrv/globalclient',
        check_connect_interval = 1000,
        globalsrv_list = {
            {srvid = 2001, host = '127.0.0.1', port = 3335, alias = 'CenterSrvSockfd'},
            {srvid = 2001, host = '127.0.0.1', port = 3334, alias = 'DbSrvSockfd'},
        },
    },
    {'gamesrv/user'},
}

--部署配置
Config = 
{

    --asset_dir = nil,
    --proc_dir = nil,
    srvlist = {
        {srvid = 1,   srvname = 'gatesrv1',  bin = 'bin/gatesrv',   ['gatesrv/websrv'] = {host = '127.0.0.1', port = 9090}, srvdef = gatesrv_def},
        {srvid = 101, srvname = 'gamesrv101',bin = 'bin/gamesrv',   ['gamesrv/gatesrv']   = {host = '127.0.0.1', port = 3332}, srvdef = gamesrv_def},
        {srvid = 301, srvname = 'dbsrv301',  bin = 'bin/globalsrv', ['globalsrv/gamesrv'] = {host = '127.0.0.1', port = 3334}, srvdef = dbsrv_def},
        {srvid = 401, srvname = 'centersrv', bin = 'bin/globalsrv', ['globalsrv/gamesrv'] = {host = '127.0.0.1', port = 3335}, srvdef = centersrv_def},
    },
    --后台管理
    adminsrv = {host = '127.0.0.1', port = 3336},
}



