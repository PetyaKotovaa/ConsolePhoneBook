#include "PhoneRepository.h"
#include "string.h"
#include "fstream"

using namespace std;

PhoneRepository::PhoneRepository(char filePath[50]) {

	strcpy_s(this -> filePath,50, filePath);

}

PhoneRepository::~PhoneRepository()
{
}

int PhoneRepository::GetNextId() {

	int nextId = 0;

	ifstream infile(this->filePath);

	Phones* result = NULL;
	Phones* phone = new Phones();

	char buff[30];

	while (!infile.eof()) {
		infile.getline(buff, 30);
		phone->setId(atoi(buff));

		infile.getline(buff, 30);
		phone->setContactId(atoi(buff));

		infile.getline(buff, 30);
		phone->setPhoneNumber(buff);

		if (phone->getId() > nextId) {
			nextId = phone->getId();
		}
	}

	infile.close();

	return nextId + 1;
}

void PhoneRepository::Add(Phones* phone) {
	
	ofstream outfile(this->filePath, ios::app);

	int id = GetNextId();
	phone->setId(id);

	outfile << phone->getId() << endl;
	outfile << phone->getContactId() << endl;
	outfile << phone->getPhoneNumber() << endl;

	outfile.close();
}

void PhoneRepository::Update(Phones* phone) {

	ifstream infile(this->filePath);
	ofstream outfile("contact.txt", ios::app);

	Phones* result = NULL;
	Phones* item = new Phones();

	char buff[30];

	while (!infile.eof()) {
		
		infile.getline(buff, 30);
		item->setId(atoi(buff));

		infile.getline(buff, 30);
		item->setContactId(atoi(buff));

		infile.getline(buff, 30);
		item->setPhoneNumber(buff);

		if (!infile.eof() && item->getId() != phone->getId()) {

			outfile << item->getId() << endl;
			outfile << item->getContactId() << endl;
			outfile << item->getPhoneNumber() << endl;

		}
		else if (!infile.eof() && item->getId() == phone->getId()) {


			outfile << phone->getId() << endl;
			outfile << phone->getContactId() << endl;
			outfile << phone->getPhoneNumber() << endl;
		}
	}

	infile.close();
	outfile.close();

	remove(this->filePath);
	rename("contact.txt", this->filePath);
}

void PhoneRepository::Delete(Phones* phone) {

	ifstream infile(this->filePath);
	ofstream outfile("contact.txt", ios::app);

	Phones* result = NULL;
	Phones* item = new Phones();

	char buff[30];

	while (!infile.eof()) {

		infile.getline(buff, 30);
		item->setId(atoi(buff));

		infile.getline(buff, 30);
		item->setContactId(atoi(buff));

		infile.getline(buff, 30);
		item->setPhoneNumber(buff);

		if (!infile.eof() && item->getId() != phone->getId()) {

			outfile << item->getId() << endl;
			outfile << item->getContactId() << endl;
			outfile << item->getPhoneNumber() << endl;

		}
	}
	infile.close();
	outfile.close();

	remove(this->filePath);
	rename("contact.txt", this->filePath);
}

Phones* PhoneRepository::GetById(int id) {

	ifstream infile(this->filePath);

	Phones* result = NULL;
	Phones* phone = new Phones();

	char buffer[30];

	while (!infile.eof())
	{
		infile.getline(buffer, 30);
		phone->setId(atoi(buffer));

		infile.getline(buffer, 30);
		phone->setContactId(atoi(buffer));

		infile.getline(buffer, 30);
		phone->setPhoneNumber(buffer);

		if (phone->getId() == id)
		{
			result = phone;
			break;
		}
	}

	infile.close();

	return result;
}

LinkedList<Phones>* PhoneRepository::GetAll() {

	LinkedList<Phones>* result = new LinkedList<Phones>();

	ifstream infile(this->filePath);

	Phones* phone = NULL;

	char buffer[30];

	while (!infile.eof())
	{
		phone = new Phones();

		infile.getline(buffer, 30);
		phone->setId(atoi(buffer));

		infile.getline(buffer, 30);
		phone->setContactId(atoi(buffer));

		infile.getline(buffer, 30);
		phone->setPhoneNumber(buffer);

		result->Add(phone);
	}

	infile.close();

	if (result->Count() > 0)
		result->RemoveAt(result->Count() - 1);

	return result;
}

LinkedList<Phones>* PhoneRepository::GetAll(int idParent) {

	LinkedList<Phones>* result = new LinkedList<Phones>();

	ifstream infile(this->filePath);

	Phones* phone = NULL;

	char buffer[30];

	while (!infile.eof())
	{
		phone = new Phones();

		infile.getline(buffer, 30);
		phone->setId(atoi(buffer));

		infile.getline(buffer, 30);
		phone->setContactId(atoi(buffer));

		infile.getline(buffer, 30);
		phone->setPhoneNumber(buffer);

		if (phone->getContactId() == idParent)
			result->Add(phone);
	}

	infile.close();

	return result;
}