#include "operation.h"
void REGISTER(string name){
    User newuser(name);
    if(check_user(name)){
        cout<<"Error - user already existing\n";
    }
    else{
        write_user(newuser);
        cout<<"Success\n";
    }
}