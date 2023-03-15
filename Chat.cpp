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
		cout << "Введите логин: ";
		cin >> login; // логин пользователя
		cout << "Введите пароль: ";
		cin >> password; // пароль пользователя

		_currentUser = GetUserLogin(login);

		if (_currentUser == nullptr || password != _currentUser->GetPassword()) 
		{
			_currentUser = nullptr;
			cout << "\n Неверный логин или пароль \n" << endl;
				break;
		}
	} while (!_currentUser);
}

void Chat::UserRegistration()
{
	string login, password, name;
	cout << "\n Регистрация пользователя \n" << endl;
	cout << "Введите логин: ";
	cin >> login; 
	cout << "Введите пароль: ";
	cin >> password; 
	cout << "Введите имя: ";
	cin >> name;

	if (GetUserLogin(login) || login == "all") // проверка
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
	cout << "\n Здраствуйте, " << _currentUser->GetName() << ".\n" << endl;
	while (_currentUser)
	{
		cout << "1 - Прочитать сообщения" << endl;
		cout << "2 - Просмотр пользователей" << endl;
		cout << "3 - Написать сообщение" << endl;
		cout << "0 - Выйти" << endl;
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
			cout << "\n До свидания, " << _currentUser->GetName() << ".\n" << endl;
			_currentUser = nullptr;
			break;

		default:
			cout << "\n Ошибка ввода! \n" << endl;
		}
	}
}

void Chat::AddMessage() 
{
	string user, text;
	cout << "\nВведите имя пользователя которому хотите отправить сообщение, для отправки всем пользователям наберите - всем: ";
	cin >> user;  // пользователь
	cout << "Введите текст сообщения: ";
	cin.ignore();
	getline(cin, text); // сообщение

	if (!((user == "всем") || GetUserName(user)))
	{
		cout << user << "\n Пользователь с данным именем не найден! \n"  << endl;
		return;
	}

	if (user == "всем") // отправка сообщения всем пользователям
	{
		_messageArray.push_back(Message{ _currentUser->GetLogin(), "всем", text });
		cout << "\n Сообщение разослано всем пользователям! \n" << endl;
	}

	else  //отправка сообщения полльзователю
	{
		_messageArray.push_back(Message{ _currentUser->GetLogin(), GetUserName(user)->GetLogin(), text });
		cout << "\n Сообщение отправлено! \n" << endl;
	}
}

void Chat::ShowLoginMenu() 
{
	_currentUser = nullptr;
	char menu;
	do
	{
		cout << " Консольный ЧАТ \n " << endl;
		cout << "1 - Вход" << endl;
		cout << "2 - Регистрация" << endl;
		cout << "0 - Выход из чата" << endl;
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
			catch (const exception& excep) // проверка
			{
				cout << excep.what() << endl;
			}
			break;
		case '0':
			_start = false;
			break;

		default:
			cout << "\n Ошибка ввода! \n" << endl;
		}
	} while (!_currentUser && _start);
}

void Chat::ShowChat() const
{
	string Sender, Recipient;
	cout << "\n Сообщения: \n" << endl;

	for (auto& message : _messageArray)
	{
		if (_currentUser->GetLogin() == message.GetSender() || _currentUser->GetLogin() == message.GetRecipient() || message.GetRecipient() == "всем")
		{
			Sender = (_currentUser->GetLogin() == message.GetSender()) ? "меня" : GetUserLogin(message.GetSender())->GetName();
		}
		if (message.GetRecipient() == "всем")
		{
			Recipient = "всем";
		}
		else
		{
			Recipient = (_currentUser->GetLogin() == message.GetRecipient()) ? "меня" : GetUserLogin(message.GetRecipient())->GetName();
		}
		cout << "От: " << Sender << " Для: " << Recipient << endl;
		cout << "Сообщение: " << message.GetText() << "\n" << endl;
	}
}

void Chat::ShowAllUsers() const
{
	cout << "\n Пользователи: \n" << endl;

	for (auto& user : _userArray)
	{
		if (_currentUser->GetLogin() == user.GetLogin()) {cout << "-> ";} // указатель под кем зайдено
		cout << user.GetName();
		cout <<"\n"<< endl;
	}
}