#include "operation.h"
#include<ctime>
#include<iomanip>
#include<sstream>
string gettime();
string gettime(){
    time_t times=time(NULL);
    auto tm=*localtime(&times);
    ostringstream oss;
    oss<<put_time(&tm,"%Y-%m-%d %H:%M:%S");
    return oss.str();
}
string MainService::CREATE_LISTING(string name,string title,string description,int price,string category){
    dataoperation dataservice;
    if(!dataservice.check_user(name)){
        return "Error - unknown user\n";
    }
    int id=dataservice.get_new_id();
    if(id==-1){
        return "Error\n";
    }
    string time=gettime();
    if(dataservice.create_item(name,id,title,description,time,price,category)==-1){
        return "Error\n";
    }
    if(dataservice.cat_action(category,1)==-1){
        return "cat_action error\n";
    }
    return to_string(id)+"\n";
}