#include <iostream>
#include <string>
#include "sorting\Sorting.h"
#include "ADTs\BinarySearchTree.h"
#include "ADTs\TreeTraversal.h"
#include "ADTs\RandomNumberGenerator.h"

using namespace std;

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
    return false;
}

int main(void)
{
    BinarySearchTree<int> tree{};
     
    cout << boolalpha << "Is Full: " << isFull(&tree) << " (expected: TRUE)" << endl;
    cout << boolalpha << "Is Complete: " << isComplete(&tree) << " (expected: TRUE)" << endl;
    cout << boolalpha << "Is AVL: " << isAvl(&tree) << " (expected: TRUE)" << endl;

    tree.addElement(10);
    tree.addElement(5);

    cout << boolalpha << "Is Full: " << isFull(&tree) << " (expected: FALSE)" << endl;
    cout << boolalpha << "Is Complete: " << isComplete(&tree) << " (expected: TRUE)" << endl;
    cout << boolalpha << "Is AVL: " << isAvl(&tree) << " (expected: TRUE)" << endl;

    tree.addElement(15);

    cout << boolalpha << "Is Full: " << isFull(&tree) << " (expected: TRUE)" << endl;
    cout << boolalpha << "Is Complete: " << isComplete(&tree) << " (expected: TRUE)" << endl;
    cout << boolalpha << "Is AVL: " << isAvl(&tree) << " (expected: TRUE)" << endl;

    tree.addElement(12);
    tree.addElement(20);

    cout << boolalpha << "Is Full: " << isFull(&tree) << " (expected: TRUE)" << endl;
    cout << boolalpha << "Is Complete: " << isComplete(&tree) << " (expected: FALSE)" << endl;
    cout << boolalpha << "Is AVL: " << isAvl(&tree) << " (expected: TRUE)" << endl;

    tree.addElement(11);

    cout << boolalpha << "Is Full: " << isFull(&tree) << " (expected: FALSE)" << endl;
    cout << boolalpha << "Is Complete: " << isComplete(&tree) << " (expected: FALSE)" << endl;
    cout << boolalpha << "Is AVL: " << isAvl(&tree) << " (expected: FALSE)" << endl;

    tree.addElement(13);
    tree.addElement(1);
    tree.addElement(7);

    cout << boolalpha << "Is Full: " << isFull(&tree) << " (expected: TRUE)" << endl;
    cout << boolalpha << "Is Complete: " << isComplete(&tree) << " (expected: FALSE)" << endl;
    cout << boolalpha << "Is AVL: " << isAvl(&tree) << " (expected: TRUE)" << endl;


    //Note: this breaks the tree structure because our BST isn't informed of the new root.  Must be done last
    BinaryNode<int>* rotated = rotateLeft(tree.getRoot());
    RecursivePreOrderTraversal<int> traversal{};
    traversal.traverse(rotated);
    
    //rotate again just for fun
    rotated = rotateLeft(tree.getRoot());
    traversal.traverse(rotated);
    return 0;
}
