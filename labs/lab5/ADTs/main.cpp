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
	Test t2;
	t2.value = 7;
	return t2;
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
    BinaryNode<int>* merged = nullptr;

    //LAB TASK: merge these two trees into a single, valid BST
    //NOTE: may be helpful to write a recursive helper function

    //if done correctly, should be in-order
    RecursiveInOrderTraversal<int> traversal{};
    traversal.traverse(merged);

}

void subtreeTest(BinaryNode<int>* tree1, BinaryNode<int>* tree2)
{
    //LAB TASK: determine if tree2 is a subtree of tree1
    //Note: writing a recursive helper function may be useful
}

void commonAncestor(BinaryNode<int>* tree, int val1, int val2)
{
    //LAB TASK: determine closest parent for val1 and val2
}


int main(void)
{
	Test t{};
	t.value = 10;
	Test t2 = getTest(t);
	getTest(t).value = 12;
	cout << t.value << endl;

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

    //should be 11
    commonAncestor(tree1.getRoot(), 30, 12);

    //should be "NONE"
    commonAncestor(tree1.getRoot(), 30, 100);

    
    return 0;
}
