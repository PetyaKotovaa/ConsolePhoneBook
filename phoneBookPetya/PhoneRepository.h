#pragma once
#include "Phones.h"
#include "LinkedLists.cpp"
class PhoneRepository
{

private:
	char filePath[50];
	int GetNextId();
public:
	PhoneRepository(char filePath[50]);
	~PhoneRepository();

	void Add(Phones* phone);
	void Update(Phones* phone);
	void Delete(Phones* phone);

	Phones* GetById(int id);
	LinkedList<Phones>* GetAll();
	LinkedList<Phones>* GetAll(int idParent);
};

