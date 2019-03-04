#include "BinaryNode.h"
#include <iostream>
#include <string>
using namespace std;

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
	BinaryNode<int>* root = new BinaryNode<int>{ 5 };
	root->setLeft(new BinaryNode<int>{ 12 });
	root->setRight(new BinaryNode<int>{ 4 });
	root->getLeft()->setLeft(new BinaryNode<int>{ 11 });
	root->getLeft()->setRight(new BinaryNode<int>{ 18 });
	root->getRight()->setLeft(new BinaryNode<int>{ 10 });
	root->getRight()->setRight(new BinaryNode<int>{7});
	root->getRight()
		->getLeft()
		->setLeft(new BinaryNode<int>{3});
	root->getRight()
		->getLeft()
		->setRight(new BinaryNode<int>{ 9 });
	root->getRight()
		->getRight()
		->setRight(new BinaryNode<int>{ 15 });
	root->getRight()
		->getRight()
		->getRight()
		->setLeft(new BinaryNode<int>{ 20 });
	root->getRight()
		->getRight()
		->getRight()
		->setRight(new BinaryNode<int>{ 22 });

	cout << find(root, 7) << endl;
}