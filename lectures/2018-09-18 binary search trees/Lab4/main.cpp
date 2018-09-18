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

};

void addElement(BinaryNode* node, int value)
{
    if (node == nullptr)
    {
        return;
    }

    if (node->value > value)
    {
        //left
        if (node->left == nullptr)
        {
            node->left = new BinaryNode{ value };
        }
        else
        {
            addElement(node->left, value);
        }
    }
    else
    {
        //right
        if (node->right == nullptr)
        {
            node->right = new BinaryNode{ value };
        }
        else
        {
            addElement(node->right, value);
        }
    }
}

BinaryNode* addElementV2(int value)
{
    return addElementV2(nullptr, value);
}

BinaryNode* addElementV2(BinaryNode* node, int value)
{
    if (node == nullptr)
    {
        node = new BinaryNode{ value };
        return node;
    }

    if (node->value > value)
    {
        node->left = addElementV2(node->left, value);
    }
    else
    {
        node->right = addElementV2(node->right, value);
    }
    return node;
}

int main(void)
{
	srand(time(NULL));

	BinaryNode* root = new BinaryNode{ 100 };
    addElement(root, 50);
    addElement(root, 25);

    BinaryNode* tree1 = addElementV2(100);
    addElementV2(tree1, 50);
    addElementV2(tree1, 25);

	return 0;
}