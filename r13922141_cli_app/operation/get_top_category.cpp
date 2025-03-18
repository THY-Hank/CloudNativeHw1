#include "operation.h"
void GET_TOP_CATEGORY(string name){
    if(!check_user(name)){
        cout<<"Error - unknown user"<<endl;
        return;
    }
    vector<string> cat=get_top();
    if(!cat.empty()){
        sort(cat.begin(),cat.end());
        for(int i=0;i<(int)cat.size();i++){
            cout<<cat[i]<<endl;
        }
    }
}