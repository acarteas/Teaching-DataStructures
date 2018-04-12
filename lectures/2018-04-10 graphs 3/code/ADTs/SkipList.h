#ifndef SKIP_LIST_H
#define SKIP_LIST_H

#include "Collection.h"
#include "Vector.h"
#include "SkipNode.h"
#include "RandomNumberGenerator.h"
#include "StackAdapter.h"
#include <utility>
using namespace std;

template <typename T>
class SkipList : public Collection<T>
{
private:
	Vector<SkipNode<T> *> _nodes;
	RandomNumberGenerator _rng;
	int _size = 0;

protected:

	//only finds the correct location on a given level
	//(we won't take down pointers)
	SkipNode<T> *levelFind(SkipNode<T> *start, const T& item)
	{
		//grab top-most starter node
		SkipNode<T> *current = _nodes[_nodes.getSize() - 1];

		//shift down until we find either the value
		//or a nullptr
		while (current != nullptr 
			&& current->getNext() != nullptr
			&& current->getValue() != item)
		{
			//one of two options: either go next if 
			//we are less than or down if we are not.
			if (current->getNext()->getValue() <= item)
			{
				current =
					dynamic_cast<SkipNode<T>*>(
						current->getNext()
						);
			}
			else
			{
				break;
			}
		}
		return current;
	}

	//finds the correct location to insert a given node
	SkipNode<T> *find(SkipNode<T> *start, const T& item)
	{
		//grab top-most starter node
		SkipNode<T> *current = _nodes[_nodes.getSize() - 1];
		SkipNode<T> *previous = current;

		//shift down until we find either the value
		//or a nullptr
		while (current != nullptr &&
			current->getValue() != item)
		{
			previous = current;

			//one of two options: either go next if 
			//we are less than or down if we are not.
			if (current->getNext()->getValue() <= item)
			{
				current = 
					dynamic_cast<SkipNode<T>*>(
						current->getNext()
						);
			}
			else
			{
				current = current->getBelow();
			}
		}
		return previous;
	}

	//handles the recursive bit of adding new elements to the list
	pair<SkipNode<T> *, int> addElementHelper(SkipNode<T> *start, const T& item, int depth = 0)
	{

	}

public:

	SkipList()
	{
		//add starting "empty" node
		SkipNode<T> *first = new SkipNode<T>{};
		first->setIsSentinel(true);
		_nodes.addElement(first);
	}

	virtual ~SkipList()
	{
		for (int i = 0; i < _nodes.getSize(); i++)
		{
			SkipNode<T> *current = _nodes.getElementAt(i);
			while (current != nullptr)
			{
				SkipNode<T> *next = dynamic_cast<SkipNode<T> *>(current->getNext());
				delete current;
				current = next;
			}
		}
	}

#pragma region Collection overrides

	virtual void addElement(const T &item)
	{
		//TODO: fix memory leak
		StackAdapter<SkipNode<T>*> item_stack{ new Vector<SkipNode<T>*>{} };

		//find appropraite insert location at each level of
		//skip list
		item_stack.push(levelFind(_nodes[_nodes.getSize() - 1], item));
		for (int i = _nodes.getSize() - 2; 
			i >= 0; 
			i--)
		{
			//begin search at last found node on prior
			//level
			item_stack.push(
				levelFind(item_stack.getTop()->getBelow(),
					item)
			);
		}

		bool should_add = true;
		SkipNode<T> *last_add = nullptr;
		while (item_stack.getSize() > 0 && should_add == true)
		{
			SkipNode<T> *before = item_stack.pop();
			SkipNode<T> *current = new SkipNode<T>{ item };
			current->setBelow(last_add);
			last_add = current;
			current->setNext(before->getNext());
			before->setNext(current);
			should_add = _rng.getRandomNumber(0, 2) == 1;
		}

		//do we need to add a whole new level to our
		//SkipList
		if (should_add == true)
		{
			//create new level in vector
			SkipNode<T> *sentinel = new SkipNode<T>{};
			sentinel->setIsSentinel(true);
			_nodes.addElement(sentinel);

			//add new item, link to sentinel
			SkipNode<T> *current = new SkipNode<T>{ item };
			sentinel->setNext(current);
		}
		
	}

	virtual bool isEmpty() const
	{
		return _size == 0;
	}


	virtual int getSize() const
	{
		return _size;
	}

    //TODO: implement
    virtual void removeElement(const T& item)
    {

    }

    //TODO: implement
    virtual bool containsElement(const T& item) const
    {
		return false;
		//return find(_items item)->getValue() != item;
		
    }

    //TODO: implement
    virtual const T& getFirst() const
    {
		return _nodes[0]->getValue();
    }

    //TODO: implement
    virtual T& getFirst()
    {
		return _nodes[0]->getValue();
    }


#pragma endregion

};
#endif