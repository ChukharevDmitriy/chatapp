#pragma once
#include "User.h"
#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;

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
	void showUserMenu(); //Show User menu
};
class bad_sing : public exception
{
public:
	virtual const char* what() const noexcept override
	{
		return "неверный логин или пароль";
		cout << endl;
	}
};