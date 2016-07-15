



--部署配置
Config = 
{

    loglevel = {"MSG", "INFO", "ERROR", "WARN", "DEBUG"},
    --loglevel = {"MSG", "INFO", "ERROR", "WARN"},
    --拓扑结构
    srvgrap = 
    {
        [1] = {4},
        [4] = {1, 3},
        [3] = {4},
    },

    --服务列表
    srvlist = 
    {
        [0] = {nodeid = 0, srvname = 'test',       bin = 'bin/logicsrv',   host = '127.0.0.1', port = 9089,    mainfile = 'test/main'},
        [1] = {nodeid = 1, srvname = 'gatesrv1',   bin = 'bin/gatesrv',    host = '127.0.0.1', port = 9090,    mainfile = 'gatesrv/main'},
        [3] = {nodeid = 3, srvname = 'dbsrv1',     bin = 'bin/logicsrv',   host = '127.0.0.1', port = 9092,    mainfile = 'dbsrv/main'},
        [4] = {nodeid = 4, srvname = 'localsrv',   bin = 'bin/logicsrv',   host = '127.0.0.1', port = 9093,    mainfile = 'localsrv/main'},
    },
    test = {host = '127.0.0.1', port = 12341},

    dbinit = 
    {
        mysql_conf = 
        {
            test = 
            {
                dbproto_dir = 'asset/dbproto',
                host = '127.0.0.1', user = 'root', password = '0987abc123',
                tables = 
                {
                    user = {class = 'dbproto.UserData'},
                    task = {class = 'dbproto.TaskData', binary = true},
                    achieve = {class = 'dbproto.AchieveData', binary = true},
                    friend = {class = 'dbproto.FriendData', binary = true},
                },
            },
        },
    },

    localsrv = {
        save_interval = 3600,
        playerdata = {'user', 'task', 'achieve', },
    },

    dbsrv = 
    {
        host = '0.0.0.0', port = 1234,
        expire_sec = 100,
        delay_write = false,
        dbproto = 'dbproto',
        redis_conf =
        {
            {dbname = '1', host = '127.0.0.1', port = 6379, password = ''},
        },
        mysql_conf = 
        {
            {dbname = 'test', host = '127.0.0.1', user = 'root', port = 3306, password = '0987abc123'},
        },
        --结构表和对象的映射
        table_conf = 
        {
            user = {class = 'dbproto.UserData'},
            task = {class = 'dbproto.TaskData', binary = true},
            achieve = {class = 'dbproto.AchieveData', binary = true},
        },
    },

    httpsrv = 
    {
        domain = '192.168.100.34',
        session = {
            secret = '19860701',
            expires = 3600,
            host = redis_host, dbname = '0', port = 6666, password = redis_password,
        },
        static_dir = '',
        template_dir = '',
        --路由
        route = {
            ['/static'] = '/home/ljw/neox/framework/nodesrv/debug/asset/script/gatesrv',
            --['/%w+%.css'] = '',
        },
    },
}

