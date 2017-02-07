#pragma once
#include "Contacts.h"
#include "LinkedLists.cpp"
class ContactRepository
{

private:
	char filePath[50];
	int GetNextId();
public:
	ContactRepository(char filePath[50]);
	~ContactRepository();

	void Add(Contacts* contact);
	void Update(Contacts* contact);
	void Delete(Contacts* contact);
	Contacts* GetById(int id);
	LinkedList<Contacts>* GetAll();
	LinkedList<Contacts>* GetAll(int idParent);

};

