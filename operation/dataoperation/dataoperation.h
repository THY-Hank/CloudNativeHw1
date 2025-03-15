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