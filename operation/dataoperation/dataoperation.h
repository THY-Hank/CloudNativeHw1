#include<iostream>
#include<string>
#include<fstream>
#include<unordered_map>
using namespace std;
class User{
    string name;
    unordered_map<int,Item> List;
    public:
    User(string in){
        name=in;
    }
};
class Item{
    string title;
    string description;
    string creation_time;
    int price;
    string category;
    public:
    Item(string t,string d,string ct,int p,string cat){
        title=t;description=d;creation_time=ct;price=p;category=cat;
    }
};
void write_user(User user);
User read_user(string name);
bool check_user(string name);