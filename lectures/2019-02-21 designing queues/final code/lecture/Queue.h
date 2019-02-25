#pragma once
#ifndef QUEUE_H
#define QUEUE_H

template <typename T>
class Queue
{
public:
   virtual void enqueue(const T& item) = 0;
   virtual T dequeue() = 0;
   virtual T& front() = 0;
   virtual int size() = 0;
   virtual bool isEmpty() = 0;
};

#endif // !QUEUE_H
