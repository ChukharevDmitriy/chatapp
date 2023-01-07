#pragma once
#include "User.h"
#include <iostream>
#include <string>
#include <vector>
#include <memory>

class Chat
{
private:
	bool _workStatus = false; // Chat work status: "ON" - true, "OFF" - false (default is "OFF")
	std::vector<User> _users;
	std::shared_ptr<User> _currentUser = nullptr;

	void logIn();
	void signUp();
public:
	void start(); //Change work status to "ON"
	bool isChatWork() const; //Return current work status
	void showLogInMenu(); //Show Log In menu
	std::shared_ptr<User> getCurrentUser() const;
};

