#include "dataoperation.h"
vector<string> get_top(){
    sqlite3 *db=NULL;
    vector<string> res;
    int db_check=sqlite3_open(databasename,&db);
    if(db_check!=SQLITE_OK){
        res.push_back("Database open failed\n");
        return res;
    }
    bool check=0;
    sqlite3_stmt *stmtc;
    string check_cmd="SELECT EXISTS(SELECT 1 FROM Category)";
    sqlite3_prepare_v2(db,check_cmd.c_str(),-1,&stmtc,NULL);
    db_check=sqlite3_step(stmtc);
    if(db_check==SQLITE_ROW){
        check=sqlite3_column_int(stmtc,0);
    }
    sqlite3_finalize(stmtc);
    
    if(!check){
        res.push_back("NULL");
        return res;
    }
    string sql_cmd="SELECT * FROM Category ORDER BY count DESC;";
    sqlite3_stmt *stmt;
    sqlite3_prepare_v2(db,sql_cmd.c_str(),-1,&stmt,NULL);
    int count=-1;
    while(sqlite3_step(stmt)==SQLITE_ROW){
        int tmp=sqlite3_column_int(stmt,0);
        if(count==-1) count=tmp;
        else if(tmp<count){
            break;
        }
        res.push_back((const char *)sqlite3_column_text(stmt,1));
    }
    sqlite3_finalize(stmt);
    db_check=sqlite3_close(db);
    if(db_check!=SQLITE_OK){
        res.clear();
        res.push_back("Database close failed\n");
        return res;
    }
    db=NULL;
    return res;
}