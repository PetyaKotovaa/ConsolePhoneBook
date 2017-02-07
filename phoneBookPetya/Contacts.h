#pragma once
class Contacts
{
private:
		char firstContactName[30];
		char lastContactName[30];
		int id;
		int userId;
public:


	void setFirstContactName(char firstContactName[30]);
	char* getFirstContactName();

	void setLastContactName(char lastContactName[30]);
	char* getLastContactName();

	void setId(int id);
	int getId();
	
	void setUserId(int id);
	int getUserId();



};

