#pragma once
#include "cSort.h"
class cInsertionSort :
	public cSort
{
public:
	cInsertionSort(int max = 100) : cSort(max) {}

	virtual void Sorting();
};

