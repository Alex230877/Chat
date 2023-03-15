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

	void UserLogin();              // �����������
	void UserRegistration();      // ����������� ������������
	void ShowChat() const;       // ��������� ������������
	void ShowAllUsers() const;  // ������������ ����
	void AddMessage();         // ������ ���������

	std::vector <User>& GetAllUser() { return _userArray; } //������ ������ � ���� ������ ������������������ ������������� ����
	std::vector <Message>& GetAllMessage() { return _messageArray; } //������ ������ � ���� ��������� ����
	std::shared_ptr <User> GetUserName(const std::string& name) const;
	std::shared_ptr <User> GetUserLogin(const std::string& login) const;

public:
	void StartChat();       // ���� � ���
	void ShowLoginMenu();  // ���� �����������
	void ShowUserMenu();  // ���� ����������������� ������������
	bool Move() const { return _start; }
	std::shared_ptr <User> GetCurrentUser() const { return _currentUser; }
};