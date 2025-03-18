#include "dataoperation.h"
vector<Item*> dataoperation::get_items(string condition,string input){
    sqlite3 *db=NULL;
    vector<Item*> res;
    int db_check=sqlite3_open(databasename.c_str(),&db);
    if(db_check!=SQLITE_OK){
        cout<<"Database open failed\n";
        return res;
    }
    string sql_cmd="SELECT * FROM Item WHERE "+condition+" = ?;";
    sqlite3_stmt *stmt;
    sqlite3_prepare_v2(db,sql_cmd.c_str(),-1,&stmt,NULL);
    sqlite3_bind_text(stmt,1,input.c_str(),-1,SQLITE_TRANSIENT);
    while(sqlite3_step(stmt)==SQLITE_ROW){
        Item *tmp=new Item();
        tmp->set_id(sqlite3_column_int(stmt,0));
        string user((const char *)sqlite3_column_text(stmt,1));
        tmp->set_user(user);
        string title((const char *)sqlite3_column_text(stmt,2));
        tmp->set_title(title);
        string description((const char *)sqlite3_column_text(stmt,3));
        tmp->set_description(description);
        string time((const char *)sqlite3_column_text(stmt,4));
        tmp->set_time(time);
        tmp->set_price(sqlite3_column_int(stmt,5));
        string category((const char *)sqlite3_column_text(stmt,6));
        tmp->set_category(category);
        res.push_back(tmp);
    }
    sqlite3_finalize(stmt);
    db_check=sqlite3_close(db);
    if(db_check!=SQLITE_OK){
        cout<<"Database close failed\n";
        res.clear();
        return res;
    }
    db=NULL;
    return res;
}