#pragma once
#include <iostream>
#include <stack>
#include <queue>
#include <map>

using namespace std;


template<typename T>
class cBFS
{
public:
	cBFS() {}
	~cBFS() {}

	class cGraphClass
	{
	public:
		T _owner;
		cGraphClass** _child;
		T _childCount;

		cGraphClass() : _child(nullptr), _childCount(0) {}
		cGraphClass(T owner, cGraphClass** child, int childCount) : _owner(owner), _child(child), _childCount(childCount) {}

	};

	class cPathData
	{
	public:
		T* _pathArray;
		int _pathArrayCount;

		cPathData(T* pathArray, int pathArrayCount) : _pathArray(pathArray), _pathArrayCount(pathArrayCount) {}
	};

	static T* GetPath(cGraphClass** graph, int graphSize, T start, T end)
	{
		cGraphClass* currentNode = 0;
		int currentParent;
		std::map<T, T> parentNodes;
		std::map<T, bool> visitedNodes;
		std::queue<int> _pathFinderQueue;

		for (int i = 0; i < graphSize; ++i)
		{
			visitedNodes.insert(std::pair<T, bool>(graph[i]->_owner, false));
		}

		for (int i = 0; i < graphSize; ++i)
		{
			if (graph[i]->_owner == start)
			{
				currentNode = graph[i];
				break;
			}
		}
		parentNodes.insert(std::pair<T, T>(currentNode->_owner, currentNode->_owner));
		visitedNodes[currentNode->_owner] = true;
		currentParent = currentNode->_owner;

		bool isEndSearchingPath = false;

		while (true)
		{
			if (currentNode->_child == 0)
				break;

			for (int i = 0; i < currentNode->_childCount; ++i)
			{
				if (visitedNodes[currentNode->_child[i]->_owner] == true)
					continue;
				parentNodes.insert(std::pair<T, T>(currentNode->_child[i]->_owner, currentParent));
				_pathFinderQueue.push(currentNode->_child[i]->_owner);

				if (currentNode->_child[i]->_owner == end)
				{
					isEndSearchingPath = true;
					break;
				}
			}

			if (isEndSearchingPath == true)
				break;

			currentParent = _pathFinderQueue.front();
			_pathFinderQueue.pop();
			visitedNodes[currentParent] = true;

			for (int i = 0; i < graphSize; ++i)
			{
				if (graph[i]->_owner == currentParent)
				{
					currentNode = graph[i];
					break;
				}
			}
		}

		if (isEndSearchingPath == false)
			return 0;

		stack<T> collectPath;
		int currentPathNode = end;

		collectPath.push(currentPathNode);

		while (true)
		{
			if (parentNodes[currentPathNode] == currentPathNode)
				break;
			collectPath.push(parentNodes[currentPathNode]);
			currentPathNode = parentNodes[currentPathNode];
		}

		T* retPath = new T[collectPath.size()];
		int index = 0;

		while (!collectPath.empty())
		{
			retPath[index] = collectPath.top();
			collectPath.pop();
			index++;
		}
		
		return retPath;
	}

private:
};

class test
{
public:
	static void TestBPS()
	{
		cBFS<int>::cGraphClass** graph = new cBFS<int>::cGraphClass*[6];
		for (int i = 0; i < 6; ++i)
		{
			graph[i] = new cBFS<int>::cGraphClass();
			graph[i]->_owner = i;
		}

		graph[0]->_child = new cBFS<int>::cGraphClass*[3]{ graph[1], graph[2], graph[3] };
		graph[0]->_childCount = 3;

		graph[1]->_child = new cBFS<int>::cGraphClass*[3]{ graph[0], graph[3], graph[4] };
		graph[1]->_childCount = 3;

		graph[2]->_child = new cBFS<int>::cGraphClass*[3]{ graph[0], graph[1], graph[3] };
		graph[2]->_childCount = 3;

		graph[3]->_child = new cBFS<int>::cGraphClass*[3]{ graph[0], graph[1], graph[2] };
		graph[3]->_childCount = 3;

		graph[4]->_child = new cBFS<int>::cGraphClass*[3]{ graph[0], graph[1], graph[5] };
		graph[4]->_childCount = 3;

		graph[5]->_child = new cBFS<int>::cGraphClass*[3]{ graph[0], graph[2], graph[3] };
		graph[5]->_childCount = 3;

		cBFS<int>::GetPath(graph, 6, 0, 5);
	}
};

