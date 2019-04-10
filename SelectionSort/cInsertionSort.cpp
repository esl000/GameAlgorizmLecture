#include "cInsertionSort.h"


void cInsertionSort::Sorting()
{
	for (int pick = 1; pick < m_dataSize; ++pick)
	{
		int current = pick, temp = m_data[pick];
		for (; current > 0 && (m_data[current - 1] > temp); --current)
			m_data[current] = m_data[current - 1];

		m_data[current] = temp;
	}

}
