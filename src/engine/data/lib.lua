
__COMPONENTS = 1
__CHILDREN = 2

function instantiate(conf)
    local object = GameObject:new()
    for k, v in pairs(conf) do
        if k == __COMPONENTS then
            for class, component_conf in pairs(v) do
                if component_conf.__script then
                    local component = object:add_script(component_conf.__script)
                    for varname, value in pairs(component_conf) do
                        component[varname] = value
                    end
                else
                    local component_class = _G[class]
                    if not component_class then
                        print(string.format('%s not found', class))
                    end
                    local component = component_class:new()
                    object:add_component(component)
                    for varname, value in pairs(component_conf) do
                        component[varname] = value
                    end
                end
            end
        elseif k == __CHILDREN then
            for k2, v2 in pairs(v) do
                local child = instantiate(v2)
                child.name = k2
                object:add_child(child)
            end
        else
            object[k] = v
        end
    end
    return object 
end


NEW_POST = function(srvid)
    local srvid = srvid
    local modname = nil
    local funname = nil
    local mt = {
        __index = function(self, k)
            if not modname then 
                modname = k 
            else
                funcname = k
            end
            return self
        end,
        __call = function(self, ...)
            modname = nil
            funcname = nil
            mynode:post(srvid, modname, funcname, ...)
        end
    }
    local stub  = {}
    setmetatable(stub, mt)
    return stub
end

--兼容以前的协议
POST = function(...)
    mynode:post(...)
end

function import_proto(dir)
    Pblua.mappath('', dir)
    local files = File.listdir(dir)
    for _, file in pairs(files) do
        if file.type == File.TYPE_FILE and string.find(file.name, '.proto$') then
            logdebug(string.format('load proto(%s)', file.name))
            Pblua.import(file.name)
        end
    end
end

