#include "DSLK.h"
#include <iostream>
using namespace std;

template <class T>
List<T>::List() {
	this->Head = this->Tail = NULL;
	this->size = 0;
}

template <class T>
List<T>::~List() {

}
template <class T,typename K>
void List<T>::InsertLast(K x) {
	Node* node = new Node(x);
	if (Head == nullptr)
	{
		this->Head = this->Tail = node;
		this->size++;
		return;
	}
	this->Tail->Next = node;
	node->Pre = this->Tail;
	this->Tail = node;
	this->size++;

}

template <typename T>
void List<T>::Show() {
	while (this!= NULL) {
		cout << this->Head->data << "";
		this->Head = this->Head->Next;
	}
}