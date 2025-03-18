#include "operation.h"
string MainService::DELETE_LISTING(string name,int id){
    dataoperation dataservice;
    Item *item=dataservice.get_item(id);
    if(item==NULL){
        return "Error - listing does not exist\n";
    }
    if(item->get_user()!=name){
        return "Error - listing owner mismatch\n";
    }
    if(dataservice.cat_action(item->get_category(),-1)==-1){
        return "cat_action error\n";
    }
    if(dataservice.del_item(id)==0){
        return "Success\n";
    }
    return "NULL\n";
}