#pragma once
#include <vector>
#include <memory>
#include "Message.h"

class Chat
{
private:
	std::vector <User> _userArray;
	std::vector <Message> _messageArray;
	std::shared_ptr <User> _currentUser = nullptr;
	bool _start = false;

	void UserLogin();              // авторизация
	void UserRegistration();      // регистрация пользователя
	void ShowChat() const;       // сообщения пользователя
	void ShowAllUsers() const;  // пользователи чата
	void AddMessage();         // создаём сообщение

	std::vector <User>& GetAllUser() { return _userArray; } //вектор хранит в себе данные зарегестрированных пользователей чата
	std::vector <Message>& GetAllMessage() { return _messageArray; } //вектор хранит в себе сообщения чата
	std::shared_ptr <User> GetUserName(const std::string& name) const;
	std::shared_ptr <User> GetUserLogin(const std::string& login) const;

public:
	void StartChat();       // вход в чат
	void ShowLoginMenu();  // меню авторизации
	void ShowUserMenu();  // меню авторизированного пользователя
	bool Move() const { return _start; }
	std::shared_ptr <User> GetCurrentUser() const { return _currentUser; }
};