#include "iostream"
#include "Users.h"
#include "UserRepository.h"
#include "LoginView.h"
#include "UserManageView.h"
#include "AuthService.h"
#include "AdminView.h"
#include "ContactManageView.h"

using namespace std;

int main(){
	
	AdminView adminView;
	ContactManageView contactView;
	
	LoginView loginView;
	loginView.Run();



	if (AuthService::getLoggedUser()->getIsAdmin() == 1 
		&&
		AuthService::getLoggedUser()->getIsAdmin() != NULL)
	{
		adminView.Run();

	}
	else {
		contactView.Run();
	}
	

	system("pause");
	return 0;
}

