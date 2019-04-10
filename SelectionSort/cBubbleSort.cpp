#include "cBubbleSort.h"


void cBubbleSort::Sorting()
{
	bool isSorted = false;

	for (int pass = 1; (pass < m_dataSize) && (!isSorted); ++pass)
	{
		isSorted = true;

		for (int current = 0; current < m_dataSize - pass; ++current)
		{
			if (m_data[current] > m_data[current + 1])
			{
				//exchange part
				int temp = m_data[current + 1];
				m_data[current + 1] = m_data[current];
				m_data[current] = temp;
				isSorted = false;
			}
		}
	}
}
