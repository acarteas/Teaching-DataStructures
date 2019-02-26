#pragma once
#ifndef STL_QUEUE_H
#define STL_QUEUE_H

#include "Queue.h"
#include <queue>
using namespace std;
template <typename T>
class StlQueue : public Queue<T>
{
private:
	queue<T> _queue;
public:

	StlQueue()
	{
	}

	void enqueue(const T& item)
	{
		_queue.push(item);
	}
	T dequeue()
	{
		T item = _queue.front();
		_queue.pop();
		return item;
	}
	T& front()
	{
		return _queue.front();
	}
	int size()
	{
		return _queue.size();
	}
	bool isEmpty()
	{
		return _queue.size() == 0;
	}
};

#endif // !VECTOR_QUEUE_H
