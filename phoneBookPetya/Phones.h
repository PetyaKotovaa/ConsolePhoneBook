#pragma once
class Phones
{
private:
	char phoneNumber[30];
	int id;
	int idContact;
public:
	Phones();
	~Phones();

	void setId(int id);
	int getId();

	void setPhoneNumber(char phoneNumber[30]);
	char* getPhoneNumber();

	void setContactId(int contactId);
	int getContactId();

};

