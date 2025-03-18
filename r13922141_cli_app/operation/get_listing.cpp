#include "operation.h"
string MainService::GET_LISTING(string name, int id){
    dataoperation dataservice;
    if(!dataservice.check_user(name)){
        return "Error - unknown user\n";
    }
    Item *item=dataservice.get_item(id);
    if(item){
        string res="";
        res+=item->get_title();
        res+="|";
        res+=item->get_description();
        res+="|";
        res+=to_string(item->get_price());
        res+="|";
        res+=item->get_time();
        res+="|";
        res+=item->get_category();
        res+="|";
        res+=item->get_user();
        res+="\n";
        return res;
    }
    else{
        return "Error - not found\n";
    }
}