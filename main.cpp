#include <iostream>
#include <Windows.h>
#include "Chat.h"

int main()
{
	SetConsoleCP(1251);        // ��������� ������� �������� win-cp 1251 � ����� �����
	SetConsoleOutputCP(1251); // ��������� ������� �������� win-cp 1251 � ����� ������
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