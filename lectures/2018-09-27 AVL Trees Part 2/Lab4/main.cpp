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
    int height = 0;

	BinaryNode(int v = 0, int h = 0)
	{
		value = v;
        height = h;
	}

    int getBalanceFactor()
    {
        //BF is RH - LH
        int right_height = 0;
        int left_height = 0;
        if (right != nullptr)
        {
            right_height = right->height;
        }
        if (left != nullptr)
        {
            left_height = left->height;
        }
        return right_height - left_height;
    }

};

BinaryNode* rotateRight(BinaryNode* original_root)
{
    if (original_root == nullptr)
    {
        return original_root;
    }
    BinaryNode* new_root = original_root->left;
    original_root->left = new_root->right;
    new_root->right = original_root;

    //recalculate heights of each
    original_root = setHeight(original_root);
    new_root = setHeight(new_root);
    return new_root;

}

BinaryNode* balance(BinaryNode* node)
{
    if (node == nullptr)
    {
        return node;
    }

    //Node NEEDS to be balanced
    //What direction do we need to rotate
    if (node->getBalanceFactor() < 0)
    {
        //right rotation
        if (node->left != nullptr && node->left->getBalanceFactor() > 0)
        {
            //rotate left at NR
        }

        //rotate right at OR
    }
    else
    {
        //left rotation
        if (node->right != nullptr && node->right->getBalanceFactor() < 0)
        {
            //rotate right at NR
        }
        //rotate left at OR
    }
}

BinaryNode* setHeight(BinaryNode* node)
{
    if (node == nullptr)
    {
        return node;
    }

    int right_height = -1;
    int left_height = -1;
    if (node->right != nullptr)
    {
        right_height = node->right->height;
    }
    if (node->left != nullptr)
    {
        left_height = node->left->height;
    }
    int height = 1 + (left_height < right_height) ? right_height : left_height;
    node->height = height;
    

    //check balance factor
    int balance_factor = node->getBalanceFactor();
    if (balance_factor > 1 || balance_factor < -1)
    {
        return balance(node);
    }
    return node;
}

BinaryNode* addElement(int value)
{
    return addElement(nullptr, value);
}

BinaryNode* addElement(BinaryNode* node, int value)
{
    if (node == nullptr)
    {
        node = new BinaryNode{ value };
        return node;
    }

    if (node->value > value)
    {
        node->left = addElement(node->left, value);
    }
    else
    {
        node->right = addElement(node->right, value);
    }
    return setHeight(node);
}

int main(void)
{
	srand(time(NULL));

	BinaryNode* root = new BinaryNode{ 100 };
    addElement(root, 50);
    addElement(root, 25);

    BinaryNode* tree1 = addElement(100);
    addElement(tree1, 50);
    addElement(tree1, 25);

	return 0;
}