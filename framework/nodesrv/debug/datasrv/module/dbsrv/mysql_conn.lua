module('DbSrv', package.seeall)

mysql_table = mysql_table or {}

function check_mysql_connections()
    --连接
    for index, conf in pairs(Config.dbsrv.mysql_conf) do
        local conn = mysql.create()
        if conn:connect(conf.host, conf.dbname, conf.user, conf.password) then
            loginfo('success connect mysql index(%d) host(%s) dbname(%s) user(%s)', index, conf.host, conf.dbname, conf.user)
            mysql_table[index] = conn
        else
            loginfo('fail connect mysql index(%d) host(%s) dbname(%s) user(%s)', index, conf.host, conf.dbname, conf.user, conf.password)
            os.exit(0)
        end
    end
end

function select_mysql_connection(uid)
    local index = math.fmod(uid, #mysql_table)
    local conn = mysql_table[index + 1]
    return conn
end
