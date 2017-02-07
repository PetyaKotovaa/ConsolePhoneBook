#include "Phones.h"
#include "string.h"

Phones::Phones()
{
}
Phones::~Phones()
{
}

void Phones::setPhoneNumber(char phoneNumber[30]) {

	strcpy_s(this->phoneNumber, 30, phoneNumber);

}
char* Phones::getPhoneNumber() {

	return this->phoneNumber;
}

void Phones::setId(int id) {
	this->id = id;
}
int Phones::getId() {
	return this->id;

}

void Phones::setContactId(int idContact) {
	this->idContact = idContact;

}
int Phones::getContactId() {
	return this->idContact;
}