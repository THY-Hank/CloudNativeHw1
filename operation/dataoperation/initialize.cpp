#include "dataoperation.h"
bool dbcheck(int a,int b){
    if(a!=b){
        cout<<"Database execute failed\n";
        return false;
    }
    return true;
}
bool databaseExists(const std::string& dbFilePath) {
    sqlite3* db;
    int db_check = sqlite3_open_v2(dbFilePath.c_str(), &db,SQLITE_OPEN_READONLY,NULL);

    if (db_check==SQLITE_OK) {
        sqlite3_close(db);
        return true;
    } else {
        sqlite3_close(db);
        return false;
    }
}

void initialize(){
    if(databaseExists(databasename)){
        cout<<"Database is already exist\n";
        return;
    }
    sqlite3 *db=NULL;
    int db_check=sqlite3_open(databasename,&db);
    if(db_check!=SQLITE_OK){
        cout<<"Database open failed\n";
        return ;
    }
    char sql_cmd[100]="CREATE TABLE User (user_name TEXT PRIMARY KEY);";
    db_check=sqlite3_exec(db,sql_cmd,NULL,NULL,NULL);
    if(!dbcheck(db_check,SQLITE_OK)){
        return ;
    }
    char sql_cmd2[200]="CREATE TABLE Item (id INTEGER PRIMARY KEY,user_name TEXT,\
    title TEXT, time TEXT, category TEXT,FOREIGN key(user_name) REFERENCES User(user_name));";
    db_check=sqlite3_exec(db,sql_cmd2,NULL,NULL,NULL);
    if(!dbcheck(db_check,SQLITE_OK)){
        return ;
    }
    int start=100001;
    char sql_cmd3[200]="CREATE TABLE Number (id INTEGER);INSERT INTO Number (id) VALUES (?);";
    sqlite3_stmt *stmt;
    sqlite3_prepare_v2(db,sql_cmd3,-1,&stmt,NULL);
    sqlite3_bind_int(stmt,1,start);
    db_check=sqlite3_step(stmt);
    if(!dbcheck(db_check,SQLITE_DONE)){
        return ;
    }
    sqlite3_finalize(stmt);
    db_check=sqlite3_close(db);
    if(db_check!=SQLITE_OK){
        cout<<"Database close failed\n";
        return;
    }
    db=NULL;
}