
dofile(os.getenv('ENGINE_PATH')..'/bin/luaenv')

_G['_atint'] = function()
    Log.info('atint')
    Asyncsrv.stop()
end

_G['_atexit'] = function()
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
    if File.exists('pid') then
        Log.info('pid file exists')
        os.exit(1)
        return
    end
    local pid = System.getpid()
    local file = io.open('pid', 'w+')
    file:write(pid)
    file:close()
    Log.info(string.format('running pid(%d)', pid))
end

local srvname = arg[2]
local is_daemon = arg[3] == '-d'

local srvconf = nil
for k, conf in pairs(Config.srvlist) do
    if srvname == conf.srvname then
        srvconf = conf
    end
end
if not srvconf then
    print(string.format('%s not found', srvname))
    os.exit(1)
end
if not srvconf.srvdef then
    print(string.format('srvdef not found'))
    os.exit(1)
end

Config.srvid = srvconf.srvid
Config.srvname = srvconf.srvname
Config.srvconf = srvconf


--切换工作目录
if not Config.proc_dir then
    Config.proc_dir = string.format('%s/proc', File.getcwd())
end
if not File.exists(Config.proc_dir) then
    File.mkdirs(Config.proc_dir)
end
local running_dir = string.format('%s/%s', Config.proc_dir, Config.srvname)
if not File.exists(running_dir) then
    File.mkdirs(running_dir)
end
File.chdir(running_dir)
Log.info(string.format('running dir(%s)', File.getcwd()))

Srvapp.fork_daemon(is_daemon)
if is_daemon then
    local d = os.date('*t')
    Log.stdout2file(string.format('%s_%04d%02d%02d', Config.srvname, d.year, d.month, d.day))
end

recordpid()

import('pblua')
Pblua.import_dir(string.format('%s/proto', asset_dir))
Pblua.import_dir(string.format('%s/dbproto', asset_dir))

for _, argv in pairs(srvconf.srvdef) do
    local mod = import(argv[1])
    --重写配置
    local argv2 = srvconf[argv[1]]
    if argv2 then
        for k, v in pairs(argv2) do
            argv[k] = v
        end
    end
    mod.argv = argv
end

Mod.call('main')


Asyncsrv.mainloop()



