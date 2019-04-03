#pragma once
#include "cSort.h"


class cSelectionSort : public cSort
{
public:
	cSelectionSort(int max = 100) : cSort(max)
	{
	}

	virtual void Sorting();
};

