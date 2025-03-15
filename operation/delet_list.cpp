#include "operation.h"
void DELETE_LISTING(string name, int id){
    if(!check_user(name)){
        cout<<"Error - listing owner mismatch\n";
        return;
    }
    User r=read_user(name);
    if(!r.finditem(id)){
        cout<<"Error - listing does not exist\n";
        return;
    }
    r.eraseitem(id);
    write_user(r);
    cout<<"Success\n";
}