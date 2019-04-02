#pragma once
#ifndef AVL_NODE_H
#define AVL_NODE_H

#include "BinaryNode.h"

template <typename T>
class AvlNode : public BinaryNode<T>
{
private:
	int _height = 0;

public:
	//empty constructor
	AvlNode() : BinaryNode<T>(){}

	//value constructor
	AvlNode(const T& value) : BinaryNode<T>(value) {}

	int getHeight() const
	{
		return _height;
	}

	void setHeight(const int& h)
	{
		_height = h;
	}

	AvlNode<T>* getLeft()
	{
		return dynamic_cast<AvlNode<T>*>(BinaryNode<T>::getLeft());
	}

	AvlNode<T>* getRight()
	{
		return dynamic_cast<AvlNode<T>*>(BinaryNode<T>::getRight());
	}

	int getBalanceFactor() 
	{
		//leaf nodes have nullptr as children, so we have
		//to protect against that possibility
		auto left_child = getLeft();
		auto right_child = getRight();

		//a null child must have a smaller height than a
		//leaf node.  If a leaf node has height 0, then 
		//null node must be less.  We select -1.
		int left_height = (left_child == nullptr)
			? -1 
			: left_child->getHeight();
		int right_height = (right_child == nullptr)
			? -1
			: right_child->getHeight();
		return right_height - left_height;
	}
};

#endif // !AVL_NODE_H
