#pragma once

#include"UserManager.h"
#include<iostream>
#include<vector>
#include<unordered_set>
#include<string>

using namespace std;

void clearScreen();
void showNotification();
void showNotificationContinue();

void UI_DeleteUser(UserManager& userm);
void UI_RegisterUser(UserManager& userm);
void UI_Login(UserManager& userm);
void UI_ShowUserList(UserManager& userm);
void UI_SearchUser(UserManager& userm);

void hall(UserManager& userm);
void isMaster(UserManager& userm);
void isMember(UserManager& userm);




#pragma once
