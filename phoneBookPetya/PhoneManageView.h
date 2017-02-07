#pragma once
#include"Contacts.h"
#include"Enumerator.h"
class PhoneManageView
{
private: 
	Contacts* parContact;

public:
	PhoneManageView(Contacts* parContact);
	~PhoneManageView();

	CRUDMenuItems RenderMenu();

	void Add();
	void List();
	void Edit();
	void Delete();
	void Run();
};

