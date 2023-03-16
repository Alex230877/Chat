#pragma once
#include <string>
#include <exception>

struct UserLoginException : public std::exception  //проверка от повторной регистрации
{
	const char* what() const noexcept override { return "\n Логин уже занят, введите другой! \n"; }
};

class User
{
private:
	std::string _name;
	std::string _login;
	std::string _password;

public:
	User(const std::string& login, const std::string& password, const std::string& name) : _login(login), _password(password), _name(name) {}
	const std::string& GetLogin() const { return _login; }
	const std::string& GetName() const { return _name; }
	const std::string& GetPassword() const {return _password;}

	void SetName(const std::string& name) {_name = name;}
	void SetPassword(const std::string& password) {_password = password;}
};