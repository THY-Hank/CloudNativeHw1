#include "dataoperation.h"
bool dataoperation::check_user(string name){
    bool res=false;
    sqlite3 *db=NULL;
    int db_check=sqlite3_open(databasename.c_str(),&db);
    sqlite3_stmt *stmt;
    char sql_cmd[100]="SELECT EXISTS(SELECT 1 FROM User WHERE user_name = ?);";
    sqlite3_prepare_v2(db,sql_cmd,-1,&stmt,NULL);
    sqlite3_bind_text(stmt,1,name.c_str(),-1,SQLITE_TRANSIENT);
    db_check=sqlite3_step(stmt);
    if(db_check==SQLITE_ROW){
        res=sqlite3_column_int(stmt,0);
    }
    sqlite3_finalize(stmt);
    db_check=sqlite3_close(db);
    db=NULL;
    return res;
}