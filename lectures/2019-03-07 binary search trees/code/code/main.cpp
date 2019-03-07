#include "BinarySearchTree.h"
#include <iostream>
#include <string>
using namespace std;


int main(void)
{
   BinarySearchTree<int> tree{};
   tree.addElement(100);
   tree.addElement( 75);
   tree.addElement( 25);
   tree.addElement( 10);
   tree.addElement( 50);
   tree.addElement( 125);
   tree.addElement( 111);
   tree.addElement( 150);
   tree.addElement( 145);
   tree.addElement( 155);
   tree.addElement( 110);
   tree.addElement( 112);
   tree.addElement( 115);
   tree.addElement( 114);
   tree.addElement( 120);
   tree.addElement( 117);
   tree.addElement( 116);
   tree.addElement( 118);

   //complex case #1
   tree.removeElement(125);

   //complex case #2
   tree.removeElement(150);

   //easy case #1
   tree.removeElement(75);

   //ease case #2
   tree.removeElement(10);
}