#include "Chat.h"
#include "color_txt.h"
#include "message.h"
void Chat::makeMessage() {}
void Chat::readMessage(){}

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
void makeMessage() 
{
	std::string _to, _text;
	std::cout << " Напишите логин адресата" << endl;
	std::cout << " Напишите all - если для всех адресатов" << endl;
	std::cin >> _to;
	//If (getfindUsertoLogin(_to) || _to=="all") 
	//{
		//std::cout << " Напишите текст для адресата(-ов)" << endl;
		//cin.ignore();
		//getline(cin, _text);
		//messages_push_back(Message{ _currentUser->getUserLogin(), getfindUsertoLogin->getUserLogin, _text });
	//}
	//else { 
		//std::cout << RED << "Такого пользователя нет! " << RESET << endl;
		//return; }
}
void readMessage() {}


void Chat::showLogInMenu()
{
	std::cout <<YELLOW<< "*** Введите желаемую команду: ***" << std::endl;
	std::cout << "* Вход ...................... 1 *" << std::endl;
	std::cout << "* Регистрация ............... 2 *" << std::endl;
	std::cout << "* Выход из программы ........ 0 *" <<RESET<< std::endl;
	
	int userInput;
	std::cout << "> "; //Comand PROMPT
	std::cin >> userInput; //Wait user input
	std::cout << std::endl;
	switch (userInput)
	{
	case 1: 
	{	logIn();

		break; }
	case 2:
	{
		signUp();
		showUserMenu();
		break;
	}
	case 0:
	{
		_currentUser = nullptr;
		_workStatus = false; //Change work status to "OFF"
		return;
		break; }
	default:
	{
		std::cout << RED << "Вы ввели неверную команду!" << RESET << std::endl; //Error message if user input not define
		std::cout << std::endl;
		_workStatus = false; //Change work status to "OFF"
		break;
	}
	} //switch
}
std::shared_ptr<User> Chat::getCurrentUser() const
{
	return _currentUser;
}

void Chat::showUserMenu()
{
	std::cout << "*** Введите желаемую команду: ***" << std::endl;
	std::cout << "* Изменить имя .............. 1 *" << std::endl;
	std::cout << "* Изменить пароль ........... 2 *" << std::endl;
	std::cout << "* Отправить сообщение ........3 *" << std::endl;
	std::cout << "* Прочитать сообщения ........4 *" << std::endl;
	std::cout << "* Выход в предидущее меню ........ 0 *" << RESET << std::endl;

	int userInput=9;
	std::cout << "> "; //Comand PROMPT
	std::cin >> userInput; //Wait user input
	std::cout << std::endl;
	switch (userInput)
	{
	case 1:
	{
		std::cout << "Введите новое отображаемое имя пользователя:" << std::endl;
		std::string name;
		std::cout << "> "; //Comand PROMPT
		std::cin >> name; //Wait user input
		_currentUser->setUserName(name);
		break; }
	case 2:
	{
		std::cout << "Введите новый пароль:" << std::endl;
		std::string password;
		std::cout << "> "; //Comand PROMPT
		std::cin >> password; //Wait user input
		_currentUser->setUserPassword(password);
		break;
	}
	case 3:
	{
		makeMessage();
		break; }
	case 4:
	{
		readMessage();
		break; }
	case 0:
	{
		showLogInMenu();
		_workStatus = false; //Change work status to "OFF"
		break; }
	default:
	{
		std::cout << RED << "Вы ввели неверную команду!" << RESET << std::endl; //Error message if user input not define
		std::cout << std::endl;
		_workStatus = false; //Change work status to "OFF"
		break;
	}
	} //switch
}