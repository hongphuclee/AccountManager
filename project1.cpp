#include<bits/stdc++.h>
//xay dung phan mem quan ly nguoi dung co cac cuc nang register user, login, delete, search,
// showuser list
// co mot tai khoan master, chi co tai khoan master moi co quyen delete, showuserlist

using namespace std;
int check = 0;


void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void showNotification(){
	string tmp;
    cout << "\t\tEnter any command to exit: ";
    cin >> tmp;
}

void showNotificationContinue() {
    string tmp;
    cout << "\t\tEnter any command to continue: ";
    cin >> tmp;
}

class User {
	private:
		string username, password;
		string fullName;
	public:
		User(){
			this->username = "";
			this->password = "";
		}
		User(string name, string pass, string fullName){
			this->username = name;
			this->password = pass;
			this->fullName = fullName;
		}
		string getUserName(){
			return this->username;
		}
		string getPassWord(){
			return this->password;
		}
		string getFullName(){
			return this->fullName;
		}
		friend void standardizeName(User& u);
};

User ucl;

void standardizeName(User& u){
	for(int i = 0; i < u.username.size(); i++){
		u.username[i] = tolower(u.username[i]);
	}
	stringstream ss(u.fullName);
	string word, result = "";
	vector<string> v_word;
	while(ss >> word){
		v_word.push_back(word);
	}
	for(int i = 0; i < v_word.size(); i++){
		v_word[i][0] = toupper(v_word[i][0]);
		result = result + v_word[i] + " ";
	}
	u.fullName = result.erase(result.length() - 1);
}

class UserManager{
	private:
		string master_account = "lehongphuc";
		string master_password = "123456";
		vector<User> users;
		unordered_set<string> s_name;
	public:

		string getMasterAccount(){
			return this->master_account;
		}
		string getMasterPassWord(){
			return this->master_password;
		}
		void RegisterUser();
		void Login();
		void ShowUserList();
		void DeleteUser();
		void SearchUser();
};


void UserManager::DeleteUser(){
	clearScreen();
	string name;
	cout << "-------------------------------------------------------------------\n";
	cout << "\t\tEnter name of the account you want to delete: ";
	cin >> name;
	int i = 0;
	while(i < users.size()){
		if(users[i].getUserName() == name){
			s_name.erase(name);
			break;
		}
		i++;
	}
	clearScreen();
	if(i >= users.size()){
		cout << "-------------------------------------------------------------------\n";
		cout << "\t\tInvalid account name......\n";
		showNotification();
	}
	else{
		users.erase(users.begin() + i);
		cout << "-------------------------------------------------------------------\n";
		cout << "\t\tDelete account successfuly......\n";
		showNotificationContinue();
	}
}

void UserManager::RegisterUser(){
	clearScreen();
	string name, pass, fname;
	cout << "-------------------------------------------------------------------\n";
	cout << "\t\tEnter your user name: ";
	cin >> name;
	while(s_name.count(name)){
		clearScreen();
		cout << "-------------------------------------------------------------------\n";
		cout << "\t\tName already exists, please re-enter: ";
		cin >> name;
	}
	s_name.insert(name);
	cout << "\t\tEnter your password: ";
	cin >> pass;
	cout << "\t\tEnter your fullname: ";
	cin.ignore();
	getline(cin, fname);
	User newUser(name, pass, fname);
	standardizeName(newUser);
	users.push_back(newUser);
	clearScreen();
	cout << "-------------------------------------------------------------------\n";
	cout << "\t\tUser Register Successfully......" << endl;
	showNotificationContinue();
}

void UserManager::Login(){
	clearScreen();
	string name, pass;
	cout << "-------------------------------------------------------------------\n";
	cout << "\t\tEnter your user name: ";
	cin >> name;
	cout << "\t\tEnter you password: ";
	cin >> pass;
	clearScreen();
	if(getMasterAccount() == name && getMasterPassWord() == pass){
		cout << "-------------------------------------------------------------------\n";
		cout << "\t\tLogin Successfully............\n";
		showNotificationContinue();
		check = 2;
		return;
	}
	for(int i = 0; i < users.size(); i++){
		if(users[i].getUserName() == name && users[i].getPassWord() == pass){
			cout << "-------------------------------------------------------------------\n";
			cout << "\t\tLogin Successfully............\n";
			showNotificationContinue();
			check = 1;
			ucl = users[i];
			return;
		}
	}
	cout << "-------------------------------------------------------------------\n";
	cout << "\t\tInvalid Account or Password\n";
	showNotification();
}

