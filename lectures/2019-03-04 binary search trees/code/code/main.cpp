#include "BinaryNode.h"
#include <iostream>
#include <string>
using namespace std;

BinaryNode<int>* bstAdd(BinaryNode<int>* node, int value)
{
	//null node indicates time to create a new item in our tree
	if (node == nullptr)
	{
		node = new BinaryNode<int>{ value };
		return node;
	}

	//if not null, send result to child based on relation of node's value
	//and new value
	if(value >= node->getValue())
	{
		node->setRight(bstAdd(node->getRight(), value));
	}
	else
	{
		node->setLeft(bstAdd(node->getLeft(), value));
	}

	//to maintian recursive correctness, always return a BinaryNode<T>*
	return node;
}

bool find(BinaryNode<int>* start, const int& to_find)
{
	//recursive base case answers the question, 
	//"how do we know when we're done?"
	//base case 1: start's value matches to_find
	//base case 2: if children are null (not needed)
	//base case 3: if *start* is null
	if (start == nullptr)
	{
		return false;
	}

	//always do after null check to prevent runtime exceptions
	if (start->getValue() == to_find)
	{
		return true;
	}

	//recursive case: offload work to some subsegment of 
	//our children
	return find(start->getLeft(), to_find) 
		|| find(start->getRight(), to_find);
}
int size(BinaryNode<int>* start)
{
	//base case: nothing has no size (0)
	if (start == nullptr)
	{
		return 0;
	}

	//Invariant: something we know to be true
	//Invariant: start is not null
	//therefore, start has a size
	return 1 + size(start->getLeft()) + size(start->getRight());
}

int height(BinaryNode<int>* start)
{
	//base case: null ptr.  Height of null is -1
	if (start == nullptr)
	{
		return -1;
	}

	//recursive calls to child nodes
	int left_height = height(start->getLeft());
	int right_height = height(start->getRight());

	//assume right side is smaller, check assumption
	int height = right_height;
	if (left_height > right_height)
	{
		height = left_height;
	}
	return 1 + height;
}

//true when all nodes have either 0 or 2 children, false
//otherwise
bool isFull(BinaryNode<int>* start)
{
	if (start == nullptr)
	{
		return true;
	}
	if (start->getLeft() != nullptr && start->getRight() == nullptr)
	{
		return false;
	}
	else if (start->getLeft() == nullptr && start->getRight() != nullptr)
	{
		return false;
	}
	return isFull(start->getLeft()) && isFull(start->getRight());
}

int main(void)
{
	BinaryNode<int>* root = new BinaryNode<int>{ 100 };
	bstAdd(root, 25);
	bstAdd(root, 75);
	bstAdd(root, 10);
	bstAdd(root, 125);
	bstAdd(root, 111);
	bstAdd(root, 150);
	
}