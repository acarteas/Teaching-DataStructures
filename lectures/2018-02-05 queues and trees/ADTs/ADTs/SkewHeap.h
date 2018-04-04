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
        if (left == nullptr)
        {
            return right;
        }
        if (right == nullptr)
        {
            return left;
        }

        //default assumptions
        BinaryNode<T> *smaller = left;
        BinaryNode<T> *larger = right;
        BinaryNode<T> *to_recursive_call = left->getRightChild();

        //are these assumptions violated?
        if (left->getValue() > right->getValue())
        {
            smaller = right;
            larger = left;
            to_recursive_call = right->getRightChild();
        }

        //swap smaller's right child with left child
        BinaryNode<T> *left_child = smaller->getLeftChild();
        BinaryNode<T> *right_child = smaller->getRightChild();
        smaller->setRightChild(left_child);

        //recursively determine smaller's new left child
        BinaryNode<T> *new_left = merge(right_child, larger);

        //set left child
        smaller->setLeftChild(new_left);

        //return smaller
        return smaller;
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
        BinaryNode<T> *new_value = new BinaryNode<T>{ item };
        _root = merge(_root, new_value);
        _size++;
    }
    virtual T dequeue()
    {
        T first = _root->getValue();
        _root = merge(_root->getLeftChild(), _root->getRightChild());
        _size--;
        return first;
    }
    virtual int getSize() const
    {
        return _size;
    }
};


#endif // !SKEW_HEAP_H
