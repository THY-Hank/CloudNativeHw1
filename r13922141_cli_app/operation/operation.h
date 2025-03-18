#include "dataoperation/dataoperation.h"
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
class MainService{
    public:
    string REGISTER(string name);
    string CREATE_LISTING(string name,string title,string description,int price,string category);
    string DELETE_LISTING(string name, int id);
    string GET_LISTING(string name, int id);
    string GET_CATEGORY(string name,string category);
    string GET_TOP_CATEGORY(string name);
    void EXIT();
    void initializer();
};
bool compare_time(string a,string b);
