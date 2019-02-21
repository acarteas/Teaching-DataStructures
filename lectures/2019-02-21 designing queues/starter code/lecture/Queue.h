#pragma once
#ifndef QUEUE_H
#define QUEUE_H

template <typename T>
class Queue
{
public:
   void enqueue(const T& item) = 0;
   T dequeue() = 0;
   T& front() = 0;
   int size() = 0;
   bool isEmpty() = 0;
};

#endif // !QUEUE_H
