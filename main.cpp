
#include "command.h"
using namespace std;
//g++ main.cpp -o test 
int main(){
    
    while(true){
        string line;
        getline(cin,line);
        command c(line);
        c.process();

    }
    return 0;
}