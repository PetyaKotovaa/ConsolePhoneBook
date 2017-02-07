#include "ContactRepository.h"
#include "string.h"
#include "fstream"

using namespace std;

ContactRepository::ContactRepository(char filePath[50])
{
	strcpy_s(this->filePath, 50, filePath);

}

ContactRepository::~ContactRepository()
{
}

int ContactRepository::GetNextId() {

	int nextId = 0;
	ifstream infile(this->filePath);

	Contacts* result = NULL;
	Contacts* contact = new Contacts();

	char buff[30];

	while (!infile.eof()) 
	{

		infile.getline(buff, 30);
		contact->setId(atoi(buff));

		infile.getline(buff, 30);
		contact->setUserId(atoi(buff));

		infile.getline(buff, 30);
		contact->setFirstContactName(buff);

		infile.getline(buff, 30);
		contact->setLastContactName(buff);

		if (contact->getId() > nextId) 
		{
			nextId = contact->getId();
		}
	}

	infile.close();
	return nextId + 1;
}

void ContactRepository::Add(Contacts* contact) {

	ofstream outfile(this->filePath, ios::app);

	int id = GetNextId();

	contact->setId(id);

	outfile << contact->getId() << endl;
	outfile << contact->getUserId() << endl;
	outfile << contact->getFirstContactName() << endl;
	outfile << contact->getLastContactName() << endl;

	outfile.close();
}

void ContactRepository::Update(Contacts* contact) 
{

	ifstream infile(this->filePath);
	ofstream outfile("contact.txt", ios::app);

	Contacts* result = NULL;
	Contacts* item = new Contacts();

	char buff[30];

	while (!infile.eof()) {

		infile.getline(buff, 30);
		item->setId(atoi(buff));

		infile.getline(buff, 30);
		item->setUserId(atoi(buff));

		infile.getline(buff, 30);
		item->setFirstContactName(buff);

		infile.getline(buff, 30);
		item->setLastContactName(buff);

		if (!infile.eof() && item->getId() != contact->getId()) 
		{
			outfile << item->getId() << endl;
			outfile << item->getUserId() << endl;
			outfile << item->getFirstContactName() << endl;
			outfile << item->getLastContactName() << endl;

		}
		else if (!infile.eof() && item->getId() == contact->getId()) 
		{
			
			outfile << contact->getId() << endl;
			outfile << contact->getUserId() << endl;
			outfile << contact->getFirstContactName() << endl;
			outfile << contact->getLastContactName() << endl;

		}

	}
	infile.close();
	outfile.close();

	remove(this->filePath);
	rename("contact.txt", this->filePath);
}

void ContactRepository::Delete(Contacts* contact) {

	ifstream infile(this->filePath);
	ofstream outfile("contact.txt", ios::app);

	Contacts* result = NULL;
	Contacts* item = new Contacts();

	char buff[30];

	while (!infile.eof()) 
	{
		infile.getline(buff, 30);
		item->setId(atoi(buff));

		infile.getline(buff, 30);
		item->setUserId(atoi(buff));

		infile.getline(buff, 30);
		item->setFirstContactName(buff);

		infile.getline(buff, 30);
		item->setLastContactName(buff);

		if (!infile.eof() && item->getId() != contact->getId()) {
			outfile << item->getId() << endl;
			outfile << item->getUserId() << endl;
			outfile << item->getFirstContactName() << endl;
			outfile << item->getLastContactName() << endl;

		}
	
	}

	infile.close();
	outfile.close();

	remove(this->filePath);
	rename("contact.txt", this->filePath);
}

Contacts* ContactRepository::GetById(int id) {

	ifstream infile(this->filePath);

	Contacts* result = NULL;
	Contacts* contact = new Contacts();

	char buff[30];

	while (!infile.eof()) {
		infile.getline(buff, 30);
		contact->setId(atoi(buff));

		infile.getline(buff, 30);
		contact->setUserId(atoi(buff));

		infile.getline(buff, 30);
		contact->setFirstContactName(buff);

		infile.getline(buff, 30);
		contact->setLastContactName(buff);

		if (contact->getId() == id) {
			result = contact;
			break;
		}
	}
		infile.close();
		return result;
}

LinkedList<Contacts>* ContactRepository::GetAll() 
{

	LinkedList<Contacts>* result = new LinkedList<Contacts>();

	ifstream infile(this->filePath);

	Contacts* contact = NULL;

	char buff[30];

	while (!infile.eof()) {
		contact = new Contacts();

		infile.getline(buff, 30);
		contact->setId(atoi(buff));

		infile.getline(buff, 30);
		contact->setUserId(atoi(buff));

		infile.getline(buff, 30);
		contact->setFirstContactName(buff);

		infile.getline(buff, 30);
		contact->setLastContactName(buff);

		result->Add(contact);
	}

	infile.close();
	if (result->Count() > 0) {
		result->RemoveAt(result->Count() - 1);
	}
	return result;
}

LinkedList<Contacts>* ContactRepository::GetAll(int idParent) {
	
	LinkedList<Contacts>* result = new LinkedList<Contacts>();

	ifstream infile(this->filePath);
	Contacts* contact = NULL;

	char buff[30];

	while (!infile.eof()) {
		
		contact = new Contacts();

		infile.getline(buff, 30);
		contact->setId(atoi(buff));

		infile.getline(buff, 30);
		contact->setUserId(atoi(buff));

		infile.getline(buff, 30);
		contact->setFirstContactName(buff);

		infile.getline(buff, 30);
		contact->setLastContactName(buff);

		if (contact-> getUserId() == idParent) {
			result->Add(contact);
		}
	}
	infile.close();
	return result;
}