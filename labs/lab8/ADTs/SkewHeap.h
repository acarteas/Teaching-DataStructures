#ifndef SKEW_HEAP_H
#define SKEW_HEAP_H

#include "Queue.h"
#include "BinaryNode.h"

template <typename T>
class SkewHeap : Queue<T>
{
private:
    int _size = 0;
    BinaryNode<T> *_root = nullptr;

    BinaryNode<T>* merge(BinaryNode<T> *left, BinaryNode<T> *right)
    {
        //LAB #8 TODO: implement
        return left;
    }

public:
    SkewHeap()
    {

    }

    virtual T &getFirst()
    {
        return _root->getValue();
    }
    virtual const T &getFirst() const
    {
        return _root->getValue();
    }
    virtual void enqueue(const T &item)
    {
        //LAB #8 TODO: implement
    }
    virtual T dequeue()
    {
        //LAB #8 TODO: implement
        return T{};
    }
    virtual int getSize() const
    {
        return _size;
    }
};


#endif // !SKEW_HEAP_H
