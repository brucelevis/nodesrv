
table.insert(Mod.search_path, string.format('%s/test/module', Config.asset_dir))
package.path = string.format('%s;%s/test/module/?.lua', package.path, Config.asset_dir)

require('test/entity/client')

mysrv:create_entity_local('ClientEntity')

local function run_func(mod_name, func_name)
    local mod = _G[string.cap(mod_name)]
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

local url = arg[3]
local mod_name = nil
local func_name = nil
if url then
    local pats = string.split(url, '.')
    mod_name = pats[1]
    func_name = pats[2]
end

local root_dir = string.format('%s/test/module', Config.asset_dir)
local files = File.listdir(root_dir)
if not files then
    print(string.format('dir(%s) not exists', root_dir))
    os.exit(1)
end
--加载模块
for _, file in pairs(files) do
    if file.type == File.TYPE_DIR then
        import(file.name)
    end
end
--执行函数
run_func(mod_name, func_name)
os.exit(0)

