#include "Chat.h"

int main()
{
	Chat chat; //Create chat object

	chat.start(); //Set chat`s status is "ON"

	while (chat.isChatWork()) //Verify that chat is "ON"
	{
		chat.showLogInMenu(); //Show Log In menu

	}
	return 0;
}