#include "operation.h"
void GET_TOP_CATEGORY(string name){
    if(!check_user(name)){
        cout<<"Error - unknown user"<<endl;
        return;
    }
    string cat=get_top();
    if(cat!=""){
        cout<<cat<<endl;
    }
    else{
        cout<<"Error - category not found"<<endl;
        return;
    }
}