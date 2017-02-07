#include "UserManageView.h"
#include "UserRepository.h"
#include "UserS.h"
#include "Enumerator.h"
#include "iostream"

using namespace std;

UserManageView::UserManageView()
{
}

UserManageView::~UserManageView()
{
}

CRUDMenuItems UserManageView::RenderMenu() {

	while (true) {
		cout << "--------------------" << endl;
		cout << "  USER MANAGEMENT  " << endl;
		cout << "--------------------" << endl;
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

		switch(toupper(choice[0])) 
		{

				case'C': {

					return CRUDMenuItems::Create;

				}
				case'L': {

					return CRUDMenuItems::Read;

				}
				case'U': {

					return CRUDMenuItems::Update;

				}
				case'D': {

					return CRUDMenuItems::Delete;

				}
				case'X': {

					return CRUDMenuItems::Exit;

				}
		}
	}
}

void UserManageView::Create() {

	
	system("cls");

	Users* user = new Users();
	char buff[30];

	cout << "--------------------" << endl;
	cout << "     ADD USER  " << endl;
	cout << "--------------------" << endl;
	
	cout << ">> First name:   >> ";
	cin.getline(buff, 30);
	user->setFirstName(buff);
	cout << endl;
	
	cout << ">> Last name:   >> ";
	cin.getline(buff, 30);
	user->setLastName(buff);
	cout << endl;
	
	cout << ">> Username:   >> ";
	cin.getline(buff, 30);
	user->setUsername(buff);
	cout << endl;
	
	cout << ">> Password:   >> ";
	cin.getline(buff, 30);
	user->setPassword(buff);
	cout << endl;
	
	cout << ">> Admin:   >> ";
	cin.getline(buff, 30);
	user->setIsAdmin(atoi(buff));
	cout << endl;

	UserRepository* repository = new UserRepository("users.txt");
	repository->Add(user);
	delete repository;

	system("pause");

}

void UserManageView::Read() {

	system("cls");

	UserRepository* repository = new UserRepository("users.txt");
	LinkedList<Users>* item = repository->GetAll();

		cout << "--------------------" << endl;
		cout << "       Users        " << endl;
		cout << "--------------------" << endl;
	for (int i = 0; i < item->Count(); i++)
	{
		cout << "--------------------" << endl;

		cout << ">> ID:  "<< item->getItemAt(i)->getId() << endl;
		cout << ">> First Name:  " << item->getItemAt(i)->getFirstName() << endl;
		cout << ">> Last Name:  " << item->getItemAt(i)->getLastName() << endl;
		cout << ">> Username:  " << item->getItemAt(i)->getUsername() << endl;
		cout << ">> Password:  " << item->getItemAt(i)->getPassword() << endl;
		cout << ">> Is Admin:  " << item->getItemAt(i)->getIsAdmin() << endl;

		cout << "--------------------" << endl;
	}
	delete item;
	delete repository;
	system("pause");
}

void UserManageView::Update() {

	system("cls");

	char buff[30];
	int id;
	
	cout << "--------------------" << endl;
	cout << "       Editing       " << endl;
	cout << "--------------------" << endl;
	cout << ">> ID: ";
	cin.getline(buff, 30);
	id = atoi(buff);

	UserRepository* repository = new UserRepository("users.txt");
	Users* user = repository->GetById(id);

	system("cls");
	
	cout << "--------------------" << endl;
	cout << "     Editing User   " << endl;
	cout << "--------------------" << endl;

	cout << ">> First Name: " << user->getFirstName() << " -> change to: ";
	cin.getline(buff, 30);
	user->setFirstName(buff);

	cout << ">> Last Name: " << user->getLastName() << " -> change to: ";
	cin.getline(buff, 30);
	user->setLastName(buff);

	cout << ">> Username: " << user->getUsername() << " -> change to: ";
	cin.getline(buff, 30);
	user->setUsername(buff);

	cout << ">> Password: " << user->getPassword() << " -> change to: ";
	cin.getline(buff, 30);
	user->setPassword(buff);

	cout << ">> Is admin: " << user->getIsAdmin() << " -> change to: ";
	cin.getline(buff, 30);
	user->setIsAdmin(atoi(buff));

	repository->Update(user);

	delete user;
	delete repository;

	system("pause");
}

void UserManageView::Delete() {

	system("cls");
	char buff[30];

	cout << "--------------------" << endl;
	cout << "    Deleting user   " << endl;
	cout << "--------------------" << endl;
	cout << ">> ID: ";

	cin.getline(buff, 30);
	int id = atoi(buff);

	UserRepository* repository = new UserRepository("users.txt");
	Users* user = repository->GetById(id);
	
	system("cls");
	repository->Delete(user);

	cout << "--------------------" << endl;
	cout << "   User deleted     " << endl;
	cout << "--------------------" << endl;

	delete user;
	delete repository;

	system("pause");
}

void UserManageView::Run()
{
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
			return ;
		}
		default:
		{
			cout << "Invalid choice";
			continue;
		}
		}
	}
}