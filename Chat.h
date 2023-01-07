#pragma once
#include <iostream>
#include <string>

class Chat
{
private:
	bool _workStatus = false;

	void logIn();
	void signUp();
public:
	void start();
	bool isChatWork() const;
	void showLogInMenu();
};

