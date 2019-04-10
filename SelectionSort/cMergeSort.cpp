#include "cMergeSort.h"
#include <stack>


struct st_MergeSortCallStackData
{
public:
	int first;
	int last;
	int middle;

	int overrideNewStackCount = 0;
};

void cMergeSort::Merge(int first, int middle, int last)
{
	int* sorted = new int[last - first + 1];
	int sortedSize = last - first + 1;
	int first1 = first, last1 = middle,
		first2 = middle + 1, last2 = last;
	int index = 0;

	while (first1 <= last1 && first2 <= last2)
	{
		if (m_data[first1] < m_data[first2])
			sorted[index++] = m_data[first1++];
		else
			sorted[index++] = m_data[first2++];
	}

	for (; first1 <= last1; ++first1, ++index)
	{
		sorted[index] = m_data[first1];
	}

	for (; first2 <= last2; ++first2, ++index)
	{
		sorted[index] = m_data[first2];
	}


	for (index = 0; index < sortedSize; ++index)
	{
		m_data[first + index] = sorted[index];
	}

	delete[] sorted;
}

void cMergeSort::Sorting()
{
	stack<st_MergeSortCallStackData*> callstack;
	callstack.push(new st_MergeSortCallStackData{ 0, m_dataSize - 1, 0, 0});

	for (st_MergeSortCallStackData* activeStack = callstack.top(); activeStack != nullptr; activeStack = callstack.top())
	{
		if (activeStack->first < activeStack->last)
		{
			if (activeStack->overrideNewStackCount == 0)
			{
				activeStack->middle = (activeStack->first + activeStack->last) / 2;
				callstack.push(new st_MergeSortCallStackData{ activeStack->first, activeStack->middle , 0, 0 });
				activeStack->overrideNewStackCount++;
			}
			else if (activeStack->overrideNewStackCount == 1)
			{
				callstack.push(new st_MergeSortCallStackData{ activeStack->middle + 1, activeStack->last , 0, 0 });
				activeStack->overrideNewStackCount++;
			}
			else
			{
				Merge(activeStack->first, activeStack->middle, activeStack->last);
				delete activeStack;
				callstack.pop();
			}
		}
		else
		{
			delete activeStack;
			callstack.pop();
		}

		if (callstack.size() == 0)
			break;
	}
}
