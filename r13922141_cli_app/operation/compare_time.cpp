#include "operation.h"
bool compare_time(string a,string b){
    if(stoi(a.substr(0,4))<stoi(b.substr(0,4))){
        return true;//year
    }
    else if(stoi(a.substr(5,2))<stoi(b.substr(5,2))){
        return true;//month
    }
    else if(stoi(a.substr(8,2))<stoi(b.substr(8,2))){
        return true;//day
    }
    else if(stoi(a.substr(11,2))<stoi(b.substr(11,2))){
        return true;//hour
    }
    else if(stoi(a.substr(14,2))<stoi(b.substr(14,2))){
        return true;//minute
    }
    else if(stoi(a.substr(17,2))<stoi(b.substr(17,2))){
        return true;//second
    }
    return false;
}