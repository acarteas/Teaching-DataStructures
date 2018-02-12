#ifndef AVL_NODE_H
#define AVL_NODE_H

#include "BinaryNode.h"

template <typename T>
class AvlNode : public BinaryNode<T>
{
private:
	int _height = 0;

public:

	//carry over constructors from parent
	AvlNode() : BinaryNode<T>()
	{
	}

	AvlNode(T value) : BinaryNode<T>(value)
	{
	}

	AvlNode(AvlNode<T> *left, AvlNode<T> *right) : BinaryNode<T>(left, right)
	{
	}

	int getHeight() const
	{
		return _height;
	}

	void setHeight(const int& height)
	{
		_height = height;
	}

	int getBalanceFactor()
	{
		AvlNode<T> *left = dynamic_cast<AvlNode<T> *>(BinaryNode<T>::getLeftChild());
		AvlNode<T> *right = dynamic_cast<AvlNode<T> *>(BinaryNode<T>::getRightChild());

		int left_height = (left == nullptr) ? -1 : left->getHeight();
		int right_height = (right == nullptr) ? -1 : right->getHeight();

		return right_height - left_height;
	}
};

#endif