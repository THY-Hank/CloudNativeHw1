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
    User r=read_user(name);
    string creation_time=gettime();
    cout<<creation_time<<endl;
    if(!check_user("Manager")){
        User new_M("Manager");
        write_user(new_M);
    }
    User M=read_user("Manager");
    int id=M.get_id();
    write_user(M);
    Item newitem(id,title,description,creation_time,price,category);
    r.List_add(newitem);
    write_user(r);
    cout<<id<<endl;
}