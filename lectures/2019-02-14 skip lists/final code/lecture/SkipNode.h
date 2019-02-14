#pragma once
#ifndef	SKIP_NODE_H
#define SKIP_NODE_H

#include "ListNode.h"
template <typename T>
class SkipNode : public ListNode<T>
{
private:
	SkipNode<T>* _below = nullptr;

public:
	SkipNode(const T& value)
		: ListNode(value)
	{
	}

	SkipNode<T>* getBelow()
	{
		return _below;
	}

	SkipNode<T>* getNext()
	{
		return dynamic_cast<SkipNode<T>*>(ListNode<T>::getNext());
	}
};

#endif