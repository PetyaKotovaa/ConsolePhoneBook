#pragma once
#include"Users.h"
class AuthService
{
private:
	static Users* LoggedUser;
	AuthService();
public:
	static Users* getLoggedUser();
	static void Auth(char username[30],char password[30]);
	~AuthService();
};

