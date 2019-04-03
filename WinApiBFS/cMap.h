#pragma once

struct offset
{
	int vert;
	int horiz;
};


enum TileStyle {BLANK, OBJECT, WALL, GONE, PLAYER
};


class cMap
{
	int** m_map;
	int m_mapSize;
public:
	~cMap();
	cMap();

	offset m_move[4];
	cMap(int mapSize) : m_mapSize(mapSize) {
		m_map = new int*[mapSize];

		for (int i = 0; i < mapSize; ++i)
		{
			m_map[i] = new int[mapSize];
		}
	}

	void InitMap();
	void MakeMap();
	void InitOffSet();
	void DrawTile(HDC hdc, HDC hMemdc, HBITMAP hBitmap, int x, int y);

	int GetMapSize() { return m_mapSize; }
	int GetMapInfo(int x, int y) { return m_map[y][x]; }
	int GetMapInfo(int x, int y, int val) {  m_map[y][x] = val; }
};

