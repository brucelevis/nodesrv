dofile('bin/luaenv')

package.path = string.format('%s;%s/test/module/?.lua', package.path, Config.asset_dir)
require('test/main')

local function run_func(mod_name, func_name)
    local mod = _G[mod_name]
    if not mod then
        print('mod(%s) not found', mod_name)
        return
    end
    local func = mod[func_name]
    if not func then
        Log.error(string.format('func(%s.%s) not found', mod_name, func_name or ''))
        return
    end
    local player = {uid = 333}
    func(player)
    print(string.format('(ok)run %s.%s', mod_name, func_name))
end

local url = arg[2]
local mod_name = nil
local func_name = nil
if url then
    local pats = string.split(url, '.')
    mod_name = pats[1]
    func_name = pats[2]
end

--Log.closealllevel()
import_proto(string.format('%s/proto', Config.asset_dir))
--执行函数
run_func(mod_name, func_name)
os.exit(0)

