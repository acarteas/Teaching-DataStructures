# Lab 5
This lab is intended to get you accustomed to working with recursive tree functions.  To that end, you must implement the following functions inside main.cpp:

## void mergeTrees()
In this function, you must merge the two supplied trees in such a way that the properties of a BST are maintained.

## void subtreeTest(BinaryNode<int>* tree1, BinaryNode<int>* tree2)
In this function, you must determine if tree2 is a subtree of tree1.  Note that a subtree has exactly the same elements in exactly the same location as a parent.  

## void commonAncestor(BinaryNode<int>* tree, int val1, int val2)
For this function, determine the closest common ancestor of both values in the tree.  If one value is not in the tree, output "NONE".  For example, given the tree:

```
            10
        5       15
     1    6   11   17
```

* Values 1 and 5 share the ancestor 5 (parent-child relationship).  
* Values 1 and 6 share the ancestor 5 (sibling relationship).
* Values 6 and 11 share the ancestor 10 (grandparent relationship).