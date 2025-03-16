#include<iostream>
#include<string>
#include<fstream>
#include<unordered_map>
#include<sqlite3.h>
using namespace std;
#define databasename "database.db"
int create_user(string name);
// int read_user(string name);
bool check_user(string name);
void initialize();
int get_new_id();
int create_item(string name,int id,string title,string description,string time,int price,string category);