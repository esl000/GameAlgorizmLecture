#include "cQuickSort.h"
#include <stack>

struct st_QuickSortCallStackData
{
public:
	int low;
	int high;
	int partition;

	int overrideNewStackCount = 0;
};

int cQuickSort::Partition(int low, int high)
{
	int j = low, pivotItem = m_data[low], temp;

	for (int i = low + 1; i <= high; ++i)
	{
		if (m_data[i] < pivotItem)
		{
			j++;
			temp = m_data[j];
			m_data[j] = m_data[i];
			m_data[i] = temp;
		}
	}

	m_data[low] = m_data[j];
	m_data[j] = pivotItem;
	return j;
}

void cQuickSort::Sorting()
{
	stack<st_QuickSortCallStackData*> callstack;
	callstack.push(new st_QuickSortCallStackData{ 0, m_dataSize - 1, 0, 0 });

	for (st_QuickSortCallStackData* activeStack = callstack.top(); activeStack != nullptr; activeStack = callstack.top())
	{
		if (activeStack->low < activeStack->high)
		{
			if (activeStack->overrideNewStackCount == 0)
			{
				activeStack->partition = Partition(activeStack->low, activeStack->high);
				callstack.push(new st_QuickSortCallStackData{ activeStack->low, activeStack->partition - 1 , 0, 0 });
				activeStack->overrideNewStackCount++;
			}
			else
			{
				callstack.pop();
				callstack.push(new st_QuickSortCallStackData{ activeStack->partition + 1, activeStack->high , 0, 0 });
				delete activeStack;
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
