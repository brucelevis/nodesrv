


function instantiate(conf)
    local entity = Entity:new()
    for k, v in pairs(conf) do
        if k == 1 then
            for class, component_conf in pairs(v) do
                local component = _G[class]:new()
                Entity.add_component(entity, component)
                for varname, value in pairs(component_conf) do
                    component[varname] = value
                end
            end
        elseif k == 2 then
            for class, component_conf in pairs(v) do
                local component = Entity.add_script(entity, class)
                for varname, value in pairs(component_conf) do
                    component[varname] = value
                end
            end
        elseif k == 3 then
            for varname, value in pairs(v) do
                entity[varname] = value
            end
        else
            local child = instantiate(v)
            child.name = k
            Entity.add_child(entity, child)
        end
    end
    return entity
end


