#pragma once


#include<iostream>
using namespace std;

class User {
private:
	string username, password;
	string fullName;
public:
	User();
	User(string name, string pass, string fullName);
	string getUserName();
	string getPassWord();
	string getFullName();
	friend void standardizeName(User& u);
};

#pragma once