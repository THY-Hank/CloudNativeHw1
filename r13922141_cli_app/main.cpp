
#include "command.h"
#include "operation/dataoperation/dataoperation.h"
using namespace std;
int main(){
    initialize();
    while(true){
        string line;
        getline(cin,line);
        command c(line);
        c.execute();
    }
    return 0;
}