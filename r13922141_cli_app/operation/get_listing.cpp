#include "operation.h"
void GET_LISTING(string name, int id){
    if(!check_user(name)){
        cout<<"Error - unknown user"<<endl;
        return;
    }
    Item *item=get_item(id);
    if(item){
        cout<<item->get_title()<<'|'<<item->get_description()<<'|'<<item->get_price()<<
        '|'<<item->get_time()<<'|'<<item->get_category()<<'|'<<item->get_user()<<endl;
    }
    else{
        cout<<"Error - not found"<<endl;
        return;
    }
}