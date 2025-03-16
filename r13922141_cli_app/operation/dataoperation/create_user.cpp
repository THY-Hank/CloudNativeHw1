#include "dataoperation.h"
int create_user(string name){
    sqlite3 *db=NULL;
    int db_check=sqlite3_open(databasename,&db);
    if(db_check!=SQLITE_OK){
        cout<<"Database open failed\n";
        return -1;
    }
    sqlite3_stmt *stmt;
    char sql_cmd[100]="INSERT INTO User (user_name) VALUES (?);";
    sqlite3_prepare_v2(db,sql_cmd,-1,&stmt,NULL);
    sqlite3_bind_text(stmt,1,name.c_str(),-1,SQLITE_TRANSIENT);
    db_check=sqlite3_step(stmt);
    if(db_check!=SQLITE_DONE){
        cout<<"Database execute failed\n";
        return -1;
    }
    sqlite3_finalize(stmt);
    db_check=sqlite3_close(db);
    if(db_check!=SQLITE_OK){
        cout<<"Database close failed\n";
        return -1;
    }
    db=NULL;
    return 0;
}