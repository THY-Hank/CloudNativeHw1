#include "command.h"
OpCode str2code(string op){
    if(op=="REGISTER") return OpCode::REGISTER;
    if(op=="CREATE_LISTING") return OpCode::CREATE_LISTING;
    if(op=="GET_LISTING") return OpCode::GET_LISTING;
    if(op=="DELETE_LISTING") return OpCode::DELETE_LISTING;
    if(op=="GET_CATEGORY") return OpCode::GET_CATEGORY;
    if(op=="GET_TOP_CATEGORY") return OpCode::GET_TOP_CATEGORY;
    return OpCode::REGISTER;
}
void command::process(){
    string key,operation;
    istringstream iss(line);
    iss>>key;
    if(key!="#"){
        cout<<"Command need #\n";
        return;
    }
    iss>>operation;
    switch (str2code(operation))
    {
        case OpCode::REGISTER:
            /* code */
            cout<<"register";
            break;
        case OpCode::CREATE_LISTING:
        /* code */
            break;
        case OpCode::GET_LISTING:
        /* code */
            break;
        case OpCode::DELETE_LISTING:
        /* code */
            break;
        case OpCode::GET_CATEGORY:
        /* code */
            break;
        case OpCode::GET_TOP_CATEGORY:
        /* code */
            break;
        
        default:
            break;
    }

}