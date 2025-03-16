#include "operation.h"
void GET_TOP_CATEGORY(string name){
    if(!check_user(name)){
        cout<<"Error - unknown user"<<endl;
        return;
    }
    Item* item=get_top("time");
    if(item){
        cout<<item->get_category()<<endl;
    }
    else{
        cout<<"Error - category not found"<<endl;
        return;
    }
}