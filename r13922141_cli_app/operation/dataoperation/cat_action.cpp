#include "dataoperation.h"
int dataoperation::cat_action(string category,int add){
    sqlite3 *db=NULL;
    int db_check=sqlite3_open(databasename.c_str(),&db);
    if(db_check!=SQLITE_OK){
        cout<<"Database open failed\n";
        return -1;
    }
    sqlite3_stmt *stmt;
    bool res=0;
    string check_cmd="SELECT EXISTS(SELECT 1 FROM Category WHERE name = ?);";
    sqlite3_prepare_v2(db,check_cmd.c_str(),-1,&stmt,NULL);
    sqlite3_bind_text(stmt,1,category.c_str(),-1,SQLITE_TRANSIENT);
    db_check=sqlite3_step(stmt);
    if(db_check==SQLITE_ROW){
        res=sqlite3_column_int(stmt,0);
    }
    if(!res){
        sqlite3_finalize(stmt);
        sqlite3_stmt *stmt2;
        string insert_cmd="INSERT INTO Category(count,name) VALUES(1,?)";
        sqlite3_prepare_v2(db,insert_cmd.c_str(),-1,&stmt2,NULL);
        sqlite3_bind_text(stmt2,1,category.c_str(),-1,SQLITE_TRANSIENT);
        db_check=sqlite3_step(stmt2);
        sqlite3_finalize(stmt2);
        db_check=sqlite3_close(db);
        if(db_check!=SQLITE_OK){
            cout<<"Database close failed\n";
            return -1;
        }
        return 1;
    }
    sqlite3_finalize(stmt);
    string sql_cmd="SELECT count FROM Category WHERE name=?;";
    int count=-1;
    sqlite3_stmt *stmtf;
    sqlite3_prepare_v2(db,sql_cmd.c_str(),-1,&stmtf,NULL);
    sqlite3_bind_text(stmtf,1,category.c_str(),-1,SQLITE_TRANSIENT);
    db_check=sqlite3_step(stmtf);
    if(db_check==SQLITE_ROW){
        count=sqlite3_column_int(stmtf,0);
    }
    else{
        cout<<"No data found in Number\n";
        return -1;
    }
    sqlite3_finalize(stmtf);
    if(count+add==0){
        string sql_cmd2="DELETE FROM Category WHERE name=?";
        sqlite3_stmt *stmu;
        sqlite3_prepare_v2(db,sql_cmd2.c_str(),-1,&stmu,NULL);
        sqlite3_bind_text(stmu,1,category.c_str(),-1,SQLITE_TRANSIENT);
        db_check=sqlite3_step(stmu);
        sqlite3_finalize(stmu);
        db_check=sqlite3_close(db);
        if(db_check!=SQLITE_OK){
            cout<<"Database close failed\n";
            return -1;
        }
        return 0;
    }
    string sql_cmd2="UPDATE Category SET count=? WHERE name=?;";
    sqlite3_stmt *stmu;
    sqlite3_prepare_v2(db,sql_cmd2.c_str(),-1,&stmu,NULL);
    sqlite3_bind_int(stmu,1,count+add);
    sqlite3_bind_text(stmu,2,category.c_str(),-1,SQLITE_TRANSIENT);
    db_check=sqlite3_step(stmu);
    sqlite3_finalize(stmu);
    db_check=sqlite3_close(db);
    if(db_check!=SQLITE_OK){
        cout<<"Database close failed\n";
        return -1;
    }
    return count;
}
