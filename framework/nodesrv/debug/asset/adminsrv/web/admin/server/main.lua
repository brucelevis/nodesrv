module('Admin.Server', package.seeall)

function action_index()
    local srvlist = {}
    for k, conf in pairs(Config.srvlist) do
        local srv = {
                nodeid = conf.nodeid,
                srvname = conf.srvname,
                host = conf.host,
                port = conf.port,
            }
        local running_dir = string.format('%s/%s', Config.proc_dir, conf.srvname)
        local pidfile = string.format('%s/pid', running_dir)
        local pid = nil
        if File.exists(pidfile) then
            local file = io.open(pidfile, 'r')
            pid = file:read()
            file:close()
            if File.exists(string.format('/proc/%s', pid)) then
                pid = nil
            end
        end
        srv.pid = pid
        srvlist[k] = srv
    end
    render('admin/server/index.html', {srvlist = srvlist}) 
end
