module('HttpEnv', package.seeall)
--初始化环境

local slt2 = require('lib/slt2')

headers = {}
response_buffer = Buffer:new()

if not Config.template_dir then
    Config.template_dir = string.format('%s/template/', Config.asset_dir)
end

_REQUEST = function(self, sid)
    print('sid', sid)
    print('_CONTENT', _CONTENT)
    print('_REQUEST_URL', _REQUEST_URL)
    print('_METHOD', _METHOD)
    print('_HEADER')
    for k, v in pairs(_HEADER) do
        print(k, v)
    end
    
    response_buffer:reset()

    httpmain()

    headers['Content-Length'] = tostring(response_buffer:size())
    self:send_string(sid, 'HTTP/1.1 200 OK\r\n')
    for k, v in pairs(headers) do
        self:send_string(sid, string.format('%s: %s\r\n', k, v))
    end
    self:send_string(sid, '\r\n')
    self:send_buffer(sid, response_buffer)
end
_G._REQUEST = _REQUEST


function header_set(k, v)
    headers[k] = v
end
_G.header_set = header_set


function render(filename, args)
    local file = io.open(string.format('%s/%s', Config.template_dir, filename))
    local str = file:read('*a')
    local tmpl = slt2.loadstring(str)
    local body = slt2.render(tmpl, args)
    echo(body)
end
_G.render = render

function echo(str)
    response_buffer:write_string(str)
end
_G.echo = echo


_G.httpmain = function()
    --render('index.html')
    local pats = string.split(_REQUEST_URL, '/')
    local modname = pats[2]
    local actionname = pats[3]
    local mod = _G[string.cap(modname)]
    if not mod then
        Log.error(string.format('mod not found url(%s)', _REQUEST_URL))
        return
    end
    local action = mod['action_'..actionname]
    if not action then
        Log.error(string.format('action not found url(%s)', _REQUEST_URL))
        return
    end
    action()
end




