



--部署配置
Config = 
{
    --拓扑结构
    nodegrap = {
        [1] = {2},
    },

    --服务列表
    nodelist = {
        [1] = {nodeid = 1, nodename = 'gatesrv1',   bin = 'bin/gatesrv',    host = '127.0.0.1', port = 9090,    mainfile = 'gatesrv/main'},
        [2] = {nodeid = 2, nodename = 'scenesrv1',  bin = 'bin/scenesrv',   host = '127.0.0.1', port = 9091,    mainfile = 'scenesrv/main'},
    },
}



