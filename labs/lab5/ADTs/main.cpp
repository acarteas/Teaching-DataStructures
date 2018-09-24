#include <iostream>
#include <string>
#include "sorting\Sorting.h"
#include "ADTs\BinarySearchTree.h"
#include "ADTs\TreeTraversal.h"
#include "ADTs\RandomNumberGenerator.h"

using namespace std;

class Test
{
public:
	int value;
};

Test& getTest(Test& t)
{
	return t;
}

void insert(BinaryNode<int>* node, int value)
{
	if (node == nullptr)
	{
		return;
	}
	if (value < node->getValue())
	{
		if (node->getLeftChild() == nullptr)
		{
			node->setLeftChild(new BinaryNode<int>{ value });
		}
		else
		{
			insert(node->getLeftChild(), value);
		}
	}
	else
	{
		if (node->getRightChild() == nullptr)
		{
			node->setRightChild(new BinaryNode<int>{ value });
		}
		else
		{
			insert(node->getRightChild(), value);
		}
	}
}

void merge(BinaryNode<int>* destination, BinaryNode<int>* values_to_insert)
{
	if (values_to_insert == nullptr || destination == nullptr)
	{
		return;
	}
	insert(destination, values_to_insert->getValue());
	merge(destination, values_to_insert->getLeftChild());
	merge(destination, values_to_insert->getRightChild());
}

void mergeTrees()
{
    BinarySearchTree<int> tree1{};
    BinarySearchTree<int> tree2{};
    RandomNumberGenerator rng{};

    for(int i = 0; i < 15; i++)
    {
        tree1.addElement(rng.getRandomNumber(1, 100));
        tree2.addElement(rng.getRandomNumber(1, 100));
    }

    BinaryNode<int>* root1 = tree1.getRoot();
    BinaryNode<int>* root2 = tree2.getRoot();
	merge(root1, root2);
	BinaryNode<int>* merged = root1;

    //LAB TASK: merge these two trees into a single, valid BST
    //NOTE: may be helpful to write a recursive helper function

    //if done correctly, should be in-order
    RecursiveInOrderTraversal<int> traversal{};
    traversal.traverse(merged);

}

BinaryNode<int>* findStart(BinaryNode<int>* node, int value)
{
	if (node == nullptr)
	{
		return nullptr;
	}
	if (node->getValue() == value)
	{
		return node;
	}
	if (node->getValue() > value)
	{
		return findStart(node->getLeftChild(), value);
	}
	else
	{
		return findStart(node->getRightChild(), value);
	}
}

bool doesMatch(BinaryNode<int>* first, BinaryNode<int>* second)
{
	if (first == nullptr && second == nullptr)
	{
		return true;
	}
	else if (first == nullptr || second == nullptr)
	{
		return false;
	}
	if (first->getValue() == second->getValue())
	{
		return (doesMatch(first->getLeftChild(), second->getLeftChild())
			&& doesMatch(first->getRightChild(), second->getRightChild())
			);
	}
	else
	{
		return false;
	}
}

void subtreeTest(BinaryNode<int>* tree1, BinaryNode<int>* tree2)
{
    //LAB TASK: determine if tree2 is a subtree of tree1
    //Note: writing a recursive helper function may be useful
	BinaryNode<int>* start = findStart(tree1, tree2->getValue());
	if (doesMatch(tree2, start) == true)
	{
		cout << "Is Subtree" << endl;
	}
	else
	{
		cout << "Not a subtree" << endl;
	}
}

bool exists(BinaryNode<int>* node, int value)
{
	if (node == nullptr)
	{
		return false;
	}
	if (node->getValue() == value)
	{
		return true;
	}
	else if(node->getValue() <= value)
	{
		return exists(node->getRightChild(), value);
	}
	else
	{
		return exists(node->getLeftChild(), value);
	}
}

void commonAncestorHelper(BinaryNode<int>* tree, int val1, int val2)
{
	if (tree == nullptr)
	{
		cout << "Error!" << endl;
		return;
	}
	if (val1 == tree->getValue() || val2 == tree->getValue())
	{
		cout << tree->getValue() << endl;
	}
	else if (
		(val1 < tree->getValue() && val2 > tree->getValue())
		||
		(val1 > tree->getValue() && val2 < tree->getValue())
		)
	{
		cout << tree->getValue() << endl;
	}
	else if (val1 < tree->getValue() && val2 < tree->getValue())
	{
		commonAncestorHelper(tree->getLeftChild(), val1, val2);
	}
	else
	{
		commonAncestorHelper(tree->getRightChild(), val1, val2);
	}
}

void commonAncestor(BinaryNode<int>* tree, int val1, int val2)
{
    //LAB TASK: determine closest parent for val1 and val2
	//does val1 and val2 exist below us? If so, return tree's value
	if (exists(tree, val1) != true || exists(tree, val2) != true)
	{
		cout << "None!" << endl;
		return;
	}
	return commonAncestorHelper(tree, val1, val2);
}


int main(void)
{
	Test t{};
	t.value = 10;
	Test t2 = getTest(t);
	getTest(t).value = 12;
	//cout << t.value << endl;

    BinarySearchTree<int> tree1{};
    BinarySearchTree<int> tree2{};

    tree1.addElement(10);
    tree1.addElement(5);
    tree1.addElement(7);
    tree1.addElement(2);
    tree1.addElement(9);
    tree1.addElement(15);
    tree1.addElement(11);
    tree1.addElement(12);
    tree1.addElement(20);
    tree1.addElement(25);
    tree1.addElement(27);
    tree1.addElement(30);

    tree2.addElement(20);
    tree2.addElement(25);
    tree2.addElement(27);
    tree2.addElement(30);

    mergeTrees();

    //should be TRUE
    subtreeTest(tree1.getRoot(), tree2.getRoot());

    tree2 = BinarySearchTree<int>{};
    tree2.addElement(5);
    tree2.addElement(9);
    tree2.addElement(27);
    tree2.addElement(25);

    //should be FALSE
    subtreeTest(tree1.getRoot(), tree2.getRoot());

    //should be 5
    commonAncestor(tree1.getRoot(), 5, 7);

    //should be 15
    commonAncestor(tree1.getRoot(), 30, 12);

    //should be "NONE"
    commonAncestor(tree1.getRoot(), 30, 100);

    
    return 0;
}
