#include <iostream>
#include <Windows.h>
#include "Chat.h"

int main()
{
	SetConsoleCP(1251);        // установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода
	Chat chat;
	chat.StartChat();

	while (chat.Move())
	{
	  chat.ShowLoginMenu();
		while (chat.GetCurrentUser())
		{
		  chat.ShowUserMenu();
		}
	}
	return 0;
}