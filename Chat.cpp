#include "Chat.h"
#include "color_txt.h"

void Chat::signUp()
{
	try
	{
		std::string login;
		std::cout << "Введите login:" << std::endl;
		std::cout << "> "; //Comand PROMPT
		std::cin >> login; //Wait user input

		for (int i = 0; i < _users.size(); i++)
		{
			if (login == _users[i].getUserLogin())
			{
				throw "Такой login уже зарегистрирован!";
			}
		}

		std::string name;
		std::cout << "Введите отображаемое имя пользователя:" << std::endl;
		std::cout << "> "; //Comand PROMPT
		std::cin >> name; //Wait user input

		std::string pass;
		std::cout << "Введите пароль:" << std::endl;
		std::cout << "> "; //Comand PROMPT
		std::cin >> pass; //Wait user input

		_currentUser = std::make_shared<User>(login, name, pass);
		_users.push_back(*_currentUser);

		std::cout << GREEN <<"Пользователь успешно зарегистрирован!" <<RESET<< std::endl;
		std::cout << std::endl;
	}
	catch (const char* exception)
	{
		std::cout << std::endl;
		std::cout << exception << std::endl;
		std::cout << std::endl;
	}
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
	std::cout << "* Вход ...................... l *" << std::endl;
	std::cout << "* Регистрация ............... s *" << std::endl;
	std::cout << "* Выход из программы ........ q *" << std::endl;
	
	string userInput;
	std::cout << "> "; //Comand PROMPT
	std::cin >> userInput; //Wait user input
	std::cout << std::endl;

	if (userInput == "l")
	{
		logIn();
	}
	else if (userInput == "s")
	{
		signUp();
	}
	else if (userInput == "q")
	{
		_workStatus = false; //Change work status to "OFF"
	}
	else
	{
		std::cout << RED <<"Вы ввели неверную команду!" <<RESET << std::endl; //Error message if user input not define
		std::cout << std::endl;
	}
}

std::shared_ptr<User> Chat::getCurrentUser() const
{
	return _currentUser;
}

void Chat::showUserMenu()
{
	std::cout << "*** Введите желаемую команду: ***" << std::endl;
	std::cout << "* Изменить имя .............. n *" << std::endl;
	std::cout << "* Изменить пароль ........... p *" << std::endl;
	std::cout << "* Выход из текущей сессии ... q *" << std::endl;

	string userInput;
	std::cout << "> "; //Comand PROMPT
	std::cin >> userInput; //Wait user input
	std::cout << std::endl;

	if (userInput == "n")
	{
		std::cout << "Введите новое отображаемое имя пользователя:" << std::endl;

		std::string name;
		std::cout << "> "; //Comand PROMPT
		std::cin >> name; //Wait user input

		_currentUser->setUserName(name);
	}
	else if (userInput == "p")
	{
		std::cout << "Введите новый пароль:" << std::endl;

		std::string password;
		std::cout << "> "; //Comand PROMPT
		std::cin >> password; //Wait user input

		_currentUser->setUserPassword(password);
	}
	else if (userInput == "q")
	{
		_currentUser = nullptr;
	}
	else
	{
		std::cout << RED<<"Вы ввели невеную команду!" <<RESET<< std::endl; //Error message if user input not define
		std::cout << std::endl;
	}
}