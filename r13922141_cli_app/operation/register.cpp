#include "operation.h"
string MainService::REGISTER(string name){
    dataoperation dataservice;
    if(dataservice.check_user(name)){
        return "Error - user already existing\n";
    }
    else{
        int e=dataservice.create_user(name);
        if(e!=-1) return "Success\n";
    }
    return "NULL\n";
}