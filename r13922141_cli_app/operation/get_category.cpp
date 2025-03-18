#include "operation.h"

string MainService::GET_CATEGORY(string name, string category){
    dataoperation dataservice;
    if(!dataservice.check_user(name)){
        return "Error - unknown user\n";
    }
    vector<Item*> items=dataservice.get_items("category",category);
    if(items.size()!=0){
        sort(items.begin(),items.end(),[](Item* a,Item* b){
            return !compare_time(a->get_time(),b->get_time());
        });
        string res="";
        for(int i=0;i<(int)items.size();i++){
            
            res+=items[i]->get_title();
            res+="|";
            res+=items[i]->get_description();
            res+="|";
            res+=to_string(items[i]->get_price());
            res+="|";
            res+=items[i]->get_time();
            res+="|";
            res+=items[i]->get_category();
            res+="|";
            res+=items[i]->get_user();
            res+="\n";
        }
        return res;
    }
    else{
        return "Error - category not found\n";
    }
    return "NULL\n";
}