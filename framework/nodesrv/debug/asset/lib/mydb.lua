
--[[
mydb.test.
--]]


local mydb_meta = {
    __index = function(self, dbname)
        local conn = self._connections[dbname]
        if not conn then
            conn = mysql.create()
            self._connections[dbname] = conn
            local conf = self._dbconf[dbname]
            if not conf then
                logerr('conf not found db(%s)', dbname)
                return
            end
            if conn:connect(conf.host, conf.dbname, conf.user, conf.password) then
                loginfo('success connect mysql host(%s) dbname(%s) user(%s)', conf.host, dbname, conf.user)
            else
                loginfo('fail connect mysql host(%s) dbname(%s) user(%s)', conf.host, dbname, conf.user)
            end
        end
        if not conn:ping() then
            return
        end
        return conn
    end
}

mydb = {
    _connections = {},
    _dbconf = {},
}

mydb.connect = function(conf)
    mydb._dbconf = conf
end

setmetatable(mydb, mydb_meta)

