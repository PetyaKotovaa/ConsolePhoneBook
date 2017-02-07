#include "AdminView.h"
#include "UserManageView.h"
#include "ContactManageView.h"
#include "iostream"
using namespace std;


AdminView::AdminView()
{
}


AdminView::~AdminView()
{
}

void AdminView::Run() {

	while (true)
	{
		system("cls");
		cout << "______________________________" << endl;
		cout << "            ADMIN             " << endl;
		cout << "______________________________" << endl;

		cout << ">  [U]ser management view: " << endl;

		cout << ">  [C]ontact management view: " << endl;
		cout << "---------------------------------" << endl;
		cout << endl;
		cout << ">   E[X]it " << endl;


		cout << endl;
		cout << ">> ";

		char choice[2];
		cin.getline(choice, 2);

		switch (toupper(choice[0])) {
			
		case 'U':
		{
			UserManageView view;
			view.Run();

			break;
			
		}
		case 'C':
		{
			ContactManageView view;
			view.Run();
			break;
		}
		case 'X':
		{
			return ;
		}

		default:
		{
			cout << "Invalide choice" << endl;
			continue;
		}
		}

	}

}