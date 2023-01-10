#pragma once
#include "User.h"
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "message.h"
using namespace std;

class Chat
{
private:
	bool _workStatus = false; // Chat work status: "ON" - true, "OFF" - false (default is "OFF")
	std::vector<User> _users;
	std::shared_ptr<User> _currentUser = nullptr;
	std::vector<Message> messagesList_;
	void logIn();
	void signUp();
	void makeMessage();
	void readMessage();
	std::vector<Message>& getAllMessages() { return messagesList_; }
	//std::shared_ptr<User> getUsertoLogin(const std::string& login) const;
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