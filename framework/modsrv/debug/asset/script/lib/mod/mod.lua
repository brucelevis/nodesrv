module('Mod', package.seeall)

--[[
usage:
Mod.load('scene')
Mod.reload('scene')
Mod.reload()
Mod.call('update')
--]]

search_path = {'.'}
mod_table = {}
loaded = {}

function test()
    Log.info('test')
end

function load(mod_path, isreload)
    local real_path = mod_path
    for _, root_path in pairs(search_path) do
        real_path = string.format('%s/%s', root_path, mod_path)
        if File.exists(real_path) then
            break
        end
    end
    local pats = string.split(mod_path, '/')
    local mod_name = string.cap(pats[#pats])
    local mod = _G[mod_name]
    Log.info(string.format('import mod_path(%s) mod_name(%s)', mod_path, mod_name))
    local files = File.listdir(real_path)
    if not files then
        Log.warn(string.format('dir not exist %s!!!!!!!!!!!!!!!!!!!!!!!!', mod_path))
        return
    end
    for _, file in pairs(files) do
        if file.type == File.TYPE_FILE then
            local file_path = string.format('%s/%s', mod_path, file.name)
            local index = string.find(file_path, '.lua$')
            if index and index + 3 == string.len(file_path) then
                local require_path = string.sub(file_path, 1, index - 1)
                Log.info(string.format('scan file(%s)', file_path))
                if isreload then
                    package.loaded[require_path] = nil
                end
                require(require_path)
            else
                Log.info(string.format('ignore file(%s)!!!!!', file_path))
            end
        end
    end
    local mod = _G[mod_name]
    if not mod then
        Log.error(string.format('mod(%s) not found, please check mod name(%s)!!!', mod_path, mod_name))
        os.exit(1)
    end
    mod_table[#mod_table + 1] = mod
    loaded[mod_path] = mod_name
    mod.loginfo = function(format, ...) Log.info(string.format('[%s]'..format, mod_name, ...)) end
    mod.logwarn = function(format, ...) Log.info(string.format('[%s]'..format, mod_name, ...)) end
    mod.logerr = function(format, ...) Log.info(string.format('[%s]'..format, mod_name, ...)) end
    Log.info('')
    return mod
end

function cap(str)
    return string.upper(string.sub(str, 1, 1))..string.sub(str, 2)
end

function reload(mod_path)
    import(mod_path, true)
end

function call(func_name, ...)
    for _, mod in pairs(mod_table) do
        local func = mod[func_name]
        if func then
            func(unpack(arg))
        end
    end
end

_G['import'] = load
_G['reimport'] = reload
