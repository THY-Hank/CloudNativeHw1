#include "operation/command.h"
using namespace std;
int main(){
    MainService service;
    service.initializer();
    while(true){
        cout<<"# ";
        string line;
        getline(cin,line);
        command c(line);
        string output=c.execute();
        cout<<output;
    }
    return 0;
}