--dofile(os.getenv('ENGINE_PATH')..'/bin/luaenv')

--------------------------------------------------------------------------------------------------------------------------------------
function _atint()
    Log.info('atint')
end

function _atexit()
    Log.info('atexit')
    clearpid()
end

function clearpid()
    --清理pid
    local file = io.open('pid', 'r')
    if file then
        local pid = file:read()
        file:close()
        os.remove('pid')
        Log.info(string.format('exit pid(%d)', pid))
    end
end

function recordpid()
    --if File.exists('pid') then
        --Log.info('pid file exists')
        --os.exit(1)
        --return
    --end
    local pid = System.getpid()
    local file = io.open('pid', 'w+')
    file:write(pid)
    file:close()
    Log.info(string.format('running pid(%d)', pid))
end
--------------------------------------------------------------------------------------------------------------------------------------

require('config')
if not Config.proc_dir then
    Config.proc_dir = string.format('%s/proc', File.getcwd())
end
if not Config.asset_dir then
    Config.asset_dir = string.format('%s/asset', File.getcwd())
end
package.path = string.format('%s;%s/script/?.lua', package.path, Config.asset_dir)

local nodename = arg[2]
local is_daemon = arg[3] == '-d'

local node_conf = nil
for k, conf in pairs(Config.nodelist) do
    if nodename == conf.nodename then
        node_conf = conf
    end
end
if not node_conf then
    print(string.format('%s not found', nodename))
    os.exit(0)
end

Config.nodeid = node_conf.nodeid
Config.nodename = node_conf.nodename
Config.host = node_conf.host
Config.port = node_conf.port

if not File.exists(Config.proc_dir) then
    File.mkdirs(Config.proc_dir)
end
local running_dir = string.format('%s/%s', Config.proc_dir, Config.nodename)
if not File.exists(running_dir) then
    File.mkdirs(running_dir)
end
File.chdir(running_dir)
Log.info(string.format('running dir(%s)', File.getcwd()))

--nodeapp.fork_daemon(is_daemon)
--if is_daemon then
    --local d = os.date('*t')
    --Log.stdout2file(string.format('%s_%04d%02d%02d', Config.nodename, d.year, d.month, d.day))
--end

recordpid()

NodeMgr.create_node_local(Config.nodeid)
mynode:listen(Config.host, Config.port)

local nodelist = Config.nodegrap[Config.nodeid]
if nodelist then
    for k, nodeid in pairs(nodelist) do
        local node = NodeMgr.create_node_remote(nodeid)
        local node_conf = Config.nodelist[nodeid]
        node:connect(node_conf.host, node_conf.port)
    end
end

require(node_conf.mainfile)
--import('pblua')
--Pblua.import_dir(string.format('%s/proto', asset_dir))
--Pblua.import_dir(string.format('%s/dbproto', asset_dir))

--for _, argv in pairs(srv_conf.srvdef) do
    --local mod = import(argv[1])
    ----重写配置
    --local argv2 = srv_conf[argv[1]]
    --if argv2 then
        --for k, v in pairs(argv2) do
            --argv[k] = v
        --end
    --end
    --mod.argv = argv
--end

--Mod.call('main')

--Asyncsrv.mainloop()

