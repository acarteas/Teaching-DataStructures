#ifndef QUEUE_H
#define QUEUE_H

//Queues allow us to insert items at the end of a collection
//and remove from the front of a collection
template <typename T>
class Queue
{
public:
	virtual T &getFirst() = 0;
    virtual const T &getFirst() const = 0;
	virtual void enqueue(const T &item) = 0;
	virtual T dequeue() = 0;
    virtual int getSize() const = 0;
};

#endif