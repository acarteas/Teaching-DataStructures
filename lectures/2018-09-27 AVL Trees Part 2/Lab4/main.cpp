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
    return node;
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