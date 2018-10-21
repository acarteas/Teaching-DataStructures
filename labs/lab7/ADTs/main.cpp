#include <iostream>
#include <string>
#include <queue> //for PQ
#include <functional> //for making a min-queue
#include <vector> //also needed for PQ
#include <cmath>
#include <stack>
#include "sorting\Sorting.h"
#include "ADTs\BinarySearchTree.h"
#include "ADTs\TreeTraversal.h"
#include "ADTs\RandomNumberGenerator.h"

using namespace std;

int getHeight(BinaryNode<int>* node)
{
	if (node == nullptr)
	{
		return -1;
	}
	int left_height = getHeight(node->getLeftChild());
	int right_height = getHeight(node->getRightChild());
	int max_height = left_height;
	if (right_height > left_height)
	{
		max_height = right_height;
	}
	return 1 + max_height;
}

bool isAvlHelper(BinaryNode<int>* node)
{
	if (node == nullptr)
	{
		return true;
	}
	int left_height = getHeight(node->getLeftChild());
	int right_height = getHeight(node->getRightChild());
	if (abs(right_height - left_height) < 2)
	{
		return isAvlHelper(node->getLeftChild()) 
			&& isAvlHelper(node->getRightChild());
	}
	else
	{
		return false;
	}
}

bool isAvl(BinarySearchTree<int> *tree)
{
	return isAvlHelper(tree->getRoot());
}

BinaryNode<int>* rotateLeft(BinaryNode<int>* original_root)
{
	BinaryNode<int>* new_root = original_root->getRightChild();
	original_root->setRightChild(new_root->getLeftChild());
	new_root->setLeftChild(original_root);
	return new_root;
}

bool isFullHelper(BinaryNode<int>* node)
{
	if (node == nullptr)
	{
		return true;
	}
	if (node->getLeftChild() == nullptr 
		&& node->getRightChild() == nullptr)
	{
		return true;
	}
	else if (node->getLeftChild() == nullptr 
		|| node->getRightChild() == nullptr)
	{
		return false;
	}
	else
	{
		return isFullHelper(node->getRightChild())
			&& isFullHelper(node->getLeftChild());
	}
}

bool isFull(BinarySearchTree<int> *tree)
{
	if (tree == nullptr)
	{
		return true;
	}
	return isFullHelper(tree->getRoot());
}

void levelOrderTraversal(BinarySearchTree<int> *tree)
{
	if (tree == nullptr)
	{
		return;
	}
	queue<BinaryNode<int>*> node_queue{};
	node_queue.push(tree->getRoot());
	while (node_queue.empty() == false)
	{
		BinaryNode<int>* top = node_queue.front();
		node_queue.pop();
		if (top != nullptr)
		{
			cout << top->getValue() << ", ";
			node_queue.push(top->getLeftChild());
			node_queue.push(top->getRightChild());
		}
	}
}

bool isComplete(BinarySearchTree<int>* tree)
{
	if (tree == nullptr)
	{
		return true;
	}
	queue<BinaryNode<int>*> node_queue{};
	node_queue.push(tree->getRoot());
	bool has_null = false;
	while (node_queue.empty() == false)
	{
		BinaryNode<int>* top = node_queue.front();
		node_queue.pop();
		if (top != nullptr)
		{
			if (has_null == true)
			{
				return false;
			}
			node_queue.push(top->getLeftChild());
			node_queue.push(top->getRightChild());
		}
		else
		{
			has_null = true;
		}
	}
	return true;
}

