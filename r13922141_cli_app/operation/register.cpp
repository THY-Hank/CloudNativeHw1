#include "operation.h"
void REGISTER(string name){
    if(check_user(name)){
        cout<<"Error - user already existing\n";
    }
    else{
        int e=create_user(name);
        if(e!=-1) cout<<"Success\n";
    }
}