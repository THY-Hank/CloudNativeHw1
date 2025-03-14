#include<iostream>
#include<string>
#include<sstream>
#include<vector>
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