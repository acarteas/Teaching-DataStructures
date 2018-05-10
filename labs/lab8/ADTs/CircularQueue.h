#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H

#include "Queue.h"
#include "Vector.h"

/*
AC Note: This version of a circular queue is slightly different than past versions.
Thus, I am less confident in its correctness.  As always, more testing is needed.
*/
template<typename T>
class CircularQueue : public Queue<T>
{
private:

    //handles the holding of our underlying queue data
    Vector<T> _data{};

    //tracks logical front and logical end of our queue
    int _front = 0;
    int _end = 0;
    
    //because the queue can be of different size from the
    //underlying vector, we need to track the actual
    //queue size with another variable
    int _logical_size = 0;


public:

    //This constructor allows the user to specify a defalt
    //size for our underlying vector
    CircularQueue(int initial_size = 10)
    {
        _data = Vector<T>{ initial_size };
    }

    virtual T &getFirst()
    {
        return _data[_front];
    }
    virtual const T &getFirst() const
    {
        return _data[_front];
    }
    virtual void enqueue(const T &item)
    {
        //is our queue full?
        if (_logical_size == _data.getSize())
        {
            //tell our vector to resize
            _data.setSize(_logical_size * 2 + 1);

            //set end to logical size, which before the resize
            //was the physical end of our vector
            _end = _logical_size;

            //we only need to unwind when _front != 0
            for (int i = 0; i < _front; i++)
            {
                _data[_end] = _data[i];
                _end++;
            }
        }

        //add the item to the end of the queue
        _data[_end] = item;

        //increment end pointer, allowing for wrap around
        _end = (1 + _end) % _data.getSize();
        
        //increment logical size as we've grown
        _logical_size++;

    }
    virtual T dequeue()
    {
        //grab the "front" most element
        T element = _data[_front];

        //Using mod arithmetic will allow the _start pointer
        //to wrap around to the front when it goes past
        //the end of the physical vector
        _front = (_front + 1) % _data.getSize();

        //remember to decrement logical size
        _logical_size--;

        //TODO: resize if we are quarter full

        return element;
    }

    virtual int getSize() const 
    {
        return _logical_size;
    }
};

#endif