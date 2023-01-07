#pragma once
#include <string>
#include <iostream>

class User
{
private:
	const std::string _login;
	std::string _username;
	std::string _password;

public:
	User(const std::string& login, std::string& username, std::string& password);

	std::string getUserLogin() const;

	void setUserName(std::string& username);
	std::string getUserName() const;

	void setUserPassword(std::string& password);
	std::string getUserPassword() const;
};