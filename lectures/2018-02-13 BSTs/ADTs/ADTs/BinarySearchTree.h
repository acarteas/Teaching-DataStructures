#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include "Collection.h"
#include "BinaryNode.h"
#include "TreeTraversal.h"

//This is an interface.  An interface does not have any
//concrete implementation.
template <typename T>
class BinarySearchTree : public Collection<T>
{
protected:

    BinaryNode<T> *_root = nullptr;
    int _size = 0;

    //helper function for add element recursive call
    virtual BinaryNode<T>* addElementHelper(BinaryNode<T> *node, 
        const T& item)
    {
        
    }

	//find the largest node in the supplied subtree headed by *node
	BinaryNode<T> *findLargest(BinaryNode<T> *node)
	{
		while (node != nullptr && node->getRightChild() != nullptr)
		{
			node = node->getRightChild();
		}
		return node;
	}

    BinaryNode<T>* removeElementHelper(BinaryNode<T> *node,
        const T& item)
    {
        //base case #1: null (not found)
        if (node == nullptr)
        {
            return nullptr;
        }
        //base case #2: found
        else if (node->getValue() == item)
        {
            //possible configurations of our node
            //1: no children
            //2: 1 child
            //3: 2 children
            if (node->getLeftChild() == nullptr &&
                node->getRightChild() == nullptr)
            {
                delete node;
                return nullptr;
            }
            else if (node->getLeftChild() == nullptr ||
                node->getRightChild() == nullptr)
            {
                BinaryNode<T> *good_child = node->getLeftChild();
                if (good_child == nullptr)
                {
                    good_child = node->getRightChild();
                }
                delete node;
                return good_child;
            }
            else
            {
                //TODO: remove with 2 children
				//step 1: find the largest value in the LST
				BinaryNode<T> *largest = findLargest(node->getLeftChild());

				//step 2: have the current node assume the value of
				//        this largest value
				node->setValue(largest->getValue());

				//step 3: delete the largest value in the LST
				node->setLeftChild(removeElementHelper(
					node->getLeftChild(), 
					largest->getValue()
					));
            }

        }
        //recursive case: not the item we're looking for
        else
        {
            if (item > node->getValue())
            {
                //note: recursive call to right side might result
                //in a reconfiguration.  We need to capture this and
                //update our child accordingly
                BinaryNode<T> *result = removeElementHelper(node->getRightChild(), item);
                node->setRightChild(result);
            }
            else
            {
                BinaryNode<T> *result = removeElementHelper(
                    node->getLeftChild(),
                    item
                );
                node->setLeftChild(result);
            }
        }
		return node;
    }

public:

#pragma region Collection implementation

    virtual void addElement(const T& item)
    {
        _root = addElementHelper(_root, item);
        _size++;
    }
    virtual void removeElement(const T& item)
    {
		_root = removeElementHelper(_root, item);
    }
    virtual bool containsElement(const T& item) const
    {
        //iterative version of tree traversal
        BinaryNode<T> *current = _root;
        while (current != nullptr)
        {
            //have we found our value?
            if (current->getValue() == item)
            {
                return true;
            }
            else if (item < current->getValue())
            {
                //examine left-hand side of the tree
                current = current->getLeftChild();
            }
            else
            {
                current = current->getRightChild();
            }
        }

        //Invariant: at no point in the loop did current's value
        //ever equal what we're looking for.  Thus, return false;
        return false;
    }
    virtual const T& getFirst() const
    {
        return _root->getValue();
    }
    virtual T& getFirst()
    {
        return _root->getValue();
    }
    virtual int getSize() const
    {
        return _size;
    }
    virtual bool isEmpty() const
    {
        return _size == 0;
    }

    //returns the root pointer for learners to play around with.  Probably shouldn't exist 
    //is a real BST.
    virtual const BinaryNode<T>* getRoot()
    {
        return _root;
    }

#pragma endregion

    void performTraversal(TreeTraversal<T> &traversal)
    {
        traversal.traverse(_root);
    }
};

#endif // !BINARY_SEARCH_TREE_H
