#include "User.h"
#include <sstream>
#include <vector>

using namespace std;

User::User() {
	this->username = "";
	this->password = "";
	this->fullName = "";
}

User::User(string name, string pass, string fullName) {
	this->username = name;
	this->password = pass;
	this->fullName = fullName;
}

string User::getUserName() {
	return this->username;
}
string User::getPassWord() {
	return this->password;
}
string User::getFullName() {
	return this->fullName;
}
void standardizeName(User& u) {
	for (int i = 0; i < u.username.size(); i++) {
		u.username[i] = tolower(u.username[i]);
	}
	stringstream ss(u.fullName);
	string word, result = "";
	vector<string> v_word;
	while (ss >> word) {
		v_word.push_back(word);
	}
	for (int i = 0; i < v_word.size(); i++) {
		v_word[i][0] = toupper(v_word[i][0]);
		result = result + v_word[i] + " ";
	}
	u.fullName = result.erase(result.length() - 1);
}