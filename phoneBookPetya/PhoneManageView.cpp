#include "PhoneManageView.h"
#include "AuthService.h"
#include "PhoneRepository.h"
#include "Users.h"
#include "Enumerator.h"
#include "iostream"

using namespace std;
PhoneManageView::PhoneManageView(Contacts* parContact)
{
	this->parContact = parContact;

}


PhoneManageView::~PhoneManageView()
{
}

CRUDMenuItems PhoneManageView::RenderMenu() {

	while (true)
	{

		cout << "-----------------------" << endl;
		cout << "   CONTACT INFO        " << endl;
		cout << "-----------------------" << endl;
		cout << endl;
		cout << ">> First Name: " << this->parContact->getFirstContactName() << endl;
		cout << ">> Last Name: " << this->parContact->getLastContactName() << endl;

		cout << "-----------------------" << endl;
		cout << "   PHONE MANAGEMENT    " << endl;
		cout << "-----------------------" << endl;
		cout << "    [C]reate: " << endl;
		cout << "    [L]ist:" << endl;
		cout << "    [U]pdate:" << endl;
		cout << "    [D]elete: " << endl;
		cout << "    E[X]it" << endl;
		cout << "--------------------" << endl;
		cout << endl;
		cout << ">>  ";

		char choice[2];
		cin.getline(choice, 2);

		switch (toupper(choice[0]))
		{
		case 'C':
		{
			return CRUDMenuItems::Create;
		}
		case 'L':
		{
			return CRUDMenuItems::Read;
		}
		case 'U':
		{
			return CRUDMenuItems::Update;
		}
		case 'D':
		{
			return CRUDMenuItems::Delete;
		}
		case 'X':
		{
			return CRUDMenuItems::Exit;
		}
		}
	}
}

void PhoneManageView::Add() {

	system("cls");

	Phones* item = new Phones();
	char buffer[30];

	cout << "-----------------------" << endl;
	cout << "    ADD PHONE          " << endl;
	cout << "-----------------------" << endl;

	item->setContactId(this->parContact->getId());

	cout << ">> Phone number:  ";
	cin.getline(buffer, 30);
	item->setPhoneNumber(buffer);

	PhoneRepository* repository = new PhoneRepository("phones.txt");
	repository->Add(item);

	delete repository;

	system("pause");

}

void PhoneManageView::List() {

	system("cls");

	PhoneRepository* repository = new PhoneRepository("phones.txt");
	LinkedList<Phones>* items = repository->GetAll(this->parContact->getId());

	cout << "-----------------------" << endl;
	cout << "    CONTACT LIST       " << endl;
	cout << "-----------------------" << endl;
	for (int i = 0; i < items->Count(); i++) {

		cout << "----------------------" << endl;
		cout << ">> Id: " << items->getItemAt(i)->getId() << endl;
		cout << ">> Contact ID: " << items->getItemAt(i)->getContactId() << endl;
		cout << ">> Phone Number: " << items->getItemAt(i)->getPhoneNumber() << endl;

	}

	delete items;
	delete repository;

	system("pause");

}

void PhoneManageView::Delete() {
	system("cls");

	char buff[30];
	cout << "-----------------------" << endl;
	cout << "       DELETING        " << endl;
	cout << "-----------------------" << endl;
	cout << endl;
	cout << ">> ID:  "; 
	
	cin.getline(buff,30);
	int id = atoi(buff);
	
	PhoneRepository* repository = new PhoneRepository("phones.txt");
	Phones* item = repository->GetById(id);

	system("cls");

	repository->Delete(item);
	cout << "-----------------------" << endl;
	cout << "Phone deleted!!!" << endl;
	cout << "-----------------------" << endl;

	cout << endl;
	delete item;
	delete repository;
	system("pause");
	
}

void PhoneManageView::Run() {
	while (true)
	{
		system("cls");
		CRUDMenuItems choice = RenderMenu();

		switch (choice)
		{
		case CRUDMenuItems::Read:
		{
			List();
			break;
		}
		case CRUDMenuItems::Create:
		{
			Add();
			break;
		}
		case CRUDMenuItems::Update:
		{
			Edit();
			break;
		}
		case CRUDMenuItems::Delete:
		{
			Delete();
			break;
		}
		case CRUDMenuItems::Exit:
		{
			return;
		}
		default:
		{
			cout << "Invalid choice";
			continue;
		}
		}
	}
}

void PhoneManageView::Edit() {

	system("cls");

	char buff[30];

	cout << "-----------------------" << endl;
	cout << "       EDITING         " << endl;
	cout << "-----------------------" << endl;
	cout << "Id: ";

	cin.getline(buff, 30);

	int id = atoi(buff);

	PhoneRepository* repository = new PhoneRepository("phones.txt");
	Phones* item = repository->GetById(id);

	system("cls");

	cout << ">> Phone number (" << item->getPhoneNumber() << " ): ";

	cin.getline(buff, 30);
	item->setPhoneNumber(buff);

	repository->Update(item);

	delete item;
	delete repository;

	system("pause");
}
