



--部署配置
Config = 
{

    --loglevel = {"MSG", "INFO", "ERROR", "WARN", "DEBUG"},
    loglevel = {"MSG", "INFO", "ERROR", "WARN"},
    --拓扑结构
    srvgrap = 
    {
        [1] = {300},
        [100] = {300},
        [200] = {300},
        [300] = {100, 200, 1},
    },

    --服务列表
    srvlist = 
    {
        [1] =   {nodeid = 1,    srvname = 'adminsrv',   bin = 'bin/logicsrv',   host = '127.0.0.1', port = 9089,    mainfile = 'adminsrv/main'},
        [100] = {nodeid = 100,  srvname = 'gatesrv1',   bin = 'bin/gatesrv',    host = '127.0.0.1', port = 9090,    mainfile = 'gatesrv/main'},
        [200] = {nodeid = 200,  srvname = 'dbsrv1',     bin = 'bin/logicsrv',   host = '127.0.0.1', port = 9092,    mainfile = 'dbsrv/main'},
        [300] = {nodeid = 300,  srvname = 'localsrv',   bin = 'bin/logicsrv',   host = '127.0.0.1', port = 9093,    mainfile = 'localsrv/main'},
        [400] = {nodeid = 400,  srvname = 'scenesrv1',  bin = 'bin/logicsrv',   host = '127.0.0.1', port = 9094,    mainfile = 'scenesrv/main'},
    },
    test = {host = '127.0.0.1', port = 12341},


    --数据库初始化
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
                    cms_menu = {class = 'dbproto.CmsMenuData'},
                },
            },
        },
    },

    --本服的配置
    localsrv = {
        save_interval = 3600,
        playerdata = {'user', 'task', 'achieve', },
    },

    --db服的配置
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
        domain = '192.168.2.100',
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
--            ['/static'] = '/Users/lujingwei/Documents/nodesrv2/framework/nodesrv/debug/asset/script/gatesrv',
            --['/%w+%.css'] = '',
        },
    },

    mydbconf = {
        test = { host = '127.0.0.1', user = 'root', port = 3306, password = '0987abc123'},
    }
}

