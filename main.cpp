#include "Chat.h"
#include "color_txt.h"

int main()
{
	Chat chat; //Create chat object

	chat.start(); //Set chat`s status is "ON"

	while (chat.isChatWork()) //Verify that chat is "ON"
	{
		chat.showLogInMenu(); //Show Log In menu

		while (chat.getCurrentUser())
		{
			std::cout <<GREEN<< "Добро пожаловать , " <<RESET<< chat.getCurrentUser()->getUserName() << " !" << std::endl;
			std::cout << std::endl;
			chat.showLogInMenu();
			//chat.showUserMenu();
		}
	}
	return 0;
}