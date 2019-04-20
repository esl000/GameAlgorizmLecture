#include <ctime>
#include "cSelectionSort.h"
#include "cBubbleSort.h"
#include "cInsertionSort.h"
#include "cMergeSort.h"
#include "cQuickSort.h"
#include <ctime>
#include <typeinfo> 

#define CASE_1 1000
#define CASE_2 5000
#define CASE_3 10000
#define CASE_4 50000
#define CASE_5 100000

void IsvalidData(int* dataArray, int dataSize)
{
	for (int i = 0; i < dataSize - 1; ++i)
	{
		if (dataArray[i] > dataArray[i + 1])
		{
			std::cout << "Invalid Sorting Data" << std::endl;
			return;
		}
	}
}

template<class T>
void TestSortingAlgorithm(int size)
{
	int* data = new int[size];

	for (int i = 0; i < size; ++i)
	{
		data[i] = rand(); // rand() = 0 ~ 32767
	}


	cSort* sort;
	T sortClass(size);

	std::cout << "Current Sorting Algorithm : " << typeid(sortClass).name() << " , dataSize : " << size << std::endl;

	sort = &sortClass;
	sort->InitData(data);

	clock_t startTime = clock();
	sort->Sorting();
	clock_t endTime = clock();
	double elapsedTime = (endTime - startTime);
	cout << std::fixed;
	cout.precision(10);
	std::cout << "로직 실행 시간 : " << elapsedTime << " ms" << std::endl;

	IsvalidData(sort->GetData(), sort->GetSize());
	delete[] data;
}

void TestOneCycle(int size)
{
	TestSortingAlgorithm<cSelectionSort>(size);
	TestSortingAlgorithm<cInsertionSort>(size);
	TestSortingAlgorithm<cBubbleSort>(size);
	TestSortingAlgorithm<cMergeSort>(size);
	TestSortingAlgorithm<cQuickSort>(size);
}

void main()
{
	srand(time(NULL));


	TestOneCycle(CASE_1);
	TestOneCycle(CASE_2);
	TestOneCycle(CASE_3);
	TestOneCycle(CASE_4);
	TestOneCycle(CASE_5);
}