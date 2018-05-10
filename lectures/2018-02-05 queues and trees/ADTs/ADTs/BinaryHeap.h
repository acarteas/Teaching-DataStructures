
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
        //presumably, the item at location index is not where it should be.
        //Store it in a temp variable for now
        T item = _items[index];

        //we need to percolate down to the bottom of our heap
        int current_size = _items.getSize();

        //loop until we've gone past the size of our vector
        while (index < current_size)
        {
            //Start by assuming that we will swap with left child.
            int child_position = index * 2 + 1;

            //are we at the end of our vector?
            if (child_position < current_size)
            {
                //check to make sure we're in bounds before performing the check below
                if (child_position + 1 < current_size)
                {
                    //is the right child smaller than the left child?
                    if (_items[child_position + 1] < _items[child_position])
                    {
                        //if so, follow the right child's branch
                        child_position++;
                    }
                }

                //is the item smaller than the smallest of our two children?
                if (item < _items[child_position])
                {
                    //if so, then we found our match and we're good to go!
                    _items[index] = item;
                    break;
                }
                else
                {
                    //The item is not smaller than its children.  Swap the smallest
                    //child with its smallest child, and update index to account for
                    //the more likely position
                    T *val = &_items[child_position];
                    _items[index] = *val;
                    index = child_position;
                }
            }
            else
            {
                //Whereever index ended up is where our original item belongs.  Set now.
                _items[index] = item;
                break;
            }
        }
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
        //add element to end of heap, then bubble up
        _items.addElement(item); 

        //indices keep track of parent / child relationship
        int current_index = _items.getSize() - 1;
        int parent_index = (current_index - 1) / 2;

        //continue to swap parent with child until parent is smaller than child
        while (parent_index > -1 && _items[parent_index] > _items[current_index])
        {
            //swap
            T temp = _items[parent_index];
            _items[parent_index] = _items[current_index];
            _items[current_index] = temp;

            //update indices
            current_index = parent_index;
            parent_index = (current_index - 1) / 2;
        }
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
        T first_item = _items[0];
        int last_position = _items.getSize() - 1;
        T last_item = _items[last_position];
        _items[0] = last_item;
        _items.removeElementAt(_items.getSize() - 1);

        //percolate down
        if (_items.getSize() > 0)
        {
            adjustHeap(0);
        }
        return first_item;
    }

};

#endif