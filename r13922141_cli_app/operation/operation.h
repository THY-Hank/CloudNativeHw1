#include "dataoperation/dataoperation.h"
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
void REGISTER(string name);
void CREATE_LISTING(string name,string title,string description,int price,string category);
void DELETE_LISTING(string name, int id);
void GET_LISTING(string name, int id);
void GET_CATEGORY(string name,string category);
void GET_TOP_CATEGORY(string name);
void EXIT();
void initializer();
bool compare_time(string a,string b);