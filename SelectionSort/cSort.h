#pragma once
#include <cassert>
#include <iostream>
using namespace std;

class cSort
{
protected:
	int* m_data;
	int m_dataSize;
public:
	cSort(int max = 100) : m_dataSize(max)
	{
		m_data = new int[max];
		assert(m_data != nullptr);
	}
	~cSort()
	{
		if (m_data)
			delete[] m_data;
	}

	void InitData(int* data)
	{
		for (int i = 0; i < m_dataSize; i++)
			m_data[i] = data[i];
	}

	int GetSize() { return m_dataSize; }
	int* GetData() { return m_data; }

	virtual void Sorting() = 0;

	void PrintData()
	{
		for (int i = 0; i < m_dataSize; i++)
			cout << m_data[i] << endl;

		cout << endl;
	}
};

