#include <iostream>        
#include <vector>          
#include <string>          
#include <unordered_set>   
#include <sstream>  

#include"UserManager.h"
#include"Interface.h"
#include"User.h"



//xay dung phan mem quan ly nguoi dung co cac cuc nang register user, login, delete, search,showuser list
// co mot tai khoan master, chi co tai khoan master moi co quyen delete, showuserlist

using namespace std;



int main() {
	UserManager userm;

	while (1) {
		switch (userm.getCurrentUserRole()){
		case nobodyLogin:
			hall(userm);
			break;
		case userRole:
			isMember(userm);
			break;
		case masterRole:
			isMaster(userm);
			break;
		default:
			userm.setCurrentUserRole(nobodyLogin);
		}
	}

	return 0;
}