#include "dataoperation.h"
Item* get_top(string condition){
    sqlite3 *db=NULL;
    Item* res=NULL;
    int db_check=sqlite3_open(databasename,&db);
    if(db_check!=SQLITE_OK){
        cout<<"Database open failed\n";
        return res;
    }
    string sql_cmd="SELECT * FROM Item ORDER BY "+condition+" DESC LIMIT 1;";
    sqlite3_stmt *stmt;
    sqlite3_prepare_v2(db,sql_cmd.c_str(),-1,&stmt,NULL);
    while(sqlite3_step(stmt)==SQLITE_ROW){
        res=new Item();
        res->set_id(sqlite3_column_int(stmt,0));
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