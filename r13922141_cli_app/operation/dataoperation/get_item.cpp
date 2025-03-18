#include "dataoperation.h"
Item* dataoperation::get_item(int id){
    sqlite3 *db=NULL;
    Item* res=NULL;
    int db_check=sqlite3_open(databasename.c_str(),&db);
    if(db_check!=SQLITE_OK){
        cout<<"Database open failed\n";
        return res;
    }
    char sql_cmd[50]="SELECT * FROM Item WHERE id=?;";
    sqlite3_stmt *stmt;
    sqlite3_prepare_v2(db,sql_cmd,-1,&stmt,NULL);
    sqlite3_bind_int(stmt,1,id);
    db_check=sqlite3_step(stmt);
    if(db_check==SQLITE_ROW){
        res=new Item();
        res->set_id(id);
        string user((const char *)sqlite3_column_text(stmt,1));
        res->set_user(user);
        string title((const char *)sqlite3_column_text(stmt,2));
        res->set_title(title);
        string description((const char *)sqlite3_column_text(stmt,3));
        res->set_description(description);
        string time((const char *)sqlite3_column_text(stmt,4));
        res->set_time(time);
        res->set_price(sqlite3_column_int(stmt,5));
        string category((const char *)sqlite3_column_text(stmt,6));
        res->set_category(category);
    }
    sqlite3_finalize(stmt);
    db_check=sqlite3_close(db);
    if(db_check!=SQLITE_OK){
        cout<<"Database close failed\n";
        res=NULL;
        return res;
    }
    db=NULL;
    return res;
}