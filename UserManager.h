#pragma once
#include<iostream>
#include<vector>
#include<unordered_set>

#include"User.h"

#define nobodyLogin 0
#define userRole 1
#define masterRole 2

using namespace std;

class UserManager {
private:
	string master_account = "lehongphuc";
	string master_password = "123456";
	vector<User> users;
	unordered_set<string> s_name;
	int currentUserRole = 0;
	User currentUser;
public:
	string getMasterAccount();
	string getMasterPassWord();
	int getCurrentUserRole();
	void setCurrentUserRole(int c);
	User getCurrentUser();
	void setCurrentUser(User u);
	bool isUserExists(string uName);
	vector<User> getUsers();

	bool RegisterUser(string uName, string pass, string fName);
	int Login(string uName, string pass);
	vector<User> ShowUserList();
	bool DeleteUser(string name);
	vector<User> SearchUser(string keyWord);
	
};



#pragma once
