DbinitConf = {
    mysql_conf = {
        test = {
            dbproto_dir = 'asset/dbproto',
            host = '127.0.0.1', user = 'root', password = '0987abc123',
            tables = {
                user = {class = 'dbproto.UserData'},
                task = {class = 'dbproto.TaskData', binary = true},
                achieve = {class = 'dbproto.AchieveData', binary = true},
                friend = {class = 'dbproto.FriendData', binary = true},
            },
        },
    },
}
