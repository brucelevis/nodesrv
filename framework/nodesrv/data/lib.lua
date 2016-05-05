
__COMPONENTS = 1
__CHILDREN = 2

function instantiate(conf)
    local entity = Entity:new()
    for k, v in pairs(conf) do
        if k == __COMPONENTS then
            for class, component_conf in pairs(v) do
                if component_conf.__script then
                    local component = Entity.add_script(entity, component_conf.__script)
                    for varname, value in pairs(component_conf) do
                        component[varname] = value
                    end
                else
                    local component = _G[class]:new()
                    Entity.add_component(entity, component)
                    for varname, value in pairs(component_conf) do
                        component[varname] = value
                    end
                end
            end
        elseif k == __CHILDREN then
            local child = instantiate(v)
            child.name = k
            Entity.add_child(entity, child)
        else
            entity[k] = v
        end
    end
    return entity
end
