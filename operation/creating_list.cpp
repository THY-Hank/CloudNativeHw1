#include "operation.h"
#include<ctime>
#include<iomanip>
#include<sstream>
void CREATE_LISTING(string name,string title,string description,int price,string category){
    //User r=read_user(name);
    cout<<name<<' '<<title<<' '<<description<<' '<<price<<' '<<category<<endl;
    time_t times=time(NULL);
    auto tm=*localtime(&times);
    string creation_time;
    ostringstream oss;
    oss<<put_time(&tm,"%Y-%m-%d %H:%M:%S");
    creation_time=oss.str();
    cout<<creation_time<<endl;
    //Item newitem(title,description,creation_time,price,category);
}