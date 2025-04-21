#include"Interface.h"
#include<iostream>
#include<vector>
#include<string>

using namespace std;

void clearScreen() {
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
}

void showNotification() {
	string tmp;
	cout << "\t\tEnter any command to exit: ";
	cin >> tmp;
}

void showNotificationContinue() {
	string tmp;
	cout << "\t\tEnter any command to continue: ";
	cin >> tmp;
}

void UI_DeleteUser(UserManager& userm) {
	clearScreen();
	string name;
	cout << "-------------------------------------------------------------------\n";
	cout << "\t\tEnter name of the account you want to delete: ";
	cin >> name;

	clearScreen();
	if (userm.DeleteUser(name)) {
		cout << "-------------------------------------------------------------------\n";
		cout << "\t\tDelete account successfully......\n";
		showNotificationContinue();
	}
	else {
		cout << "-------------------------------------------------------------------\n";
		cout << "\t\tInvalid account name......\n";
		showNotification();
	}
}

void UI_RegisterUser(UserManager& userm) {
	clearScreen();
	string uName, passWord = " ", fName = " ";
	cout << "-------------------------------------------------------------------\n";
	cout << "\t\tEnter your user name: ";
	cin >> uName;
	while (userm.isUserExists(uName) == 1) {
		clearScreen();
		cout << "-------------------------------------------------------------------\n";
		cout << "\t\tName already exists, please re-enter: ";
		cin >> uName;
	}

	cout << "\t\tEnter your password: ";
	cin >> passWord;
	cout << "\t\tEnter your fullname: ";
	cin.ignore();
	getline(cin, fName);
	userm.RegisterUser(uName, passWord, fName); // call logic function
	clearScreen();
	cout << "-------------------------------------------------------------------\n";
	cout << "\t\tUser Register Successfully......" << endl;
	showNotificationContinue();
}

void UI_Login(UserManager& userm) {
	clearScreen();
	string uName, passWord;
	cout << "-------------------------------------------------------------------\n";
	cout << "\t\tEnter your user name: ";
	cin >> uName;
	cout << "\t\tEnter you password: ";
	cin >> passWord;
	clearScreen();
	if (userm.Login(uName, passWord)) {
		cout << "-------------------------------------------------------------------\n";
		cout << "\t\tLogin Successfully............\n";
		showNotificationContinue();
		return;
	}
	else {
		cout << "-------------------------------------------------------------------\n";
		cout << "\t\tInvalid Account or Password\n";
		showNotification();
	}
}

void UI_ShowUserList(UserManager& userm) {
	clearScreen();
	vector<User> list = userm.ShowUserList();
	if (list.size() == 0) {
		cout << "-------------------------------------------------------------------\n";
		cout << "\t\tListUser is empty\n";
		showNotification();
	}
	else {
		cout << "-------------------------------------------------------------------\n";
		cout << "\t\tList UserName: \n";
		for (int i = 0; i < list.size(); i++) {
			cout << "\t\t\t" << list[i].getUserName() << endl;
		}
		showNotificationContinue();
	}
}

void UI_SearchUser(UserManager& userm) {
	clearScreen();
	string keyWord;
	cout << "-------------------------------------------------------------------\n";
	cout << "\t\tEnter keyword to search for user: ";
	cin >> keyWord;
	vector<User> list = userm.SearchUser(keyWord);
	clearScreen();
	for (int i = 0; i < list.size(); i++) {
		if (list[i].getUserName().find(keyWord) != string::npos) {
			cout << "\t\t\t" << list[i].getUserName() << endl;
		}
	}

	if (list.size() == 0) {
		cout << "\t\t\t No user found matching\n";
	}
	showNotification();
}

void hall(UserManager& userm) {
	clearScreen();
	cout << "-------------------------------------------------------------------\n";
	cout << "\t\t1. Register User" << endl;
	cout << "\t\t2. Login" << endl;
	cout << "\t\tEnter Your Choice: ";
	string op;
	cin >> op;
	if (op == "1") {
		UI_RegisterUser(userm);
	}
	else if (op == "2") {
		UI_Login(userm);
	}
	else {
		clearScreen();
		cout << "-------------------------------------------------------------------\n";
		cout << "\t\tYour selection is invalid\n";
		showNotification();
	}
}

void isMaster(UserManager& userm) {
	clearScreen();
	cout << "-------------------------------------------------------------------\n";
	cout << "\t\tWelcom Master\n\n";

	cout << "\t\t1. Show User List" << endl;
	cout << "\t\t2. Search User" << endl;
	cout << "\t\t3. Delete User" << endl;
	cout << "\t\t4. Logout" << endl;
	cout << "\t\tEnter Your Choice: ";
	int op;
	cin >> op;
	switch (op) {
	case 1:
		UI_ShowUserList(userm);
		break;
	case 2:
		UI_SearchUser(userm);
		break;
	case 3:
		UI_DeleteUser(userm);
		break;
	case 4:
		userm.setCurrentUserRole(0);
		break;
	default:
		clearScreen();
		cout << "-------------------------------------------------------------------\n";
		cout << "\t\tYour selection is invalid\n";
		showNotification();
		break;
	}
}

void isMember(UserManager& userm) {
	clearScreen();
	cout << "-------------------------------------------------------------------\n";
	cout << "\t\tWell come " << userm.getCurrentUser().getFullName() << "\n\n";

	cout << "\t\t1. Show User List" << endl;
	cout << "\t\t2. Search User" << endl;
	cout << "\t\t3. Logout" << endl;
	cout << "\t\tEnter Your Choice: ";
	int op;
	cin >> op;
	switch (op) {
	case 1:
		clearScreen();
		cout << "-------------------------------------------------------------------\n";
		cout << "\t\tSorry, you are not master\n";
		showNotification();
		break;
	case 2:
		UI_SearchUser(userm);
		break;
	case 3:
		userm.setCurrentUserRole(0);
		break;
	default:
		clearScreen();
		cout << "-------------------------------------------------------------------\n";
		cout << "\t\tYour selection is invalid\n";
		showNotification();
		break;
	}
}

