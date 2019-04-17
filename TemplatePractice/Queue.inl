#pragma once
#include "Queue.h"
#include <iostream>

template<class T>
inline Queue<T>::Queue() : _head(nullptr), _tail(nullptr), _size(0)
{
}

template<class T>
inline bool Queue<T>::IsEmpty()
{
	return _size == 0;
}

template<class T>
inline int Queue<T>::Size()
{
	return _size;
}

template<class T>
inline void Queue<T>::Enqueue(T item)
{
	Node* node = new Node{ item, nullptr };
	if (IsEmpty())
	{
		_head = node;
		_tail = node;
	}
	else
	{
		_tail->_next = node;
		_tail = node;
	}


	_size++;
}

template<class T>
inline T Queue<T>::Dequeue()
{
	if(IsEmpty())
		return T();

	--_size;

	Node* node = _head;
	_head = node->_next;

	T retValue = node->_data;
	delete node;

	return retValue;
}

template<class T>
inline void Queue<T>::Print()
{
	int index = 0;
	for (Node* currentNode = _head; currentNode != nullptr && index < _size; currentNode = currentNode->_next, ++index)
	{
		std::cout << currentNode->_data << std::endl;
	}

}
