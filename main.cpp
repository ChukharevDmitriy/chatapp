#include "Chat.h"

int main()
{
	Chat chat;

	chat.start();

	while (chat.isChatWork())
	{
		chat.showLogInMenu();

	}
	return 0;
}