int main(void)
{
	//given a vector that represents effort expenditure
	//e.g. {1, 1, 2, 3}
	//We need to combine these efforts into a single value
	//such that the amount of effort expended is minimized
	//Example:
	//{1, 1, 2, 3} -> {2, 2, 3} (2 effort)
	//{2, 2, 3} -> {4, 3} (4 effort)
	//{4, 3} -> {7} (7 effort)
	//total effort = 2 + 4 + 7 = 13
	priority_queue<int, vector<int>, greater<int>> pq{}; //min PQ
	vector<int> effort{ 1, 1, 2, 3 };

	//add everything to our PQ
	for (auto i : effort)
	{
		pq.push(i);
	}
	int total_effort = 0;
	while (pq.size() > 1)
	{
		int first = pq.top();
		pq.pop();
		int second = pq.top();
		pq.pop();
		int temp = first + second;
		total_effort += temp;
		pq.push(temp);
	}
	cout << "Total effort: " << total_effort << endl;

	BinarySearchTree<int> tree{};

	cout << boolalpha << "Is Full: " << isFull(&tree) << " (expected: TRUE)" << endl;
	cout << boolalpha << "Is Complete: " << isComplete(&tree) << " (expected: TRUE)" << endl;
	cout << boolalpha << "Is AVL: " << isAvl(&tree) << " (expected: TRUE)" << endl;
	cout << boolalpha << "Height: " << getHeight(tree.getRoot()) << " (expected: -1)" << endl;

	tree.addElement(10);
	tree.addElement(5);

	cout << boolalpha << "Is Full: " << isFull(&tree) << " (expected: FALSE)" << endl;
	cout << boolalpha << "Is Complete: " << isComplete(&tree) << " (expected: TRUE)" << endl;
	cout << boolalpha << "Is AVL: " << isAvl(&tree) << " (expected: TRUE)" << endl;
	cout << boolalpha << "Height: " << getHeight(tree.getRoot()) << " (expected: 1)" << endl;

	tree.addElement(15);

	cout << boolalpha << "Is Full: " << isFull(&tree) << " (expected: TRUE)" << endl;
	cout << boolalpha << "Is Complete: " << isComplete(&tree) << " (expected: TRUE)" << endl;
	cout << boolalpha << "Is AVL: " << isAvl(&tree) << " (expected: TRUE)" << endl;
	cout << boolalpha << "Height: " << getHeight(tree.getRoot()) << " (expected: 1)" << endl;

	tree.addElement(12);
	tree.addElement(20);

	cout << boolalpha << "Is Full: " << isFull(&tree) << " (expected: TRUE)" << endl;
	cout << boolalpha << "Is Complete: " << isComplete(&tree) << " (expected: FALSE)" << endl;
	cout << boolalpha << "Is AVL: " << isAvl(&tree) << " (expected: TRUE)" << endl;
	cout << boolalpha << "Height: " << getHeight(tree.getRoot()) << " (expected: 2)" << endl;

	tree.addElement(11);

	cout << boolalpha << "Is Full: " << isFull(&tree) << " (expected: FALSE)" << endl;
	cout << boolalpha << "Is Complete: " << isComplete(&tree) << " (expected: FALSE)" << endl;
	cout << boolalpha << "Is AVL: " << isAvl(&tree) << " (expected: FALSE)" << endl;
	cout << boolalpha << "Height: " << getHeight(tree.getRoot()) << " (expected: 3)" << endl;

	tree.addElement(13);
	tree.addElement(1);
	tree.addElement(7);

	cout << boolalpha << "Is Full: " << isFull(&tree) << " (expected: TRUE)" << endl;
	cout << boolalpha << "Is Complete: " << isComplete(&tree) << " (expected: FALSE)" << endl;
	cout << boolalpha << "Is AVL: " << isAvl(&tree) << " (expected: TRUE)" << endl;
	cout << boolalpha << "Height: " << getHeight(tree.getRoot()) << " (expected: 3)" << endl;
	cout << "Level-order traversal: ";
	levelOrderTraversal(&tree);
	cout << "(expected: 10, 5, 15, 1, 12, 20, 11, 13)" << endl;

	//Note: this breaks the tree structure because our BST isn't informed of the new root.  Must be done last
	cout << endl;
	BinaryNode<int>* rotated = rotateLeft(tree.getRoot());
	RecursivePreOrderTraversal<int> traversal{};
	traversal.traverse(rotated);
	cout << endl;

	//rotate again just for fun
	rotated = rotateLeft(rotated);
	traversal.traverse(rotated);
	return 0;
}
