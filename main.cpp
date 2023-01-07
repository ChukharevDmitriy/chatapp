#include "Chat.h"

int main()
{
	Chat chat; //Create chat object

	chat.start(); //Set chat`s status is "ON"

	while (chat.isChatWork()) //Verify that chat is "ON"
	{
		chat.showLogInMenu(); //Show Log In menu

		while (chat.getCurrentUser())
		{
			std::cout << "Добро пожаловать , " << chat.getCurrentUser()->getUserName() << " !" << std::endl;
			std::cout << std::endl;
			chat.showUserMenu();
		}
	}
	return 0;
}