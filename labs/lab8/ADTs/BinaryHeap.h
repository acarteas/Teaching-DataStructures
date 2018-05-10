
#ifndef HEAP_H
#define HEAP_H

#include "Vector.h"
#include "Queue.h"
using namespace std;

template<typename T>
class BinaryHeap : Queue<T>
{
private:
    Vector<T> _items;

    void buildHeap()
    {
        for (int i = _items.getSize() / 2; i >= 0; i--)
        {
            adjustHeap(i);
        }
    }

    //Percolates the item specified at by index down into its proper location within a heap.  Used
    //for dequeue operations and array to heap conversions
    void adjustHeap(int index)
    {
        //TODO   
    }

public:
    BinaryHeap()
    {
    }

    BinaryHeap(const Vector<T> &unsorted)
    {
        for (int i = 0; i < unsorted.getSize(); i++)
        {
            _items.addElement(unsorted.getElementAt(i));
        }
        buildHeap();
    }

    bool isEmpty()
    {
        return _items.getSize() == 0;
    }

    virtual int getSize() const
    {
        return _items.getSize();
    }

    virtual void enqueue(const T &item)
    {
        //TODO:
    }

    virtual T& getFirst()
    {
        return _items[0];
    }

    virtual const T& getFirst() const
    {
        return _items[0];
    }

    virtual T dequeue()
    {
        //TODO
        return T{};
    }

};

#endif