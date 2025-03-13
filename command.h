#include<iostream>
#include<string>
#include<sstream>
#include<map>
using namespace std;
enum class OpCode {
    REGISTER,
    CREATE_LISTING,
    GET_LISTING,
    DELETE_LISTING,
    GET_CATEGORY,
    GET_TOP_CATEGORY
};
OpCode str2code(string op);
class command{
    string line;
    public:
    command(string in){
        line=in;
    }
    void process();
};