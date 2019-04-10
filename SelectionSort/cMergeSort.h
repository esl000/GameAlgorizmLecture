#pragma once
#include "cSort.h"
class cMergeSort :
	public cSort
{
private:
	void Merge(int first, int middle, int last);
public:
	cMergeSort(int max) : cSort(max) {}

	virtual void Sorting();
};

