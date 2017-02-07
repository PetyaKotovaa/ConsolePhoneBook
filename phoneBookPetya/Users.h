#pragma once
class Users
{
	private:
		int id;
		char firstname[30];
		char lastname[30];
		char username[30];
		char password[30];
		int isAdmin;
	public:
		/*
		Users();
		~Users();
		*/
		void setId(int id);
		int getId();

		void setFirstName(char firstname[30]);
		char* getFirstName();

		void setLastName(char lastname[30]);
		char* getLastName();

		void setUsername(char username[30]);
		char* getUsername();

		void setPassword(char password[30]);
		char* getPassword();

		void setIsAdmin(int isAdmin);
		int getIsAdmin();
};

