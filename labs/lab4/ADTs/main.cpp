#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include "sorting\Sorting.h"
#include "benchmarks\SortingBenchmark.h"
#include "ADTs\Vector.h"
#include "ADTs\StringGraphNode.h"
#include "ADTs\BinaryNode.h"
#include "ADTs\RandomNumberGenerator.h"

using namespace std;

//traversal -> search
//PRE-Order traversal (DFS)
void preOrderTraversal(BinaryNode<int>* root)
{
    stack <BinaryNode<int>*> to_visit{};
    to_visit.push(root);
    while (to_visit.empty() == false)
    {
        BinaryNode<int>* current = to_visit.top();
        to_visit.pop();
        if (current != nullptr)
        {
            cout << current->getValue() << " ";
            to_visit.push(current->getRightChild());
            to_visit.push(current->getLeftChild());
        }
    }
}

//level order traversal (BFS)
void levelOrderTraversal(BinaryNode<int>* root)
{
    queue <BinaryNode<int>*> to_visit{};
    to_visit.push(root);
    while (to_visit.empty() == false)
    {
        BinaryNode<int>* current = to_visit.front();
        to_visit.pop();
        if (current != nullptr)
        {
            cout << current->getValue() << " ";
            to_visit.push(current->getLeftChild());
            to_visit.push(current->getRightChild());
        }
    }
}

//recursive in-order traversal
void inOrderTraversal(BinaryNode<int>* root)
{
    if (root == nullptr)
    {
        return;
    }
    inOrderTraversal(root->getLeftChild());
    cout << root->getValue() << " ";
    inOrderTraversal(root->getRightChild());
}

//recursive post-order traversal
void postOrderTraversal(BinaryNode<int>* root)
{
    if (root == nullptr)
    {
        return;
    }
    postOrderTraversal(root->getLeftChild());
    postOrderTraversal(root->getRightChild());
    cout << root->getValue() << " ";
}

void createRandomTree(BinaryNode<int>* root, 
                      int value, 
                      const RandomNumberGenerator& rng)
{
    //flip coin
    int coin = rng.getRandomNumber(0, 2);

    //0  = left
    if (coin == 0)
    {
        if (root->getLeftChild() == nullptr)
        {
            root->setLeftChild(new BinaryNode<int>{ value });
        }
        else
        {
            createRandomTree(root->getLeftChild(), value, rng);
        }
    }
    else
    {
        if (root->getRightChild() == nullptr)
        {
            root->setRightChild(new BinaryNode<int>{ value });
        }
        else
        {
            createRandomTree(root->getRightChild(), value, rng);
        }
    }
}

int main(void)
{
	/*
	                          1
						2		     3
					4			5		 6
								      7		8
	*/								   
	//examples of manually constructing a binary tree
	BinaryNode<int>* tree = new BinaryNode<int>{1};
	tree->setLeftChild(new BinaryNode<int>{ 2 });
	tree->setRightChild(new BinaryNode<int>{ 3 });
	tree->getLeftChild()->setLeftChild(new BinaryNode<int>{ 4 });
    tree->getRightChild()->setLeftChild(new BinaryNode<int>{ 5 });
    tree->getRightChild()->setRightChild(new BinaryNode<int>{ 6 });
    tree->getRightChild() //going down right side
        ->getRightChild() //again visit right side
        ->setLeftChild(new BinaryNode<int>{ 7 }); //add left child as GC
    tree->getRightChild()
        ->getRightChild()
        ->setRightChild(new BinaryNode<int>{ 8 });


    //create random tree of size 10
    BinaryNode<int> *random_tree = new BinaryNode<int>{ 0 };
    RandomNumberGenerator rng{};
    for (int i = 1; i < 10; i++)
    {
        createRandomTree(random_tree, i, rng);
    }

    preOrderTraversal(random_tree);
    cout << endl;
    inOrderTraversal(random_tree);
    return 0;
}