#include "operation.h"
string MainService::GET_TOP_CATEGORY(string name){
    dataoperation dataservice;
    if(!dataservice.check_user(name)){
        return "Error - unknown user\n";
    }
    vector<string> cat=dataservice.get_top();
    if(!cat.empty()){
        sort(cat.begin(),cat.end());
        string res="";
        for(int i=0;i<(int)cat.size();i++){
            res+=cat[i];
            res+="\n";
        }
        return res;
    }
    return "NULL\n";
}