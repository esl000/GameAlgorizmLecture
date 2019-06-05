#pragma once
#include <iostream>
#include <cmath>

template<class T>
class cHeap
{
	T* _array;
	size_t _arraySize, _count;

protected:
	void GrowUpArraySize(int newSize)
	{
		if (_array == nullptr)
			_array = (T*)malloc(sizeof(T) *newSize);
		else
			_array = (T*)realloc(_array, newSize * sizeof(T));

		_arraySize = newSize;
	}

	void DownHeap(size_t index) 
	{
		int current = index;
		int child = current * 2 + 1; // lChild;

		while (child < _count)
		{
			if (child + 1 < _count)
				child = _array[child] > _array[child + 1] ? child : child + 1;
			if (_array[child] <= _array[current])
				break;

			SwapElement(child, current);
			current = child;
			child = current * 2 + 1;
		}
	}

	inline void SwapElement(size_t index1, size_t index2)
	{
		T temp = _array[index1];
		_array[index1] = _array[index2];
		_array[index2] = temp;
	}

public:
	cHeap()
		: _array(nullptr)
		, _arraySize(0)
		, _count(0)
	{

	}
	~cHeap() { delete _array; }

	void MakeHeap(T* dataArray, int arraySize)
	{
		_arraySize = arraySize;
		_count = arraySize;
		_array = dataArray;

		int depth = (int)log2((float)_count);
		
		int current = (int)(pow(2, depth) - 1);

		while (current >= 0)
		{
			DownHeap(current--);
		}
	}

	void Add(T item)
	{
		if (_arraySize == _count)
			GrowUpArraySize(_arraySize + 10);

		int current = _count;
		_array[current] = item;

		int parent = (int)((current - 1) * 0.5);

		while(current != 0 && _array[current] > _array[parent])
		{
			SwapElement(current, parent);
			current = parent;
			parent = (int)((current - 1) * 0.5);
		}

		_count++;
	}

	T Remove()
	{
		if (_count == 0)
			return T();

		T retVal = _array[0];
		_array[0] = _array[--_count];
		
		DownHeap(0);

		return retVal;
	}

	bool IsEmpty() { return _count == 0; }
};

