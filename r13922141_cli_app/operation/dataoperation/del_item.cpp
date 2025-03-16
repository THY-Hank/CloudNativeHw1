#include "dataoperation.h"
int del_item(int id){
    sqlite3 *db=NULL;
    int db_check=sqlite3_open(databasename,&db);
    if(db_check!=SQLITE_OK){
        cout<<"Database open failed\n";
        return -1;
    }
    char sql_cmd[50]="DELETE FROM Item WHERE id=?;";
    sqlite3_stmt *stmt;
    sqlite3_prepare_v2(db,sql_cmd,-1,&stmt,NULL);
    sqlite3_bind_int(stmt,1,id);
    db_check=sqlite3_step(stmt);
    sqlite3_finalize(stmt);
    db_check=sqlite3_close(db);
    if(db_check!=SQLITE_OK){
        cout<<"Database close failed\n";
        return -1;
    }
    db=NULL;
    return 0;
}