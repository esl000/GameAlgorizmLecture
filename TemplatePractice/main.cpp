#include "Queue.h"

int main()
{
	Queue<int> q;
	q.Enqueue(1);
	q.Dequeue();
	q.Enqueue(2);
	q.Enqueue(3);
	q.Dequeue();
	q.Dequeue();
	q.Enqueue(4);
	q.Enqueue(5);
	q.Enqueue(1);
	q.Enqueue(2);
	q.Enqueue(3);
	q.Enqueue(7);
	q.Print();

	return 0;
}