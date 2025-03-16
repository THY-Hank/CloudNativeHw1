#include "operation/command.h"
using namespace std;
int main(){
    initializer();
    while(true){
        string line;
        getline(cin,line);
        command c(line);
        c.execute();
    }
    return 0;
}