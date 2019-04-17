#pragma once

template<typename T>
inline void Swap(T* dataArray, int slot1, int slot2)
{
	T temp = dataArray[slot1];
	dataArray[slot1] = dataArray[slot2];
	dataArray[slot2] = temp;
}
