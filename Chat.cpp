#include <iostream>
#include "Chat.h"

using namespace std;

void Chat::StartChat() 
{
	_start = true;
}

shared_ptr <User> Chat::GetUserLogin(const string& login) const
{
	for (auto& user : _userArray)
	{
		if (login == user.GetLogin())
		{
			return make_shared<User>(user);
		}
	}
	return nullptr;
}

shared_ptr <User> Chat::GetUserName(const string& name) const
{
	for (auto& user : _userArray)
	{
		if (name == user.GetName())
		{
			return make_shared<User>(user);
		}
	}
	return nullptr;
}

void Chat::UserLogin()
{
	string login, password;
	do {
		cout << "������� �����: ";
		cin >> login; // ����� ������������
		cout << "������� ������: ";
		cin >> password; // ������ ������������

		_currentUser = GetUserLogin(login);

		if (_currentUser == nullptr || password != _currentUser->GetPassword()) 
		{
			_currentUser = nullptr;
			cout << "\n �������� ����� ��� ������ \n" << endl;
				break;
		}
	} while (!_currentUser);
}

void Chat::UserRegistration()
{
	string login, password, name;
	cout << "\n ����������� ������������ \n" << endl;
	cout << "������� �����: ";
	cin >> login; 
	cout << "������� ������: ";
	cin >> password; 
	cout << "������� ���: ";
	cin >> name;

	if (GetUserLogin(login) || login == "all") // ��������
	{
		throw UserLoginException();
	}

	User user = User(login, password, name);
	_userArray.push_back(user);
	_currentUser = make_shared <User>(user);

}

void Chat::ShowUserMenu() 
{
	char menu;
	cout << "\n �����������, " << _currentUser->GetName() << ".\n" << endl;
	while (_currentUser)
	{
		cout << "1 - ��������� ���������" << endl;
		cout << "2 - �������� �������������" << endl;
		cout << "3 - �������� ���������" << endl;
		cout << "0 - �����" << endl;
		cin >> menu;

		switch (menu)
		{
		case '1':
			ShowChat();
			break;
		case '2':
			ShowAllUsers();
			break;
		case '3':
			AddMessage();
			break;
		case '0':
			cout << "\n �� ��������, " << _currentUser->GetName() << ".\n" << endl;
			_currentUser = nullptr;
			break;

		default:
			cout << "\n ������ �����! \n" << endl;
		}
	}
}

void Chat::AddMessage() 
{
	string user, text;
	cout << "\n������� ��� ������������ �������� ������ ��������� ���������, ��� �������� ���� ������������� �������� - ����: ";
	cin >> user;  // ������������
	cout << "������� ����� ���������: ";
	cin.ignore();
	getline(cin, text); // ���������

	if (!((user == "����") || GetUserName(user)))
	{
		cout << user << "\n ������������ � ������ ������ �� ������! \n"  << endl;
		return;
	}

	if (user == "����") // �������� ��������� ���� �������������
	{
		_messageArray.push_back(Message{ _currentUser->GetLogin(), "����", text });
		cout << "\n ��������� ��������� ���� �������������! \n" << endl;
	}

	else  //�������� ��������� �������������
	{
		_messageArray.push_back(Message{ _currentUser->GetLogin(), GetUserName(user)->GetLogin(), text });
		cout << "\n ��������� ����������! \n" << endl;
	}
}

void Chat::ShowLoginMenu() 
{
	_currentUser = nullptr;
	char menu;
	do
	{
		cout << " ���������� ��� \n " << endl;
		cout << "1 - ����" << endl;
		cout << "2 - �����������" << endl;
		cout << "0 - ����� �� ����" << endl;
		cin >> menu;

		switch (menu)
		{
		case '1':
			UserLogin();
			break;
		case '2':
			try
			{
				UserRegistration();
			}
			catch (const exception& excep) // ��������
			{
				cout << excep.what() << endl;
			}
			break;
		case '0':
			_start = false;
			break;

		default:
			cout << "\n ������ �����! \n" << endl;
		}
	} while (!_currentUser && _start);
}

void Chat::ShowChat() const
{
	string Sender, Recipient;
	cout << "\n ���������: \n" << endl;

	for (auto& message : _messageArray)
	{
		if (_currentUser->GetLogin() == message.GetSender() || _currentUser->GetLogin() == message.GetRecipient() || message.GetRecipient() == "����")
		{
			Sender = (_currentUser->GetLogin() == message.GetSender()) ? "����" : GetUserLogin(message.GetSender())->GetName();
		}
		if (message.GetRecipient() == "����")
		{
			Recipient = "����";
		}
		else
		{
			Recipient = (_currentUser->GetLogin() == message.GetRecipient()) ? "����" : GetUserLogin(message.GetRecipient())->GetName();
		}
		cout << "��: " << Sender << " ���: " << Recipient << endl;
		cout << "���������: " << message.GetText() << "\n" << endl;
	}
}

void Chat::ShowAllUsers() const
{
	cout << "\n ������������: \n" << endl;

	for (auto& user : _userArray)
	{
		if (_currentUser->GetLogin() == user.GetLogin()) {cout << "-> ";} // ��������� ��� ��� �������
		cout << user.GetName();
		cout <<"\n"<< endl;
	}
}