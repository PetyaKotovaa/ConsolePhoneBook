#include "LoginView.h"
#include "iostream"
#include"AuthService.h"

using namespace std;

LoginView::LoginView()
{
}
LoginView::~LoginView()
{
}
void LoginView::Run(
) {

	while (true) {
		system("cls");

		char username[30];
		cout << "         LOGIN        " << endl;
		cout << "______________________" << endl;

		cout << "Username: ";
		cin.getline(username, 30);

		char password[30];
		cout << "Password: ";
		cin.getline(password, 30);

		AuthService::Auth(username, password);

		if (AuthService::getLoggedUser() != NULL) {
			break;
		}

	}


}