void UserManager::ShowUserList(){
	clearScreen();
	if(users.size() == 0){
		cout << "-------------------------------------------------------------------\n";
		cout << "\t\tLiseUser is empty\n";
		showNotification();
	}
	else{
		cout << "-------------------------------------------------------------------\n";
		cout << "\t\tList UserName: \n";
		for(int i = 0; i < users.size(); i++){
			cout << "\t\t\t" << users[i].getUserName() << endl;
		}
		showNotificationContinue();
	}
}

void UserManager::SearchUser() {
    clearScreen();
    string keyword;
    cout << "-------------------------------------------------------------------\n";
    cout << "\t\tEnter keyword to search for user: ";
    cin >> keyword;
    clearScreen();
    bool res = false;
    cout << "-------------------------------------------------------------------\n";
    cout << "\t\tSearch result for \" " << keyword << "\""<< endl;
    for(int i = 0; i < users.size(); i++){
    	if(users[i].getUserName().find(keyword) != string::npos){
    		res = true;
    		cout << "\t\t\t" << users[i].getUserName() << endl;
		}
	}
	if(res == false){
		cout << "\t\t\t No user found matching\n";
	}
	showNotification();
}

void hall(UserManager& userm){
	clearScreen();
	cout << "-------------------------------------------------------------------\n";
	cout << "\t\t1. Register User" << endl;
	cout << "\t\t2. Login" << endl;
	cout << "\t\tEnter Your Choice: ";
	string op;
	cin >> op;
	if(op == "1"){
		userm.RegisterUser();
	}
	else if(op == "2"){
		userm.Login();
	}
	else{
		clearScreen();
		cout << "-------------------------------------------------------------------\n";
		cout << "\t\tYour selection is invalid\n";
		showNotification();
	}
}

void isMaster(UserManager& userm){
	clearScreen();
	cout << "-------------------------------------------------------------------\n";
	cout <<"\t\tWelcom Master\n\n";
	
	cout << "\t\t1. Show User List" << endl;
	cout << "\t\t2. Search User" << endl;
	cout << "\t\t3. Delete User" << endl;
	cout << "\t\t4. Logout" << endl;
	cout << "\t\tEnter Your Choice: ";
	int op;
	cin >> op;
	switch(op){
		case 1:
			userm.ShowUserList();
			break;
		case 2:
			userm.SearchUser();
			break;
		case 3:
			userm.DeleteUser();
			break;
		case 4:
			check = 0;
			break;
		default:
			clearScreen();
			cout << "-------------------------------------------------------------------\n";
			cout << "\t\tYour selection is invalid\n";
			showNotification();
			break;
	}
}

void isMember(UserManager& userm){
	clearScreen();
	cout << "-------------------------------------------------------------------\n";
	cout <<"\t\tWelcom " << ucl.getFullName() << "\n\n";
	
	cout << "\t\t1. Show User List" << endl;
	cout << "\t\t2. Search User" << endl;
	cout << "\t\t3. Logout" << endl;
	cout << "\t\tEnter Your Choice: ";
	int op;
	cin >> op;
	switch(op){
		case 1:
			clearScreen();
			cout << "-------------------------------------------------------------------\n";
			cout <<"\t\tSorry, you are not master\n";
			showNotification();
			break;
		case 2:
			userm.SearchUser();
			break;
		case 3:
			check = 0;
			break;
		default:
			clearScreen();
			cout << "-------------------------------------------------------------------\n";
			cout << "\t\tYour selection is invalid\n";
			showNotification();
			break;
	}
}

int main(){	
	UserManager userm;
	
	while(1){
		switch(check){
			case 0:
				hall(userm); 
				break;
			case 1:
				isMember(userm);
				break;	
			case 2:
				isMaster(userm);
				break;
			default:
				check = 0;
		}
	}
	
	return 0;
}
