#include "operation.h"

void GET_CATEGORY(string name, string category){
    if(!check_user(name)){
        cout<<"Error - unknown user"<<endl;
        return;
    }
    vector<Item*> items=get_items("category",category);
    if(items.size()!=0){
        sort(items.begin(),items.end(),[](Item* a,Item* b){
            return !compare_time(a->get_time(),b->get_time());
        });
        for(int i=0;i<(int)items.size();i++){
            cout<<items[i]->get_title()<<'|'<<items[i]->get_description()<<'|'<<items[i]->get_price()<<
            '|'<<items[i]->get_time()<<'|'<<items[i]->get_category()<<'|'<<items[i]->get_user()<<endl;
        }
    }
    else{
        cout<<"Error - category not found"<<endl;
        return;
    }
}