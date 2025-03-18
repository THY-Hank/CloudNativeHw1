#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<sqlite3.h>
using namespace std;
class Item{
    int id,price;
    string user,title,description,time,category;
    public:
    void set_id(int in){
        id=in;
    }
    void set_price(int in){
        price=in;
    }
    void set_user(string in){
        user=in;
    }
    void set_title(string in){
        title=in;
    }
    void set_description(string in){
        description=in;
    }
    void set_time(string in){
        time=in;
    }
    void set_category(string in){
        category=in;
    }
    int get_id(){
        return id;
    }
    int get_price(){
        return price;
    }
    string get_user(){
        return user;
    }
    string get_title(){
        return title;
    }
    string get_description(){
        return description;
    }
    string get_time(){
        return time;
    }
    string get_category(){
        return category;
    }
};

class User{
    string name;
    vector<Item> Listings;
};
class dataoperation{
    string databasename="database.db";
    public:
    int create_user(string name);
    bool check_user(string name);
    void initialize();
    int get_new_id();
    int create_item(string name,int id,string title,string description,string time,int price,string category);
    Item* get_item(int id);
    int del_item(int id);
    vector<Item*> get_items(string condition,string input);
    vector<string> get_top();
    int cat_action(string category,int add);
};
