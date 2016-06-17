#include "component/mysqlcomponent.h"

MYSQLComponent::MYSQLComponent()
{
    conn_ = 0;
}

MYSQLComponent::~MYSQLComponent()
{

}


void MYSQLComponent::update(long long cur_tick)
{

}

int MYSQLComponent::connect(const char*host, const char* dbname, const char* user, const char* passwd)
{
    my_bool b = 1;
    MYSQL *conn = mysql_init(NULL);
    mysql_options(conn, MYSQL_OPT_RECONNECT, &b);
    conn = mysql_real_connect(conn, host, user, passwd, dbname, 0, NULL, MYSQL_OPT_RECONNECT);
    if(conn == NULL){
        return 1;
    }
    mysql_query(conn, "set names utf8");
    this->conn_ = conn;
    //mysql_options(mysql->conn, MYSQL_SET_CHARSET_NAME, "utf8");
    return 0;
}


int MYSQLComponent::command(const char* str)
{
    if(mysql_query(this->conn_, str) != 0){
        printf("%s\n", mysql_error(this->conn_));
        return 1;
    }
    return 0;
}

int MYSQLComponent::select(const char* str)
{
    int i;
    MYSQL_RES *result;
    MYSQL_ROW row;
    MYSQL_FIELD *fields;
    MYSQL* conn = this->conn_;
    int index = 1;
    if(conn == NULL){
        return 1;
    }
    mysql_query(conn, "set names utf8");
    mysql_query(conn, str);
    result = mysql_store_result(conn);
    if(result == NULL){
        printf("select fail %d %s command %s", mysql_errno(conn), mysql_error(conn), str);
        return 1;
    }
    while(result != NULL){
        int num_fields = mysql_num_fields(result);
        fields = mysql_fetch_fields(result);
        if(fields == NULL){
            mysql_free_result(result);
            printf("select fail fetch_fields command:%s", str);
            break;
        }
        while ((row = mysql_fetch_row(result))){
            //unsigned long *lengths = mysql_fetch_lengths(result);
            index++;
            for(i = 0; i < num_fields; i++){
                //lua_pushstring(L, fields[i].name);
                    //if(fields[i].type == FIELD_TYPE_STRING
                            //|| fields[i].type == FIELD_TYPE_VAR_STRING
                            //|| fields[i].type == FIELD_TYPE_TINY_BLOB
                            //|| fields[i].type == FIELD_TYPE_MEDIUM_BLOB
                            //|| fields[i].type == FIELD_TYPE_LONG_BLOB
                            //|| fields[i].type == FIELD_TYPE_BLOB){
                        //lua_pushlstring(L, row[i], lengths[i]);
                        //lua_pushnumber(L, atof(row[i]));
                        //lua_pushnumber(L, atoi(row[i]));
            }
        }
        mysql_free_result(result);
        result = NULL;
        //是否还有结果集
        if(mysql_next_result(conn) == 0){
            result = mysql_store_result(conn);
        }
    }
    return 0;
}
