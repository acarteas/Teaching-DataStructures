#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include "Collection.h"
#include "BinaryNode.h"
#include "TreeTraversal.h"
#include "CircularQueue.h"

//This is an interface.  An interface does not have any
//concrete implementation.
template <typename T>
class BinarySearchTree : public Collection<T>
{
protected:

    BinaryNode<T> *_root = nullptr;
    int _size = 0;

    //helper function for add element call (iterative version)
    virtual BinaryNode<T>* addElementHelperIter(BinaryNode<T> *node,
        const T& item)
    {
        //initial case: dealing with an empty tree
        if (node == nullptr)
        {
            return new BinaryNode<T>{ item };
        }

        //need variable to track where we're presently at in our tree
        BinaryNode<T>* current = node;
        BinaryNode<T>* previous = current;
        while (current != nullptr)
        {
            if (item < current->getValue())
            {
                previous = current;
                current = current->getLeftChild();
            }
            else
            {
                previous = current;
                current = current->getRightChild();
            }
        }

        //at this point, current MUST be nullptr
        //and previous must be the parent of this nullptr
        //if value is less than put on left of prev, otherwise put on right
        if (item < previous->getValue())
        {
            previous->setLeftChild(new BinaryNode<T>{ item });
        }
        else
        {
            previous->setRightChild(new BinaryNode<T>{ item });
        }
        return node;
    }

    //helper function for add element recursive call
    virtual BinaryNode<T>* addElementHelper(BinaryNode<T> *node, 
        const T& item)
    {
        //were we passed a null node?
        if (node == nullptr)
        {
            //create a new node
            BinaryNode<T>* new_node = new BinaryNode<T>{ item };
            return new_node;
        }

        //is the value greater than or less than current node's value
        if (item < node->getValue())
        {
            //belongs to the left of node
            BinaryNode<T>* left = addElementHelper(node->getLeftChild(), item);
            node->setLeftChild(left);
        }
        else
        {
            //belongs on the right of node
            BinaryNode<T>* right = addElementHelper(node->getRightChild(), item);
            node->setRightChild(right);
        }
        return node;
    }

	//find the largest node in the supplied subtree headed by *node
    //Open question: what happens if node is a leaf node?  Will this still work?
	BinaryNode<T>* findAndDisconnectLargest(BinaryNode<T> *node)
	{
        BinaryNode<T> *prev = node;
		while (node != nullptr && node->getRightChild() != nullptr)
		{
            prev = node;
			node = node->getRightChild();
		}

        //at this point, node is either null OR is not null and has either
        //a left child or no children
        if (node != nullptr)
        {
            prev->setRightChild(node->getLeftChild());
        }
		return node;
	}

    BinaryNode<T>* removeElementHelper(BinaryNode<T> *node,
        const T& item)
    {
        //always check for nulls
        if (node != nullptr)
        {
            return node;
        }

        //base case: found what we've been looking for
        if (node->getValue() == item)
        {
            //three configurations of node
            if (node->isLeaf() == true)
            {
                //easy case: leaf node
                delete node;
                return nullptr;
            }
            else if (node->getRightChild() == nullptr
                || node->getLeftChild() == nullptr)
            {
                //one child
                BinaryNode<T>* good_child = node->getLeftChild();
                if (good_child == nullptr)
                {
                    good_child = node->getRightChild();
                }
                delete node;
                return good_child;
            }
            else
            {
                //two children
                BinaryNode<T>* largest = findAndDisconnectLargest(node->getLeftChild());
                node->setValue(largest->getValue());
                delete largest;
                return node;
            }
        }
        else if (item < node->getValue())
        {
            BinaryNode<T>* result = removeElementHelper(node->getLeftChild(), item);
            node->setLeftChild(result);
        }
        else
        {
            BinaryNode<T>* result = removeElementHelper(node->getRightChild(), item);
            node->setRightChild(result);
        }
        
		return node;
    }

    void destructorHelper(BinaryNode<T>* node)
    {
        //post order traversal
        if (node == nullptr)
        {
            return;
        }
        destructorHelper(node->getLeftChild());
        destructorHelper(node->getRightChild());
        delete node;
    }

public:

#pragma region Collection implementation

    virtual void addElement(const T& item)
    {
        _root = addElementHelperIter(_root, item);
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
    virtual BinaryNode<T>* getRoot()
    {
        return _root;
    }

    virtual ~BinarySearchTree()
    {
        CircularQueue<BinaryNode<T>*> queue{};
        queue.enqueue(_root);
        while (queue.getSize() > 0)
        {
            BinaryNode<T>* node = queue.dequeue();
            if (node != nullptr)
            {
                queue.enqueue(node->getLeftChild());
                queue.enqueue(node->getRightChild());
                delete node;
            }
        }
    }

#pragma endregion

    void performTraversal(TreeTraversal<T> &traversal)
    {
        //NOTE: iterative would probably be better, but we don't know how
        //to use hash tables yet
        traversal.traverse(_root);
    }
};

#endif // !BINARY_SEARCH_TREE_H
