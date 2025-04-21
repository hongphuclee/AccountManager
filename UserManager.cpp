#include"UserManager.h"
#include<iostream>
#include<vector>
#include<unordered_set>
#include<string>

using namespace std;


int UserManager::getCurrentUserRole() {
	return this->currentUserRole;
}

void UserManager::setCurrentUserRole(int c) {
	this->currentUserRole = c;
}

User UserManager::getCurrentUser() {
	return this->currentUser;
}

void UserManager::setCurrentUser(User u) {
	this->currentUser = u;
}

string UserManager::getMasterAccount() {
	return this->master_account;
}
string UserManager::getMasterPassWord() {
	return this->master_password;
}

vector<User> UserManager::getUsers() {
	return this->users;
}

bool UserManager::RegisterUser(string uName, string pass, string fName) {
	if (s_name.count(uName)) {
		return false;
	}
	s_name.insert(uName);;
	User newUser(uName, pass, fName);
	standardizeName(newUser);
	users.push_back(newUser);
	return true;
}

int UserManager::Login(string uName, string pass) {
	if (getMasterAccount() == uName && getMasterPassWord() == pass) {
		setCurrentUserRole(masterRole); 
		return masterRole;
	}
	for (int i = 0; i < users.size(); i++) {
		if (users[i].getUserName() == uName && users[i].getPassWord() == pass) {
			setCurrentUserRole(userRole);
			setCurrentUser(users[i]);
			return userRole;
		}
	}
	return 0;
}

bool UserManager::DeleteUser(string name) {
	int i = 0;
	while (i < users.size()) {
		if (users[i].getUserName() == name) {
			s_name.erase(name);
			break;
		}
		i++;
	}
	if (i >= users.size()) {
		return false;
	}
	else {
		users.erase(users.begin() + i);
		return true;
	}
}

vector<User> UserManager::ShowUserList() {
	vector<User> res;
	for (int i = 0; i < users.size(); i++) {
		res.push_back(users[i]);
	}
	return res;
}

vector<User> UserManager::SearchUser(string keyWord) {
	vector<User> res;
	for (int i = 0; i < users.size(); i++) {
		if (users[i].getUserName().find(keyWord) != string::npos) {
			res.push_back(users[i]);
		}
	}
	return res;
}

bool UserManager::isUserExists(string uName) {
	if (s_name.count(uName)) {
		return true;
	}
	return false;
}




