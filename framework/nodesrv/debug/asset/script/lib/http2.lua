module('HttpEnv', package.seeall)
--初始化环境

local slt2 = require('lib/slt2')

headers = {}
cookies = {}
sessions = {}
response_buffer = Buffer:new()

if not Config.template_dir then
    Config.template_dir = string.format('%s/template/', Config.asset_dir)
end

_REQUEST = function(self, sid)
    print('sid', sid)
    print('_CONTENT', _CONTENT)
    print('_REQUEST_URL', _REQUEST_URL)
    print('_QUERY_STRING', _QUERY_STRING)
    print('_METHOD', _METHOD)
    print('_HEADER')
    for k, v in pairs(_HEADER) do
        print(k, v)
    end
    print('_GET')
    for k, v in pairs(_GET) do
        print(k, v)
    end
    print('_COOKIE')
    for k, v in pairs(_COOKIE) do
        print(k, v)
    end
    
    response_buffer:reset()
    cookies = {}
    headers = {}

    httpmain()

    headers['Content-Length'] = tostring(response_buffer:size())
    self:send_string(sid, 'HTTP/1.1 200 OK\r\n')
    for k, v in pairs(headers) do
        self:send_string(sid, string.format('%s: %s\r\n', k, v))
    end
    for k , v in pairs(cookies) do
        self:send_string(sid, string.format('Set-Cookie: %s\r\n', v))
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
    local filepath = string.format('%s/%s', Config.template_dir, filename)
    local file = io.open(filepath)
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
    local mod = _G
    for k = 2, #pats do
        local action = mod['action_'..pats[k]]
        if action then
            action()
            break
        end
        mod = mod[string.cap(pats[k])]
        if not mod then
            break
        end
    end
    logerr('mod not found url(%s)', _REQUEST_URL)
end

--功能:设置cookie
--@k
--@v
--@expires 秒
--@domain baidu.com
--@path
function cookie_set(k, v, expires, domain, path)
    if v then
        v = tostring(v)
    end
    domain = domain or '192.168.2.100'
    path = path or '/'
    expires = expires or 3600
    expires = os.time() + expires
    if not v then
        expires = 0
    end
    expires = format_time(expires)
    cookies[k] = string.format('%s=%s; Domain=%s; Path=%s; Expires=%s', k, v or '', domain, path, expires)
    _COOKIE[k] = v
end
_G.cookie_set = cookie_set

--功能:返回标准时间格式
function format_time(time)
    return Date.strftime('%a, %d-%b-%Y %H:%m:%S %Z', time)
end


function session_start()
    local sid = _COOKIE['sid']
    if not sid then
        sid = tostring(os.time())
        cookie_set('sid', sid)
    end
    if not sessions[sid] then
        sessions[sid] = {}
    end
end
_G.session_start = session_start

function session_destory()
    local sid = _COOKIE['sid']
    if sid then
        sessions[sid] = nil
    end
    cookie_set('sid', nil)
end
_G.session_destory = session_destory


function session_get(k)
    local sid = _COOKIE['sid']
    if not sid then
        return
    end
    if not sessions[sid] then
        return
    end
    return sessions[sid][k]
end
_G.session_get = session_get

function session_set(k, v)
    local sid = _COOKIE['sid']
    if not sid then
        return
    end
    sessions[sid][k] = v
end
_G.session_set = session_set


