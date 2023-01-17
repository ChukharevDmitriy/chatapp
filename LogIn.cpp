#include "Chat.h"
void Chat::logIn()
{
	std::string login;
	std::string pass;
	
	std::cout << "Введите login:" << std::endl;
	std::cout << "> "; //Comand PROMPT
	std::cin >> login; //Wait user input
	std::cout << "Введите пароль:" << std::endl;
	std::cout << "> "; //Comand PROMPT
	std::cin >> pass; //Wait user input
	bool n = false;// счетчик совпадений
	int k;// счетчик местоположения
	for (int i = 0; i < _users.size(); i++)
	{
		if (login == _users[i].getUserLogin())
		{
			n++; // отмечаем, что такой логин есть
			k = i;
		}
	}
	try
	{
		if (n == 0) { throw bad_sing(); }
		else if (_users[k].getUserPassword() == pass) 
		{
			std::string name = _users[k].getUserName();
			_currentUser = std::shared_ptr<User>(&_users[k]);
		}
		else if (_users[k].getUserPassword() != pass)
		{
			throw bad_sing();
		}

	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	n = 0;
	k = 0;
}

