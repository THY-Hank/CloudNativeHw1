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
    string sql_cmd="CREATE TABLE User (user_name TEXT PRIMARY KEY);";
    db_check=sqlite3_exec(db,sql_cmd.c_str(),NULL,NULL,NULL);
    if(!dbcheck(db_check,SQLITE_OK)){
        return ;
    }
    string sql_cmd2="CREATE TABLE Item (id INTEGER PRIMARY KEY,user_name TEXT,\
    title TEXT, description TEXT, time TEXT DEFAULT (datetime('now','localtime')), price INTEGER, category TEXT,FOREIGN key(user_name) REFERENCES User(user_name));";
    db_check=sqlite3_exec(db,sql_cmd2.c_str(),NULL,NULL,NULL);
    if(!dbcheck(db_check,SQLITE_OK)){
        return ;
    }
    int start=100001;
    string sql_cmd3="CREATE TABLE Number (id INTEGER);";
    db_check=sqlite3_exec(db,sql_cmd3.c_str(),NULL,NULL,NULL);
    if(!dbcheck(db_check,SQLITE_OK)){
        return ;
    }
    string sql_cmd4="INSERT INTO Number (id) VALUES (?);";
    sqlite3_stmt *stmt;
    sqlite3_prepare_v2(db,sql_cmd4.c_str(),-1,&stmt,NULL);
    sqlite3_bind_int(stmt,1,start);
    db_check=sqlite3_step(stmt);
    if(!dbcheck(db_check,SQLITE_DONE)){
        return ;
    }
    sqlite3_finalize(stmt);
    string ccmd="CREATE TABLE Category (count INTEGER, name TEXT PRIMAER KEY);";
    db_check=sqlite3_exec(db,ccmd.c_str(),NULL,NULL,NULL);
    if(!dbcheck(db_check,SQLITE_OK)){
        return ;
    }
    db_check=sqlite3_close(db);
    if(db_check!=SQLITE_OK){
        cout<<"Database close failed\n";
        return;
    }
    db=NULL;
}