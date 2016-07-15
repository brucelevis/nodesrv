module('Cms.Default.Model', package.seeall)


function get_menus()
    local result = mydb.test:select('select * from cms_menu')
    local menus = {}
    for k, v in pairs(result) do
        if not v.parent then
            menus[v.name] = v
        end
    end
    for k, v in pairs(result) do
        if v.parent then
            local parent_menu = menus[v.parent]
            if not parent_menu.sub_menus then
                parent_menu.sub_menus = {}
            end
            parent_menu.sub_menus[v.name] = v
        end
    end
    return menus
end


