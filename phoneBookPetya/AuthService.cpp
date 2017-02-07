#include "AuthService.h"
#include "Users.h"
#include "UserRepository.h"

Users* AuthService::LoggedUser = NULL;

AuthService::AuthService()
{
}


AuthService::~AuthService()
{
}

void AuthService::Auth(char username[30], char password[30]) {
	UserRepository* repository = new UserRepository("users.txt");
	Users* user = repository->GetUserByUsernamePass(username, password);
	AuthService::LoggedUser = user;
}

Users* AuthService::getLoggedUser(){
	
	return AuthService::LoggedUser;

}
