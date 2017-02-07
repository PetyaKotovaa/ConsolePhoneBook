#pragma once
#include"string"
template<class T> class LinkedList
{
	private: 
		template<class T> class LinkedListItem {
		public:
			T*value;
			LinkedListItem* next;

			LinkedListItem(T* value) {
				
				this->value = value;
				this->next = NULL;
			}
			~LinkedListItem() {

				delete this->value;
				delete this->next;

			}
		};		
		LinkedListItem<T>* root;

public:
	LinkedList();
	~LinkedList();

	void Add(T* value);
	void RemoveAt(int index);
	T* getItemAt(int index);
	int Count();
};
