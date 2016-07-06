module('Asyncsrv', package.seeall)
--异步服务器
--服务器由数据包和定时器驱动

loop = loop or nil

function main()
    loginfo('create loop')
    loop = Ae.create(10240)
end

function mainloop()
    Ae.main(loop)
    loginfo('game over!')
end

function add_timer(milliseconds, callback)
    Ae.create_time_event(Ae.main_loop(), milliseconds, 'Gamesrv.test')
end

function stop()
    Ae.stop(loop)
end
