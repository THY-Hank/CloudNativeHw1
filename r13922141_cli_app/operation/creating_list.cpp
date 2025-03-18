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
void CREATE_LISTING(string name,string title,string description,int price,string category){
    if(!check_user(name)){
        cout<<"Error - unknown user\n";
        return;
    }
    int id=get_new_id();
    if(id==-1){
        return;
    }
    string time=gettime();
    if(create_item(name,id,title,description,time,price,category)==-1){
        return;
    }
    if(cat_action(category,1)==-1){
        cout<<"cat_action error"<<endl;
        return;
    }
    cout<<id<<endl;
}