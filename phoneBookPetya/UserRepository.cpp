#include "UserRepository.h"
#include"string"
#include "fstream"

using namespace std;

UserRepository::UserRepository(char filePath[50])
{
	strcpy_s(this->filePath, 50, filePath);
}

UserRepository::~UserRepository()
{
}

int UserRepository::GetNextId() {
	
	int nextId = 0;
	ifstream infile(this->filePath);

	Users* result = NULL;
	Users* user = new Users();

	char buff[30];
	while (!infile.eof()) {

		infile.getline(buff,30);
		user->setId(atoi(buff)); //converts a string to a signed integer ! see Users.h

		infile.getline(buff, 30);
		user->setFirstName(buff);

		infile.getline(buff, 30);
		user->setLastName(buff);

		infile.getline(buff, 30);
		user->setUsername(buff);

		infile.getline(buff, 30);
		user->setPassword(buff);

		infile.getline(buff, 30); 
		user->setIsAdmin(atoi(buff)); 
		
		if (user->getId() > nextId)
			nextId = user->getId();

	}
	infile.close();
	return nextId + 1;
}

void UserRepository::Add(Users* user) {

	ofstream outfile(this->filePath, ios::app); //ATTENTION 

	int id = GetNextId();
	user->setId(id);

		outfile << user->getId() << endl;
		outfile << user->getFirstName() << endl;
		outfile << user->getLastName() << endl;
		outfile << user->getUsername() << endl;
		outfile << user->getPassword() << endl;
		outfile << user->getIsAdmin() << endl;

	outfile.close();
}

void UserRepository::Delete(Users* user) {
	
	ifstream infile(this->filePath);
	ofstream outfile("temp.txt", ios::app);

	Users* item = new Users();
	Users* result = NULL;

	char buff[30];

	while (!infile.eof()) {

		infile.getline(buff, 30);
		item->setId(atoi(buff)); //converts a string to a signed integer ! see Users.h

		infile.getline(buff, 30);
		item->setFirstName(buff);

		infile.getline(buff, 30);
		item->setLastName(buff);

		infile.getline(buff, 30);
		item->setUsername(buff);

		infile.getline(buff, 30);
		item->setPassword(buff);

		infile.getline(buff, 30);
		item->setIsAdmin(atoi(buff));

		if (!infile.eof() && item->getId() != user->getId()) {

				outfile << item->getId() << endl;
				outfile << item->getFirstName() << endl;
				outfile << item->getLastName() << endl;
				outfile << item->getUsername() << endl;
				outfile << item->getPassword() << endl;
				outfile << item->getIsAdmin() << endl;
		}

	}
		infile.close();
		outfile.close();

		remove(this->filePath);
		rename("temp.txt", this->filePath);

}

void UserRepository::Update(Users* user) {

	ifstream in(this->filePath);
	ofstream out("temp.txt", ios::app);

	Users* result = NULL;
	Users* item = new Users();

	char buffer[30];

	while (!in.eof())
	{
		in.getline(buffer, 30);
		item->setId(atoi(buffer));

		in.getline(buffer, 30);
		item->setUsername(buffer);

		in.getline(buffer, 30);
		item->setPassword(buffer);

		in.getline(buffer, 30);
		item->setFirstName(buffer);

		in.getline(buffer, 30);
		item->setLastName(buffer);

		in.getline(buffer, 30);
		item->setIsAdmin(atoi(buffer));

		if (!in.eof() && item->getId() != user->getId())
		{
			out << item->getId() << endl
				<< item->getUsername() << endl
				<< item->getPassword() << endl
				<< item->getFirstName() << endl
				<< item->getLastName() << endl
				<< item->getIsAdmin() << endl;
		}
		else if (!in.eof() && item->getId() == user->getId())
		{
			out << user->getId() << endl
				<< user->getUsername() << endl
				<< user->getPassword() << endl
				<< user->getFirstName() << endl
				<< user->getLastName() << endl
				<< item->getIsAdmin() << endl;
		}
	}

	in.close();
	out.close();

	remove(this->filePath);
	rename("temp.txt", this->filePath);
}

Users* UserRepository::GetUserByUsernamePass(char username[30], char password[30]) {

	ifstream infile(this->filePath);

	Users* result = NULL;
	Users* user = new Users();

	char buff[30];

	while (!infile.eof()) {
		infile.getline(buff, 30);
		user->setId(atoi(buff));

		infile.getline(buff, 30);
		user->setFirstName(buff);

		infile.getline(buff, 30);
		user->setLastName(buff);

		infile.getline(buff, 30);
		user->setUsername(buff);

		infile.getline(buff, 30);
		user->setPassword(buff);

		infile.getline(buff, 30);
		user->setIsAdmin(atoi(buff));

		if (strcmp(user->getUsername(), username) == 0 &&
			strcmp(user->getPassword(), password) == 0)
		{
			result = user;
			break;
		}

	}
	infile.close();
	return result;
}

Users* UserRepository::GetById(int id) {

	ifstream infile(this->filePath);

	Users* result = NULL;
	Users* user = new Users();

	char buff[30];

	while (!infile.eof())
	{

		infile.getline(buff, 30);
		user->setId(atoi(buff));

		infile.getline(buff, 30);
		user->setFirstName(buff);

		infile.getline(buff, 30);
		user->setLastName(buff);

		infile.getline(buff, 30);
		user->setUsername(buff);

		infile.getline(buff, 30);
		user->setPassword(buff);

		infile.getline(buff, 30);
		user->setIsAdmin(atoi(buff));

		if (user->getId() == id) {
			
			result = user;
			break;
		}

	}
	infile.close();
	return result;

}

LinkedList<Users>*  UserRepository::GetAll() {

	LinkedList<Users>* result = new LinkedList<Users>();
	ifstream infile(this->filePath);
	
	Users* user = NULL;

	char buff[30];
	
	while (!infile.eof()) 
	{

		user = new Users();

		infile.getline(buff, 30);
		user->setId(atoi(buff));

		infile.getline(buff, 30);
		user->setFirstName(buff);

		infile.getline(buff, 30);
		user->setLastName(buff);

		infile.getline(buff, 30);
		user->setUsername(buff);

		infile.getline(buff, 30);
		user->setPassword(buff);

		infile.getline(buff, 30);
		user->setIsAdmin(atoi(buff));

		result->Add(user);
	}
	infile.close();

	if (result->Count() > 0)
		result->RemoveAt(result->Count() - 1);
	
	return result;


}
