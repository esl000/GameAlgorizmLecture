#pragma once

template<class T>
class Queue
{
	class Node
	{
	public:
		T _data;
		Node* _next;
	};


	Node* _head;
	Node* _tail;
	int _size;

public:

	Queue();

	bool IsEmpty();
	int Size();

	void Enqueue(T item);
	T Dequeue();

	void Print();
};

#include "Queue.inl"

