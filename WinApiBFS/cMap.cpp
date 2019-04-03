#include "stdafx.h"
#include "cMap.h"



cMap::~cMap()
{

}

cMap::cMap()
{
	m_mapSize = 20;
	m_map = new int*[m_mapSize];

	for (int i = 0; i < m_mapSize; ++i)
	{
		m_map[i] = new int[m_mapSize];
	}
}

void cMap::InitMap()
{
	InitOffSet();
	MakeMap();
}

void cMap::MakeMap()
{
	int map[20][20] = 
	{
		2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
2,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,2,
2,1,1,1,1,1,1,1,1,1,0,1,0,0,0,0,0,0,0,2,
2,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,2,
2,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,2,
2,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,2,
2,1,1,1,1,1,1,1,1,1,0,1,0,0,0,0,0,0,0,2,
2,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,2,
2,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,2,
2,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,2,
2,1,1,1,1,1,1,1,1,1,0,1,0,0,0,0,0,0,0,2,
2,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,2,
2,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,2,
2,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,2,
2,1,1,1,1,1,0,1,1,1,1,1,0,0,0,0,0,0,0,2,
2,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,2,
2,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,2,
2,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,2,
2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,
2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2};

	for (int i = 0; i < m_mapSize; ++i)
	{
		for (int j = 0; j < m_mapSize; ++j)
		{
			m_map[i][j] = map[i][j];
		}
	}
}

void cMap::InitOffSet()
{
	m_move[0].vert = 0; m_move[0].horiz = 1; //right
	m_move[1].vert = 1; m_move[1].horiz = 0; //down
	m_move[2].vert = 0; m_move[2].horiz =- 1; //left
	m_move[3].vert = -1; m_move[3].horiz = 0; //up
}

void cMap::DrawTile(HDC hdc, HDC hMemdc, HBITMAP hBitmap, int x, int y)
{
	HBITMAP hOldBitMap;
	hOldBitMap = (HBITMAP)SelectObject(hMemdc, hBitmap);
	BitBlt(hdc, x * 24, y * 24, 24, 24, hMemdc, 0, 0, SRCCOPY);
	SelectObject(hMemdc, hOldBitMap);
}
