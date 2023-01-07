#include "Chat.h"

void Chat::logIn()
{
	std::cout << "Входим" << std::endl;
	std::cout << std::endl;
}

void Chat::signUp()
{
	std::cout << "Регаемся" << std::endl;
	std::cout << std::endl;
}

void Chat::start()
{
	_workStatus = true;
}

bool Chat::isChatWork() const
{
	return _workStatus;
}

void Chat::showLogInMenu()
{
	std::cout << "*** Введите желаемую команду: ***" << std::endl;
	std::cout << "* Вход .................. login *" << std::endl;
	std::cout << "* Регистрация .......... signup *" << std::endl;
	std::cout << "* Выход из программы ..... quit *" << std::endl;
	
	std::string userInput;
	std::cout << ">";
	std::cin >> userInput;
	std::cout << std::endl;

	if (userInput == "login")
	{
		logIn();
	}
	else if (userInput == "signup")
	{
		signUp();
	}
	else if (userInput == "quit")
	{
		_workStatus = false;
	}
	else
	{
		std::cout << "Вы ввели невеную команду!" << std::endl;
		std::cout << std::endl;
	}
}
