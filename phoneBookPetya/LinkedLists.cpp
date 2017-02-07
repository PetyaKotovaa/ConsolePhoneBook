#include "LinkedLists.h"
#include "stddef.h"

template<class T>
LinkedList<T>::LinkedList() {

	this->root = NULL;
	
}


template<class T>
LinkedList<T>::~LinkedList() {

	delete this->root;
}

// add users;

template<class T>
void LinkedList<T>::Add(T* value) {

	LinkedListItem<T>* item = new LinkedListItem<T>(value);
	if (this->root == NULL) {
		this->root = item;
		return;
	}
	LinkedListItem<T>* iterator = this->root;
	while (iterator->next != NULL)
		iterator = iterator->next;
	iterator->next = item;
	
}

//removeUsers;
template<class T>
void LinkedList<T>::RemoveAt(int index) {

	LinkedListItem<T>* iterator = this->root;

	if (index == 0 && this->root->next == NULL) {

		this->root = NULL;
		return;
	}

	if (index == 0 && this->root->next != NULL) {

		this->root = this->root->next;
		return;

	}

	while (index > 1) {
		iterator = iterator->next;
		index--;
	}

	iterator->next = iterator->next->next;
}

template<class T>
T* LinkedList<T>::getItemAt(int index) 
{
	LinkedListItem<T>* iterator = this->root;

	if (index == 0)

		return this->root->value;

	while (index > 0) {

		iterator = iterator->next;
		index--;
	}
	return iterator->value;
}

template<class T>
int LinkedList<T>::Count()
{
	if (this->root == NULL)
		return 0;

	int count = 1;
	LinkedListItem<T>* iterator = this->root;

	while (iterator->next != NULL)
	{
		iterator = iterator->next;
		count++;
	}

	return count;
}
