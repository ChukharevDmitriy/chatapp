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
	std::cout << "> "; //Comand PROMPT
	std::cin >> userInput; //Wait user input
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
		_workStatus = false; //Change work status to "OFF"
	}
	else
	{
		std::cout << "Вы ввели невеную команду!" << std::endl; //Error message if user input not define
		std::cout << std::endl;
	}
}
