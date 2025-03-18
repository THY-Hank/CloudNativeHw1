#include "operation.h"
void DELETE_LISTING(string name,int id){
    Item *item=get_item(id);
    if(item==NULL){
        cout<<"Error - listing does not exist"<<endl;
        return;
    }
    if(item->get_user()!=name){
        cout<<"Error - listing owner mismatch"<<endl;
        return;
    }
    if(cat_action(item->get_category(),-1)==-1){
        cout<<"cat_action error"<<endl;
        return;
    }
    if(del_item(id)==0){
        cout<<"Success"<<endl;
    }
}