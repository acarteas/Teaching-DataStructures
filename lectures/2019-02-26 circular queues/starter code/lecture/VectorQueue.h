#pragma once
#ifndef VECTOR_QUEUE_H
#define VECTOR_QUEUE_H

#include "Queue.h"
#include <vector>
using namespace std;
template <typename T>
class VectorQueue : public Queue<T>
{
private:
	vector<T> _queue;
public:

	VectorQueue()
	{
	}

	void enqueue(const T& item)
	{
		_queue.push_back(item);
	}
	T dequeue()
	{
		T item = _queue[0];
		_queue.erase(_queue.begin());
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

#endif // !VECTOR_QUEUE_H
