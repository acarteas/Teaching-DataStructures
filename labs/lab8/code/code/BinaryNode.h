#pragma once
#ifndef BINARY_NODE_H
#define BINARY_NODE_H

template <typename T>
class BinaryNode
{
protected:
	T _value;
	BinaryNode* _left = nullptr;
	BinaryNode* _right = nullptr;
public:

	//constructor
	BinaryNode(const T& value)
	{
		_value = value;
	}

	//empty constructor
	BinaryNode()
	{
		//no clue what _value will be
	}

	//enables polymorphism
	virtual ~BinaryNode()
	{

	}

	BinaryNode* getLeft()
	{
		return _left;
	}

	void setLeft(BinaryNode* left)
	{
		_left = left;
	}

	BinaryNode* getRight()
	{
		return _right;
	}

	void setRight(BinaryNode* right)
	{
		_right = right;
	}

	T& getValue()
	{
		return _value;
	}

	const T& getValue() const
	{
		return _value;
	}

	void setValue(const T& value)
	{
		_value = value;
	}
};



#endif