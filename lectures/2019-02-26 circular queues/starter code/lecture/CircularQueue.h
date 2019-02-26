#pragma once
#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H
#include <vector>
#include "Queue.h"

using namespace std;

template <typename T>
class CircularQueue : public Queue<T>
{
private:
	vector<T> _data;

	//tracks logical front, end, and size
	int _front = 0;
	int _end = 0;
	int _size = 0;

public:

	CircularQueue()
	{
	}

	virtual void enqueue(const T& item)
	{
		//are we full?
		if (_size == _data.size())
		{
			//tell physical vector to resize
			_data.resize(_data.size() * 2 + 1);

			//move end to the old physical end of the array
			_end = _size;

			for (int i = 0; i < _front; i++)
			{
				_data[_end] = _data[i];
				_end++;
			}
		}

		_data[_end] = item;
		_end = (_end + 1) % _data.size();
		_size++;
	}
	virtual T dequeue()
	{
		T item = _data[_front];

		//increment and wrap around to 0 if necessary
		_front = (_front + 1) % _data.size();

		//reduce logical size
		_size--;

		//TODO: make sure that queue is not empty before 
		//performing these operations!

		return item;
	}
	virtual T& front()
	{
		return _data[_front];
	}
	virtual int size()
	{
		return _size;
	}
	virtual bool isEmpty()
	{
		return _size == 0;
	}
};

#endif // !VECTOR_QUEUE_H
