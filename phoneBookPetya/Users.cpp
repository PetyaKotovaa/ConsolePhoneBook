#include "Users.h"
#include "string.h"

/*
Users::Users()
{
}

Users::~Users()
{
}
*/

void Users::setId(int id) {

	this->id = id; // this-> !!!!!

}
int Users::getId()
{
	return this->id;
}


void Users::setFirstName(char firstname[30]) {
	strcpy_s(this->firstname, 30, firstname);
	//strcpy: overflow possible
	//strcpy_s: will not write more than 30 chars
}
char* Users::getFirstName() {

	return this->firstname; 
}


void Users::setLastName(char lastname[30]) {

	strcpy_s(this->lastname, 30, lastname);
}
char* Users::getLastName() {

	return this->lastname; 
}


void Users::setUsername(char username[30]) {

	strcpy_s(this->username, 30, username);
}
char* Users::getUsername() {

	return this->username;
}


void Users::setPassword(char password[30]) {

	strcpy_s(this->password, 30, password);
}
char* Users::getPassword() {

	return this->password;
}


void Users::setIsAdmin(int isAdmin) {

	this->isAdmin = isAdmin;
}
int Users::getIsAdmin() {
	
	return this->isAdmin;
}