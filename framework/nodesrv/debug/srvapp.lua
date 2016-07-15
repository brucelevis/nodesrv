--dofile(os.getenv('ENGINE_PATH')..'/bin/luaenv')

--------------------------------------------------------------------------------------------------------------------------------------
function _atint()
    loginfo('atint')
end

function _atexit()
    loginfo('atexit')
    clearpid()
end

function clearpid()
    loginfo('clearpid')
    --清理pid
    local file = io.open('pid', 'r')
    if file then
        local pid = file:read()
        file:close()
        os.remove('pid')
        loginfo('exit pid(%d)', pid)
    end
end

function recordpid()
    --if File.exists('pid') then
        --loginfo('pid file exists')
        --os.exit(1)
        --return
    --end
    local pid = System.getpid()
    local file = io.open('pid', 'w+')
    file:write(pid)
    file:close()
    loginfo('running pid(%d)', pid)
end
--------------------------------------------------------------------------------------------------------------------------------------

dofile('bin/luaenv')

local srvname = arg[2]
local is_daemon = arg[3] == '-d'

local node_conf = nil
for k, conf in pairs(Config.srvlist) do
    if srvname == conf.srvname then
        node_conf = conf
    end
end
if not node_conf then
    print(string.format('%s not found', srvname))
    os.exit(0)
end

Config.nodeid = node_conf.nodeid
Config.srvname = node_conf.srvname
Config.host = node_conf.host
Config.port = node_conf.port

local running_dir = string.format('%s/%s', Config.proc_dir, Config.srvname)
if not File.exists(running_dir) then
    File.mkdirs(running_dir)
end
File.chdir(running_dir)
loginfo('running dir(%s)', File.getcwd())


--本地节点
NodeMgr.create_node_local(Config.nodeid)
mysrv:listen(Config.host, Config.port)
--远程节点
local srvlist = Config.srvgrap[Config.nodeid]
if srvlist then
    for k, nodeid in pairs(srvlist) do
        local node = NodeMgr.create_node_remote(nodeid)
        local node_conf = Config.srvlist[nodeid]
        node:connect(node_conf.host, node_conf.port)
        _G[node_conf.srvname] = nodeid
    end
end


if is_daemon then
    mysrv:run_background()
    local d = os.date('*t')
    Log.stdout2file(string.format('%s_%04d%02d%02d', Config.srvname, d.year, d.month, d.day))
end
recordpid()

Log.closealllevel()
for _, v in pairs(Config.loglevel) do
    Log.openlevel(Log[v])
end

Pblua.import_dir(string.format('%s/proto', Config.asset_dir))
Pblua.import_dir(string.format('%s/dbproto', Config.asset_dir))

--进入游戏
require(node_conf.mainfile)

