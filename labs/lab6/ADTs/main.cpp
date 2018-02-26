#include <iostream>
#include <string>
#include <queue>
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
	else if(node->isLeaf() == true)
	{
		return 0;
	}
	int left_height = getHeight(node->getLeftChild());
	int right_height = getHeight(node->getRightChild());
	if (left_height > right_height)
	{
		return 1 + left_height;
	}
	else
	{
		return 1 + right_height;
	}
}

bool isAvl(BinarySearchTree<int> *tree)
{
    return false;
}

BinaryNode<int>* rotateLeft(BinaryNode<int>* original_root)
{
    return original_root;
}

bool isFull(BinarySearchTree<int> *tree)
{
    return false;
}

bool isComplete(BinarySearchTree<int>* tree)
{
	//allows us to perform level-order traversal
	queue<BinaryNode<int>*> to_visit{};

	//keeps track of whether or not we've seen a null node yet
	bool has_seen_null = false;

	//prime loop
	to_visit.push(tree->getRoot());
	
	//begin BFS
	while (to_visit.empty() == false)
	{
		//grab front node from queue
		BinaryNode<int>* front = to_visit.front();
		to_visit.pop();

		//did we just see a null?
		if (front == nullptr)
		{
			has_seen_null = true;
		}
		else
		{
			//found a gap, therefore not complete
			if (has_seen_null == true)
			{
				return false;
			}

			//otherwise, push on children
			to_visit.push(front->getLeftChild());
			to_visit.push(front->getRightChild());
		}
	}

    return true;
}

void codeTest()
{

}

int main(void)
{
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
