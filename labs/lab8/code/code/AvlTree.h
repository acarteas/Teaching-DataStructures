#pragma once
#ifndef AVL_TREE_H
#define AVL_TREE_H

#include "BinarySearchTree.h"

template <typename T>
class AvlTree : public BinarySearchTree<T>
{
private:
	AvlNode<T>* rotateRight(AvlNode<T>* node)
	{
		//Let new_root = node's left child
		AvlNode<T>* new_root = node->getLeft();

		//Set node's LC equal to new_root's RC
		node->setLeft(new_root->getRight());
		node = setHeight(node);

		//set new_root's right to node
		new_root->setRight(node);
		return setHeight(new_root);
	}

	AvlNode<T>* rotateLeft(AvlNode<T>* node)
	{
		AvlNode<T>* new_root = node->getRight();
		node->setRight(new_root->getLeft());
		node = setHeight(node);
		new_root->setLeft(node);
		return setHeight(new_root);
	}

	//balances out a given node
	AvlNode<T>* balance(AvlNode<T>* node)
	{
		if (node == nullptr)
		{
			return node;
		}

		int balance_factor = node->getBalanceFactor();
		if (balance_factor > 1)
		{
			//When the balance factor of the node is positive
			//and the balance factor of the node's right child is
			//negative:
				//rotate right at node's right child
				//rotate left at node
			if (node->getRight()->getBalanceFactor() < 0)
			{
				//TODO: rotate right child right
				node->setRight(rotateRight(node->getRight()));
			}
			//TODO: rotate left at node
			return rotateLeft(node);
		}
		else if (balance_factor < -1)
		{
			//When the balance factor of the node is negative
			//and the balance factor of the node's left child is
			//positive:
				//rotate left at node's left child
				//rotate right at node
			if (node->getLeft()->getBalanceFactor() > 0)
			{
				//TODO: rotate left child left
				node->setLeft(rotateLeft(node->getLeft()));
			}
			//TODO: rotate right at node
			return rotateRight(node);
		}
		return node;
	}

	//sets the height of the supplied node
	AvlNode<T>* setHeight(AvlNode<T>* node)
	{
		//ALWAYS check for nullness
		if (node == nullptr)
		{
			return node;
		}

		AvlNode<T>* left = node->getLeft();
		AvlNode<T>* right = node->getRight();
		int left_height = (left == nullptr)
			? -1
			: left->getHeight();
		int right_height = (right == nullptr)
			? -1
			: right->getHeight();
		int height = left_height;
		if (left_height < right_height)
		{
			height = right_height;
		}

		//add 1 to account for us
		height++;
		node->setHeight(height);

		//check for AVL compliance
		int balance_factor = node->getBalanceFactor();
		if (balance_factor > 1 || balance_factor < -1)
		{
			//NOT AVL compliant
			return balance(node);
		}
		return node;
	}

protected:

	//this will override default BST add behavior
	virtual BinaryNode<T>* bstAdd(BinaryNode<T>* node, int value)
	{
		//be sure to create AVL nodes, NOT BST nodes
		if (node == nullptr)
		{
			node = new AvlNode<T>{ value };
			return node;
		}

		//reuse previous code
		AvlNode<T>* result = 
			dynamic_cast<AvlNode<T>*>(
			BinarySearchTree<T>::bstAdd(node, value)
				);

		//set node's height
		return setHeight(result);

	}
};

#endif