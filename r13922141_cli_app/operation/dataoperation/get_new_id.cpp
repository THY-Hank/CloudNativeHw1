#include "dataoperation.h"
int get_new_id(){
    sqlite3 *db=NULL;
    int db_check=sqlite3_open(databasename,&db);
    if(db_check!=SQLITE_OK){
        cout<<"Database open failed\n";
        return -1;
    }
    char sql_cmd[50]="SELECT id FROM Number;";
    int id=-1;
    sqlite3_stmt *stmtf;
    sqlite3_prepare_v2(db,sql_cmd,-1,&stmtf,NULL);
    db_check=sqlite3_step(stmtf);
    if(db_check==SQLITE_ROW){
        id=sqlite3_column_int(stmtf,0);
    }
    else{
        cout<<"No data found in Number\n";
        return -1;
    }
    sqlite3_finalize(stmtf);
    char sql_cmd2[50]="UPDATE Number SET id=?;";
    sqlite3_stmt *stmt;
    sqlite3_prepare_v2(db,sql_cmd2,-1,&stmt,NULL);
    sqlite3_bind_int(stmt,1,id+1);
    db_check=sqlite3_step(stmt);
    sqlite3_finalize(stmt);
    db_check=sqlite3_close(db);
    if(db_check!=SQLITE_OK){
        cout<<"Database close failed\n";
        return -1;
    }
    return id;
}
