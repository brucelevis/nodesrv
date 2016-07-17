module('Cms.Default', package.seeall)


function action_index()
    local menus = Cms.Default.Model.get_menus()
    render('cms/default/index.html', {menus = menus})
end
