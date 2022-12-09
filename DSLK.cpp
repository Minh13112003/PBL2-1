#include <iostream>
#include "Hanghoa.h"
using namespace std;

template < class T>
struct Node
{
public:
	T data;
	Node* Next;
	Node* Pre;
	Node(T data);
};


template < class T>
class List {

private:
	int size;
	Node<T>* Head;
	Node<T>* Tail;

public:
	List();
	~List();
	void InsertLast(T);
	void Show();
	int LinearSearch(T);
};




template <class T>
Node<T>::Node(T data) {
	this->data = data;
	this->Next = this->Pre = NULL;
}

template <class T>
List<T>::List() {
	this->Head = this->Tail = NULL;
	this->size = 0;
}

template <class T>
List<T>::~List() {

}
template <class T>
void List<T>::InsertLast(T x) {
	Node<T>* node = new Node<T>(x);
	if (Head == nullptr)
	{
		this->Head = this->Tail = node;
		this->size++;
		return;
	}
	node->Pre = this->Tail;
	this->Tail->Next = node;
	this->Tail = node;
	this->size++;

}

template <class T>
int List<T>::LinearSearch(T data) {
	int temp = 0;
	Node<T>* a = this->Head;
	while (a != NULL) {
		if (a->data == data) {
			return temp;
		}
		temp++;
		a = a->Next;
	}
	return -1;
}

template <class T>
void List<T>::Show() {
	Node <T> *a = NULL;
	a = this->Head;
	while (a != NULL) {
		a->data.show();
		a = a->Next;
	}
}