#ifndef SKIP_NODE_H
#define SKIP_NODE_H

#include "ListNode.h"

//AC Note: This implementation isn't terribly efficient as each 
//SkipNode contains its own copy of a given value.
template <typename T>
class SkipNode : public ListNode<T>
{
protected:
	SkipNode<T> *_below = nullptr;
	bool _isSentinel = false;

public:
	
	SkipNode<T> *getBelow()
	{
		return _below;
	}

	bool isSentinel() const
	{
		return _isSentinel;
	}

	void setIsSentinel(bool value)
	{
		_isSentinel = value;
	}

	void setBelow(SkipNode<T> *below)
	{
		_below = below;
	}

	SkipNode() : ListNode()
	{
	}

	//constructor must accept a default value
	SkipNode(const T &value) : ListNode(value)
	{
	}

	//copy constructor prevents premature deletion of pointers
	SkipNode(const SkipNode<T> &other) : ListNode(other)
	{
		_below = other.getBelow();
	}

	//copy operator allows us to reassign previously created skip nodes
	SkipNode<T> &operator=(const SkipNode<T> &other)
	{
		if (this != &other)
		{
			SkipNode<T> temp(other);
			swap(*this, temp);
		}
		return *this;
	}

};

#endif