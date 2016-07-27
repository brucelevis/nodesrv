module('Cms.Default', package.seeall)

local model = Cms.Default.Model

function action_index()
    local menus = model.get_menus()
    render('cms/default/index.html', {menus = menus})
end
