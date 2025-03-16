#include "command.h"
#include "operation/operation.h"
OpCode str2code(string op){
    if(op=="REGISTER") return OpCode::REGISTER;
    if(op=="CREATE_LISTING") return OpCode::CREATE_LISTING;
    if(op=="GET_LISTING") return OpCode::GET_LISTING;
    if(op=="DELETE_LISTING") return OpCode::DELETE_LISTING;
    if(op=="GET_CATEGORY") return OpCode::GET_CATEGORY;
    if(op=="GET_TOP_CATEGORY") return OpCode::GET_TOP_CATEGORY;
    return OpCode::EXIT;
}
string lowercase(string in){
    transform(in.begin(),in.end(),in.begin(),::tolower);
    return in;
}
void command::process(string line){
    istringstream iss(line);
    iss>>key;
    iss>>operation;
    string s;
    while(iss>>s){
        string tmp;
        while(s[0]=='\''&&s.back()!='\''){
            iss>>tmp;
            s+=tmp;
        }
        if(s[0]=='\''){
            s.pop_back();
            s=s.substr(1);
        }
        parameter.push_back(s);
    }
}
void command::execute(){
    if(key!="#"){
        cout<<key<<endl;
        cout<<"The input should have #\n";
        return;
    }
    switch (str2code(operation))
    {
        case OpCode::REGISTER:
            REGISTER(lowercase(parameter[0]));
            break;
        case OpCode::CREATE_LISTING:
            //CREATE_LISTING(lowercase(parameter[0]),parameter[1],parameter[2],stoi(parameter[3]),parameter[4]);
            break;
        case OpCode::GET_LISTING:
            //GET_LISTING(lowercase(parameter[0]),stoi(parameter[1]));
            break;
        case OpCode::DELETE_LISTING:
            //DELETE_LISTING(lowercase(parameter[0]),stoi(parameter[1]));
            break;
        case OpCode::GET_CATEGORY:
            //GET_CATEGORY(lowercase(parameter[0]),parameter[1]);
            break;
        case OpCode::GET_TOP_CATEGORY:
            //GET_TOP_CATEGORY(lowercase(parameter[0]));
            break;
        case OpCode::EXIT:
            //EXIT();
            break;
        default:
            cout<<"Wrong command!\n";
            break;
    }
}