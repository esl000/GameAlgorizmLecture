#include "cHeap.h"

int main()
{
	int* arr = new int[10]{ 1, 2, 30, 4, 5 ,60, 7, 8, 90, 10 };

	cHeap<int> heap;
	heap.MakeHeap(arr, 10);
	heap.Add(50);
	heap.Add(11);
	heap.Add(31);
	heap.Add(24);
	heap.Add(27);
	heap.Add(74);
	heap.Add(59);
	heap.Add(118);
	heap.Add(71);

	while (!heap.IsEmpty())
	{
		std::cout << heap.Remove() << "\t";
	}

	std::cout << std::endl;

	return 0;
}