#ifndef AVL_TREE_H
#define AVL_TREE_H

#include "BinarySearchTree.h"
#include "AvlNode.h"

template <typename T>
class AvlTree : public BinarySearchTree<T>
{
protected:

	virtual BinaryNode<T> * balance(AvlNode<T> *root)
	{
		//check for null roots
		if (root == nullptr)
		{
			return root;
		}

		//get left and right children, convert into AVL Nodes
		AvlNode<T> *left = dynamic_cast<AvlNode<T> *>(root->getLeftChild());
		AvlNode<T> *right = dynamic_cast<AvlNode<T> *>(root->getRightChild());

		//are we left-heavy?
		if (root->getBalanceFactor() < 0)
		{
			//is left subtree right-heavy?
			if (left != nullptr && left->getBalanceFactor() > 0)
			{
				//rotate left at left subtree
				BinaryNode<T> *new_left = rotateLeft(root->getLeftChild());
				root->setLeftChild(new_left);
			}
			//rotate right at root
			return rotateRight(root);
		}
		else if (root->getBalanceFactor() > 0)
		{
			//is the right subtree left heavy?
			if (right != nullptr && right->getBalanceFactor() < 0)
			{
				//rotate right at right subtree
				BinaryNode<T> *new_right = rotateRight(root->getRightChild());
				root->setRightChild(new_right);
			}
			//rotate left at root
			return rotateLeft(root);
		}
		return root;
	}

	virtual BinaryNode<T> *rotateLeft(BinaryNode<T> *root)
	{
		//check for null roots
		if (root == nullptr)
		{
			return root;
		}

		//new root comes from right side
		AvlNode<T> *new_root = dynamic_cast<AvlNode<T> *>(root->getRightChild());

		//reassign right child to new root's left child
		root->setRightChild(new_root->getLeftChild());

		//recalculate root's height as it has probably changed
		root = setHeight(dynamic_cast<AvlNode<T> *>(root));

		//with that done, we can now reassign old root to new root
		new_root->setLeftChild(root);

		//and perform additional balances as necessary
		return setHeight(new_root);
	}

	virtual BinaryNode<T> *rotateRight(BinaryNode<T> *root)
	{
		//check for null roots
		if (root == nullptr)
		{
			return root;
		}

		//new root comes from left side
		AvlNode<T> *new_root = dynamic_cast<AvlNode<T> *>(root->getLeftChild());

		//reassign old root's left child from new root's right child
		root->setLeftChild(new_root->getRightChild());

		//recalculate old root's height as it has probably changed
		root = setHeight(dynamic_cast<AvlNode<T> *>(root));

		//with that done, we can assign old root to be a child of new root
		new_root->setRightChild(root);

		//set height, rebalance as necessary
		return setHeight(new_root);
	}

	virtual BinaryNode<T> * setHeight(AvlNode<T> * root)
	{
		//check for null roots
		if (root == nullptr)
		{
			return root;
		}

		//get left and right children, convert into AVL Nodes
		AvlNode<T> *left = dynamic_cast<AvlNode<T> *>(root->getLeftChild());
		AvlNode<T> *right = dynamic_cast<AvlNode<T> *>(root->getRightChild());

		//start at height 1 because I'm representing nullptrs with values of -1
		int height = 1;

		//add in largest of left or right heights
		int left_height = left == nullptr ? -1 : left->getHeight();
		int right_height = right == nullptr ? -1 : right->getHeight();
		height += (left_height < right_height) ? right_height : left_height;

		//reassign new height to root
		root->setHeight(height);

		//check to see if balance factor is out of whack
		int balance_factor = root->getBalanceFactor();
		if (balance_factor < -1 || balance_factor > 1)
		{
			return balance(root);
		}
		return root;
	}

	virtual BinaryNode<T> * addElementHelper(BinaryNode<T> *root, const T& item)
	{
		//BASE CASE: create new node
		if (root == nullptr)
		{
			root = new AvlNode<T>{};
			root->setValue(item);
			return root;
		}

		//else, just call BST helper
		BinaryNode<T> *bst_result = BinarySearchTree<T>::addElementHelper(root, item);

		//if everything went according to plan, we should be able to cast the BinaryNode
		//into an AvlNode
		AvlNode<T> *avl_node = dynamic_cast<AvlNode<T>*>(bst_result);

		//return balanced node
		return setHeight(avl_node);
	}

	virtual BinaryNode<T> *removeElementHelper(BinaryNode<T> *root, const T& item)
	{
		//call parent's method
		BinaryNode<T> *bst_result = BinarySearchTree<T>::removeElementHelper(root, item);

		//if everything went according to plan, we should be able to cast the BinaryNode
		//into an AvlNode
		AvlNode<T> *avl_node = dynamic_cast<AvlNode<T>*>(bst_result);

		//if we don't have a nullptr, balance node
		if (avl_node != nullptr)
		{
			return setHeight(avl_node);
		}
	}
};
#endif
