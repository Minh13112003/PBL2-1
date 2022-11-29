#pragma once
#ifndef DSLK_H
#define DSLK_H

template < class T>
struct Node
{
	T data;
	Node* Next;
	Node* Pre;
	Node(T data)
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