#pragma once
#include "cSort.h"
class cQuickSort :
	public cSort
{
protected:
	int Partition(int low, int high);
public:
	cQuickSort(int max) : cSort(max) {}

	virtual void Sorting();
};

