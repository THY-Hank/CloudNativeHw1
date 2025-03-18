#include "dataoperation.h"
string get_top(){
    sqlite3 *db=NULL;
    string res="";
    int db_check=sqlite3_open(databasename,&db);
    if(db_check!=SQLITE_OK){
        cout<<"Database open failed\n";
        return res;
    }
    string sql_cmd="SELECT name FROM Category ORDER BY count DESC LIMIT 1;";
    sqlite3_stmt *stmt;
    sqlite3_prepare_v2(db,sql_cmd.c_str(),-1,&stmt,NULL);
    while(sqlite3_step(stmt)==SQLITE_ROW){
        res=(const char *)sqlite3_column_text(stmt,0);
    }
    sqlite3_finalize(stmt);
    db_check=sqlite3_close(db);
    if(db_check!=SQLITE_OK){
        cout<<"Database close failed\n";
        res="";
        return res;
    }
    db=NULL;
    return res;
}