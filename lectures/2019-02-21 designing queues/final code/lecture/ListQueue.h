#pragma once
#ifndef LIST_QUEUE_H
#define LIST_QUEUE_H

#include "Queue.h"
#include "LinkedList.h"

template <typename T>
class ListQueue : public Queue<T>
{
private:
	LinkedList<T> _queue;

public:
	void enqueue(const T& item)
	{
		_queue.push_back(item);
	}

	T dequeue()
	{
		T item = _queue[0];
		_queue.removeAt(0);
		return item;
	}

	T& front()
	{
		return _queue[0];
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

#endif // !LIST_QUEUE_H
