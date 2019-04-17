#include <ctime>
#include "cSelectionSort.h"
#include "cBubbleSort.h"
#include "cInsertionSort.h"
#include "cMergeSort.h"
#include "cQuickSort.h"



void main()
{

	srand(time(NULL));
	int data[10];

	for (int i = 0; i < 10; ++i)
	{
		data[i] = rand() % 100;
	}

	//cInsertionSort sort(10);
	//sort.InitData(data);
	//sort.PrintData();
	//sort.Sorting();
	//sort.PrintData();

	//cMergeSort sort(10);
	//sort.InitData(data);
	//sort.PrintData();
	//sort.Sorting();
	//sort.PrintData();

	cQuickSort sort(10);
	sort.InitData(data);
	sort.PrintData();
	sort.Sorting();
	sort.PrintData();
}