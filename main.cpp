
#include "command.h"
using namespace std;
int main(){
    
    while(true){
        string line;
        getline(cin,line);
        command c(line);
        c.execute();
    }
    return 0;
}