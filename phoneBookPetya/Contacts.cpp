#include "Contacts.h"
#include "string.h"

void Contacts::setFirstContactName(char firstContactName[30]) {

	strcpy_s(this->firstContactName, 30, firstContactName);
}
char* Contacts::getFirstContactName() {
	return this->firstContactName;
}

void Contacts::setLastContactName(char lastContactName[30]) {
	strcpy_s(this->lastContactName, 30, lastContactName);
}
char* Contacts::getLastContactName() {
	return this->lastContactName;
}

void Contacts::setId(int id) {
	this->id = id;
}
int Contacts::getId() {
	return this->id;
}

void Contacts::setUserId(int userId) {
	this->userId = userId;
}
int Contacts::getUserId() {
	return this->id;
}