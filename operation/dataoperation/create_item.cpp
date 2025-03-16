#include "dataoperation.h"
int create_item(string name,int id,string title,string description,string time,int price,string category){
    sqlite3 *db=NULL;
    int db_check=sqlite3_open(databasename,&db);
    if(db_check!=SQLITE_OK){
        cout<<"Database open failed\n";
        return -1;
    }
    sqlite3_stmt *stmt;
    char sql_cmd[100]="INSERT INTO Item (id,user_name,title,description,time,price,category) VALUES (?,?,?,?,?,?,?);";
    sqlite3_prepare_v2(db,sql_cmd,-1,&stmt,NULL);
    sqlite3_bind_int(stmt,1,id);
    sqlite3_bind_text(stmt,2,name.c_str(),-1,SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt,3,title.c_str(),-1,SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt,4,description.c_str(),-1,SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt,5,time.c_str(),-1,SQLITE_TRANSIENT);
    sqlite3_bind_int(stmt,6,price);
    sqlite3_bind_text(stmt,7,category.c_str(),-1,SQLITE_TRANSIENT);
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