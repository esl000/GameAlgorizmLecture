// STL_Map.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
#include <map>
#include <functional>
#include <cassert>
#include <string>
#include <iostream>
using namespace std;

struct Item
{
	string name;
	char kind;
	int buyMoney;
	int skillCd;
};

int main()
{
	map<string, Item> items;
	map<string, Item>::iterator iterPos;

	Item Item1 = { "긴칼", 1, 200, 0 };
	Item Item2 = { "성스러운 방패", 2, 1000, 4 };
	Item Item3 = { "해머", 1, 500, 0 };


	items.insert(map<string, Item>::value_type(Item2.name, Item2));
	items.insert(pair<string, Item>(Item1.name, Item1));

	cout << "오름차순" << endl;

	for (iterPos = items.begin(); iterPos != items.end(); ++iterPos)
	{
		cout << "이름: " << iterPos->first << ", 가격: " <<
			iterPos->second.buyMoney << endl;
	}

	iterPos = items.find("긴칼");

	assert(iterPos != items.end());

	cout << "이름: " << iterPos->first << ", 가격: " <<
		iterPos->second.buyMoney << endl << endl;

	cout << "내림차순" << endl;

	map<string, Item, greater<string>> items2;
	map<string, Item, greater<string>>::iterator iterPos2;

	items2.insert(map<string, Item, greater<string>>::value_type(Item2.name, Item2));
	items2.insert(pair<string, Item>(Item1.name, Item1));

	items2[Item3.name] = Item3;

	for (iterPos2 = items2.begin(); iterPos2 != items2.end(); ++iterPos2)
	{
		cout << "이름: " << iterPos2->first << ", 가격: " <<
			iterPos2->second.buyMoney << endl;
	}

	iterPos2 = items2.find("긴칼");

	if (iterPos2 != items2.end())
		items2.erase(iterPos2);

	cout << "count : " << items2.size() << endl;

}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
