#include <vector>
#include <iostream>
#include <string>
#include <ctime>

using namespace std;


class BinaryNode {
public:
	int value;
	BinaryNode* left = nullptr;
	BinaryNode* right = nullptr;

	BinaryNode(int v = 0)
	{
		value = v;
	}

	bool isFull()
	{

		if (left != nullptr && right != nullptr)
		{
			//two children, recursive call
			return left->isFull() && right->isFull();
		}
		else if (left == nullptr && right == nullptr)
		{
			//no children
			return true;
		}
		else
		{
			//1 child
			return false;
		}
	}
};

class BinaryTree 
{
public:
	BinaryNode * root;

	bool isFull()
	{
		return isFull(root);
	}

	bool isFull(BinaryNode* node)
	{
		if (node == nullptr)
		{
			return true;
		}

		if (node->left != nullptr && node->right != nullptr)
		{
			//two children, recursive call
			return isFull(node->left) && isFull(node->right);
		}
		else if (node->left == nullptr && node->right == nullptr)
		{
			//no children
			return true;
		}
		else
		{
			//1 child
			return false;
		}
	}
};

//general format for recursive tree functions
//1. At minimum, they tend to have a BinaryNode as an input
//   parameter.  
//1a.Almost always, perform a null check
//2. In the function, some amount of work is done
//3. After the work, a recursive call to the same function 
//   happens.
bool isFull(BinaryNode* node)
{
	if (node == nullptr)
	{
		return true;
	}

	if (node->left != nullptr && node->right != nullptr)
	{
		//two children, recursive call
		return isFull(node->left) && isFull(node->right);
	}
	else if (node->left == nullptr && node->right == nullptr)
	{
		//no children
		return true;
	}
	else
	{
		//1 child
		return false;
	}
}

int sumTree(BinaryNode* node)
{
	if (node == nullptr)
	{
		return 0;
	}
	return 
		  sumTree(node->left) 
		+ sumTree(node->right) 
		+ node->value;
}

int main(void)
{
	srand(time(NULL));

	BinaryNode* root = new BinaryNode{ 5 };
	root->left = new BinaryNode{ 1 };
	root->left->left = new BinaryNode{ 0 };
	root->left->right = new BinaryNode{ 4 };
	root->left->right->right = new BinaryNode{ 9 };
	root->right = new BinaryNode{ 12 };
	root->right->left = new BinaryNode{ 6 };
	root->right->right = new BinaryNode{ 2 };
	root->right->right->left = new BinaryNode{ 3 };
	root->right->right->right = new BinaryNode{ 7 };

	BinaryTree tree{};
	tree.root = root;
	cout << tree.isFull() << endl;
	cout << root->isFull() << endl;
	cout << isFull(root) << endl;

	cout << sumTree(root);
	return 0;
}