#include "BinarySearchTree.h"
#include "AvlNode.h"
#include "AvlTree.h"
#include <iostream>
#include <string>
using namespace std;


int main(void)
{
   AvlTree<int> tree{};
   tree.addElement(100);
   tree.addElement( 75);
   tree.addElement(125);

   cout << "Is AVL: " << tree.isAvl() << " (expected true)" << endl;
   cout << "Common ancestor of 75 and 125 " << tree.commonAncestor(75, 125) << " (expected 100)" << endl;

   tree.addElement( 25);
   tree.addElement( 10);
   tree.addElement( 50);
   tree.addElement( 125);
   tree.addElement( 111);
   tree.addElement( 150);
   tree.addElement( 145);
   tree.addElement(155);

   cout << "Is AVL: " << tree.isAvl() << " (expected false)" << endl;
   cout << "Common ancestor of 150 and 111 " << tree.commonAncestor(150, 111) << " (expected 125)" << endl;
   cout << "Common ancestor of 10 and 111 " << tree.commonAncestor(10, 111) << " (expected 100)" << endl;

   AvlTree<int> tree2{};
   tree2.addElement(117);
   tree2.addElement( 110);
   tree2.addElement( 112);
   tree2.addElement( 115);
   tree2.addElement( 114);
   tree2.addElement( 120);
   tree2.addElement( 116);
   tree2.addElement( 118);

   tree.mergeTree(tree2);
   cout << "Is AVL: " << tree.isAvl() << " (expected ???)" << endl;
   cout << "Common ancestor of 118 and 25 " << tree.commonAncestor(118, 25) << " (expected ???)" << endl;
   cout << "Common ancestor of 115 and 111 " << tree.commonAncestor(115, 111) << " (expected ???)" << endl;
}