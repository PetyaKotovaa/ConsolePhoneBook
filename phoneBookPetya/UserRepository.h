#pragma once
#include "Users.h"
#include "LinkedLists.cpp"
class UserRepository
{
private:
	char filePath[50];
	int GetNextId();
public:
	UserRepository(char filePath[50]);
	~UserRepository();

	void Add(Users* user);
	void Delete(Users* user);
	void Update(Users* user);
	Users* GetUserByUsernamePass(char username[30], char password[30]);
	Users* GetById(int id);
	LinkedList<Users>* GetAll();

};

