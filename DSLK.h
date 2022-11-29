#pragma once
#ifndef DSLK_H
#define DSLK_H

template <typename T>
struct Node
{
	T data;
	Node* Next;
	Node* Pre;
	Node(T data)
	{
		this->data = data;
		this->Next = this->Pre = nullptr;
	}
};
template < class T>
class List {

private:
	int size;
	Node* Head;
	Node* Tail;

public:
	List();
	~List();
	void InsertLast(T);
	void Show();
};

#endif // !DSLK_H