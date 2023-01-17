#include "User.h"

User::User(const std::string& login, std::string& username, std::string& password) 
	: _login(login), _username(username), _password(password)
{
}

std::string User::getUserLogin() const
{
	return _login;
}

void User::setUserName(std::string& username)
{
	_username = username;
	std::cout << "Имя пользователя успешно изменено на " << _username << " !" << std::endl;
	std::cout << std::endl;
}

std::string User::getUserName() const
{
	return _username;
}

void User::setUserPassword(std::string& password)
{
	_password = password;
	std::cout << "Ваш пароль успешно изменен на " << _password << " !" << std::endl;
	std::cout << std::endl;
}

std::string User::getUserPassword() const
{
	return _password;
}