#include "cSelectionSort.h"

void cSelectionSort::Sorting()
{

	for (int last = m_dataSize - 1; last > 0; --last)
	{
		//find largestIndex part
		int lagestIndex = 0;
		for (int i = 1; i <= last; ++i)
		{
			if (m_data[i] >= m_data[lagestIndex])
				lagestIndex = i;
		}

		//exchange part
		int temp = m_data[lagestIndex];
		m_data[lagestIndex] = m_data[last];
		m_data[last] = temp;
	}
}
