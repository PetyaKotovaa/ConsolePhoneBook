#include "AuthService.h"
#include "ContactManageView.h"
#include "ContactRepository.h"
#include "Users.h"
#include "Enumerator.h"
#include "iostream"
#include "PhoneManageView.h"

using namespace std;

ContactManageView::ContactManageView()
{
}


ContactManageView::~ContactManageView()
{
}

CRUDMenuItems ContactManageView::RenderMenu() {

	while (true) {

		cout << "-----------------------" << endl;
		cout << "  CONTACT MANAGEMENT   " << endl;
		cout << "-----------------------" << endl;
		cout << " [C]reate " << endl;
		cout << " [L]ist " << endl;
		cout << " [V]iew " << endl;
		cout << " [E]dit " << endl;
		cout << " [D]elete " << endl;
		cout << " E[x]it " << endl;
		cout << "-----------------------" << endl;
		cout << endl;
		cout << ">>  ";

		char choice[2];
		cin.getline(choice, 2);
		switch (toupper(choice[0]))
		{
		case'C':
		{
			return CRUDMenuItems::Create;
		}
		case'L': 
		{
			return CRUDMenuItems::Read;
		}
		case'V': 
		{
			return CRUDMenuItems::CustomMenuItem1;
		}
		case'E': 
		{
			return CRUDMenuItems::Update;
		}
		case'D':
		{
			return CRUDMenuItems::Delete;
		}
		case'X': 
		{
			return CRUDMenuItems::Exit;
		}
		
		}
	}
}

void ContactManageView::Create() {

	system("cls");
	Contacts* item = new Contacts();
	char buff[30];
	cout << "-----------------------" << endl;
	cout << "    CREATE CONTACT     " << endl;
	cout << "-----------------------" << endl;
	item->setUserId(AuthService::getLoggedUser()->getId());

	cout << ">> First name:  ";
	cin.getline(buff, 30);
	item->setFirstContactName(buff);

	cout << ">> Last name:   " ;
	cin.getline(buff, 30);
	item->setLastContactName(buff);

	ContactRepository* repository = new ContactRepository("contacts.txt");
	repository->Add(item);

	delete repository;

	system("pause");
}

void ContactManageView::Read() {
	system("cls");

	ContactRepository* repository = new ContactRepository("contacts.txt");
	LinkedList<Contacts>* items = repository->GetAll(AuthService::getLoggedUser()->getId());

	cout << "-----------------------" << endl;
	cout << "      CONTACTS         " << endl;
	cout << "-----------------------" << endl;
	for (int i = 0; i < items->Count(); i++) {

		cout << "-------------------------" << endl;
		cout << ">> Id: " << items->getItemAt(i)->getId() << endl;
		cout << ">> User Id: " << items->getItemAt(i)->getUserId() << endl;
		cout << ">> First Name: " << items->getItemAt(i)->getFirstContactName() << endl;
		cout << ">> Last Name:  " << items->getItemAt(i)->getLastContactName() << endl;
		cout << "-------------------------" << endl;
	}

	delete repository;
	delete items;
	

	system("pause");
}

void ContactManageView::View() {

	system("cls");
	char buff[20];

	cout << "-----------------------" << endl;
	cout << "      EDIT CONTACT     " << endl;
	cout << "-----------------------" << endl;
	cout << ">> ID: ";

	cin.getline(buff, 20);
	int id = atoi(buff);

	ContactRepository* repository = new ContactRepository("contacts.txt");
	Contacts* item = repository->GetById(id);

	//system("cls");

	PhoneManageView view(item);
	view.Run();

	delete repository;
	delete item;

}

void ContactManageView::Update() {

	system("cls");
	char buff[20];

	cout << "-----------------------" << endl;
	cout << "     EDIT CONTACT      " << endl;
	cout << "-----------------------" << endl;
	cout << ">> ID: " << endl;
	cin.getline(buff, 20);
	int id = atoi(buff);

	ContactRepository* repository = new ContactRepository("contacts.txt");
	Contacts* item = repository->GetById(id);

	system("cls");
	cout << ">> First Name: ( " << item->getFirstContactName() << " ): ";
	cin.getline(buff, 20);
	item->setFirstContactName(buff);

	cout << ">> Last Name: ( " << item->getLastContactName() << " ): ";
	cin.getline(buff, 20);
	item->setLastContactName(buff);

	repository->Update(item);

	delete item;
	delete repository;

	system("pause");
}

void ContactManageView::Delete() {

	system("cls");
	char buff[20];

	cout << "-----------------------" << endl;
	cout << "      DELETE  CONTACT  " << endl;
	cout << "-----------------------" << endl;
	cout << ">> ID: " << endl;
	cin.getline(buff, 20);
	int id = atoi(buff);

	ContactRepository* repository = new ContactRepository("contacts.txt");
	Contacts* item = repository->GetById(id);

	system("cls");
	
	repository->Delete(item);
	cout << endl;
	cout << "_____________________" << endl;
	cout << "   Contact Deleted!! " << endl;
	cout << "_____________________" << endl;
	cout << endl;

	delete item;
	delete repository;
	
	system("pause");
}

void ContactManageView::Run() {
	while (true)
	{
		system("cls");
		CRUDMenuItems choice = RenderMenu();

		switch (choice)
		{

		case CRUDMenuItems::Read:
		{
			Read();
			break;
		}
		case CRUDMenuItems::CustomMenuItem1:
		{
			View();
			break;
		}
		case CRUDMenuItems::Create:
		{
			Create();
			break;
		}
		case CRUDMenuItems::Update:
		{
			Update();
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