#pragma once
#include "cSort.h"
class cBubbleSort :
	public cSort
{
public:
	cBubbleSort(int max = 100) : cSort(max) {};

	virtual void Sorting();
};

