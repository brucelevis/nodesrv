module('Cms.Account', package.seeall)


function action_login()
    cookie_set('uid', '333')
    cookie_set('uname', 'ljw')

    session_start()
    if not session_get('tick') then
        print('asdfasfasdfasdf', session_get('tick'))
        session_set('tick', 0)
    end
    print('asdfasf', session_get('tick'))
    local tick = tonumber(session_get('tick'))
    tick = tick + 1
    session_set('tick', tick)
    render('cms/account/index.html', {uname = 'ljw', tick = tick})
end
