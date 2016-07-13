



--部署配置
Config = 
{
    --拓扑结构
    nodegrap = 
    {
        [1] = {4},
        [4] = {3},
        [3] = {4},
    },

    --服务列表
    nodelist = 
    {
        [0] = {nodeid = 0, nodename = 'test',       bin = 'bin/logicsrv',   host = '127.0.0.1', port = 9093,    mainfile = 'test/main'},
        [1] = {nodeid = 1, nodename = 'gatesrv1',   bin = 'bin/gatesrv',    host = '127.0.0.1', port = 9090,    mainfile = 'gatesrv/main'},
        [2] = {nodeid = 2, nodename = 'scenesrv1',  bin = 'bin/scenesrv',   host = '127.0.0.1', port = 9091,    mainfile = 'scenesrv/main'},
        [3] = {nodeid = 3, nodename = 'dbsrv1',     bin = 'bin/logicsrv',   host = '127.0.0.1', port = 9092,    mainfile = 'dbsrv/main'},
        [4] = {nodeid = 4, nodename = 'localsrv',   bin = 'bin/logicsrv',   host = '127.0.0.1', port = 9093,    mainfile = 'localsrv/main'},
    },

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

}



