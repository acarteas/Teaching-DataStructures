# CS 211 Lab #4
This lab serves as an introduction to working with trees in C++.  To this end,
you will be performing the following activities:

## Task #1
In this first task, you must write your own binary tree class.  Remember that
binary trees have three properties: a left child, a right child, and a value.
For this lab, assume that the tree will contain integers.  Furthermore, we
will be using a linked-list based implementation for our binary tree. A such,
remember that the children properties are very much like "next" pointers in a
linked list.  Note the use of the word __*pointer*__ in the prevoius sentence.
__Your tree's children must be pointers__.  

## Task #2
Having built an appropriate class to represent a binary tree structure, try
populating the tree with values.  Your tree should have a height of at least
3.

## Task #3
Now that you have a populated tree, try writing the following two functions:
1. `getHeight()` - which returns the height of your tree
2. `isFull()` - which returns whether or not the tree is a full tree having
either 0 or 2 children.
