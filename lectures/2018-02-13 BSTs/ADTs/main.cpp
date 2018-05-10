#include <iostream>
#include <string>
#include "ADTs\BinarySearchTree.h"
#include "ADTs\TreeTraversal.h"
#include "ADTs\RandomNumberGenerator.h"

using namespace std;

int main(void)
{
    RandomNumberGenerator rng{};
    BinarySearchTree<int> bst{};

    for (int i = 0; i < 50; i++)
    {
        bst.addElement(rng.getRandomNumber());
    }
    TreeToSortedVector<int> traversal{};
    traversal.traverse(bst.getRoot());
    for (auto item : traversal.getItems())
    {
        cout << item << " ";
    }
    cout << endl;

    return 0;
}