#include "operation/command.h"
using namespace std;
int main(){
    initializer();
    while(true){
        cout<<"# ";
        string line;
        getline(cin,line);
        command c(line);
        c.execute();
    }
    return 0;
}