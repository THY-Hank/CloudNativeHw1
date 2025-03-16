#include "operation.h"
#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<cctype>
#include<algorithm>
using namespace std;
enum class OpCode {
    REGISTER,
    CREATE_LISTING,
    GET_LISTING,
    DELETE_LISTING,
    GET_CATEGORY,
    GET_TOP_CATEGORY,
    EXIT
};
string lowercase(string in);
OpCode str2code(string op);
class command{
    private:
    string key,operation;
    vector<string> parameter;
    public:
    command(string in){
        process(in);
    }
    void process(string line);
    void execute();
};