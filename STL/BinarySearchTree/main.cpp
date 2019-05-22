#include <iostream>

using namespace std;


template<class T>
class BinaryTree
{
public :

	struct Node
	{
	public:
		T item;
		Node* lChild, *rChild;

		Node() : lChild(0), rChild(0) {};
		Node(T _item) : item(_item), lChild(0), rChild(0) {};
	};

	Node* _head;

	BinaryTree() : _head(0) {}

	void Insert(T item)
	{
		if (!_head)
		{
			_head = new Node(item);
			return;
		}
		
		Node* curNode = _head;

		while (true)
		{
			if (curNode->item > item)
			{
				if (!curNode->lChild)
				{
					curNode->lChild = new Node(item);
					return;
				}

				curNode = curNode->lChild;
			}
			else
			{
				if (!curNode->rChild)
				{
					curNode->rChild = new Node(item);
					return;
				}

				curNode = curNode->rChild;
			}
		}
	}

	Node* Search(T item, Node** itemPreNode = 0)
	{
		Node* curNode = _head;

		while (true)
		{
			if (!curNode)
				break;

			if (curNode->item == item)
				return curNode;

			if (itemPreNode)
				*itemPreNode = curNode;

			if (curNode->item > item)
				curNode = curNode->lChild;
			else
				curNode = curNode->rChild;

		}

		return 0;
	}

	void Delete(T item)
	{
		Node* delNodeParent = 0;
		Node* delNode = Search(item, &delNodeParent);

		if (!delNode)
			return;

		if (!delNode->lChild && !delNode->rChild)
		{
			SwapLink(delNodeParent, delNode, NULL);
			delete delNode;
		}
		else if(delNode->lChild && !delNode->rChild)
		{
			SwapLink(delNodeParent, delNode, delNode->lChild);
			delete delNode;
		}
		else if (!delNode->lChild && delNode->rChild)
		{
			SwapLink(delNodeParent, delNode, delNode->rChild);
			delete delNode;
		}
		else
		{
			Node** culNode = &(delNode->rChild);

			while (true)
			{
				if (!(*culNode)->lChild)
				{
					delNode->item = (*culNode)->item;
					Node* Temp = *culNode;
					*culNode = (*culNode)->rChild;
					delete Temp;
					return;
				}
				else
					culNode = &((*culNode)->lChild);
			}
		}
	}

	void PreOrderPrint()
	{
		PreOrder(_head);
	}

	void InOrderPrint()
	{
		InOrder(_head);
	}

	void PostOrderPrint()
	{
		PostOrder(_head);
	}

private:

	void SwapLink(Node* parent, Node* delNode, Node* newNode)
	{
		if (parent->lChild == delNode)
			parent->lChild = newNode;
		else
			parent->rChild = newNode;
	}

	void PreOrder(Node* p)
	{
		if (p != NULL) {
			cout << p->item << "\t";
			PreOrder(p->lChild);
			PreOrder(p->rChild);
		}
	}

	void InOrder(Node* p)
	{
		if (p != NULL) {
			InOrder(p->lChild);
			cout << p->item << "\t";
			InOrder(p->rChild);
		}
	}

	void PostOrder(Node* p)
	{
		if (p != NULL) {
			PostOrder(p->lChild);
			PostOrder(p->rChild);
			cout << p->item << "\t";
		}
	}
};


int main()
{
	BinaryTree<int> tree;

	tree.Insert(6);
	tree.Insert(3);
	tree.Insert(9);
	tree.Insert(2);
	tree.Insert(4);
	tree.Insert(5);
	tree.Insert(7);
	tree.Insert(8);
	tree.Insert(11);

	tree.PreOrderPrint();
	cout << endl;
	tree.InOrderPrint();
	cout << endl;
	tree.PostOrderPrint();
	cout << endl;

	tree.Delete(2);
	tree.Delete(6);

	tree.PreOrderPrint();
	cout << endl;

	return 0;
}
