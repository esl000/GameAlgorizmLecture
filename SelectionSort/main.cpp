#include <ctime>
#include "cSelectionSort.h"
#include "cBubbleSort.h"



void main()
{
	//srand(time(NULL));
	//int data[10];

	//for (int i = 0; i < 10; ++i)
	//{
	//	data[i] = rand() % 100;
	//}
	//
	//cSelectionSort sort(10);
	//sort.InitData(data);
	//sort.PrintData();
	//sort.Sorting();
	//sort.PrintData();


	srand(time(NULL));
	int data[10];

	for (int i = 0; i < 10; ++i)
	{
		data[i] = rand() % 100;
	}

	cBubbleSort sort(10);
	sort.InitData(data);
	sort.PrintData();
	sort.Sorting();
	sort.PrintData();
}