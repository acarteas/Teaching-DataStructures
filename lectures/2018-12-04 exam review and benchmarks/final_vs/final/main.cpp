#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <string>
#include <functional>
using namespace std;

class BinaryNode {
public:
    int value;
    BinaryNode *left = nullptr;
    BinaryNode *right = nullptr;
    BinaryNode(int v = 0) {
        value = v;
    }
};


/*
1.  Write a function that sorts an array using Bubble Sort.
*/
void bubbleSort(int* numbers, int size)
{

}

/*
2. Implement a function that parses the supplied vector of integers representing rainfall data and returns the day(as a string) that has the most rain.The input vector is formatted such that index 0 represents Sunday and every 7th item is the same day.Thus:
•	0, 7, 14… is a Sunday
•	1, 8, 15… is a Monday
•	2, 9, 16… is a Tuesday
•	Etc.
*/
string dayWithMostRain(vector<int> rainfall)
{
    return "none";
}

//3. Write a function called bstToVector that returns the supplied binary search tree into a sorted STL vector. 
vector<int> bstToVector(BinaryNode* node)
{
    vector<int> result{};
    return result;
}

//4. Complete the function isBst() such that the function returns TRUE when the supplied node represents a valid BST and FALSE otherwise.
bool isBst(BinaryNode* node)
{
    return false;
}

//5. Write a function called findMostCommon that finds the most commonly used character in the supplied string.
char findMostCommon(string text)
{
    return 'z';
}

/*
6.  Complete the function fizzbuzz() that returns a vector of size N (supplied input parameter) having values from 0 to N.  
However, when the index is divisible by 3, instead write "fizz".  When the index is divisible by 5, instead write "buzz".  
When the number is divisible by both 3 and 5, write "fizzbuzz" to that index.  For example, when N = 16, your vector 
should contain: 0, 1, 2, fizz, 4, buzz, fizz, 7, 8, fizz, buzz, 11, fizz, 13, 14, fizzbuzz
*/
vector<string> fizzbuzz(int n)
{
    vector<string> result{};
    return result;
}

int main(void)
{
    //task #1
    cout << "Task #1" << endl;
    vector<int> numbers{10, 8, 7, 5, 3, 2, 9, 10, 1, -1, 12, 13, 2, 15, 15, 6};
    bubbleSort(&numbers[0], numbers.size());
    for (auto i : numbers)
    {
        cout << i << " ";
    }
    cout << endl << endl;


    //task #2
    vector<int> data = { 1, 1, 1, 1, 1, 1, 1,
                        1, 2, 1, 3, 2, 4, 3,
                        3, 0, 2, 1, 2, 1, 0,
                        4, 1, 1, 1, 1, 1, 3,
                        0, 0, 0, 1, 1, 0, 2,
                        1, 2, 1, 2, 1, 2, 1 };
    cout << "Day with most rain: " << dayWithMostRain(data) << " (expected: Saturday)";
    cout << endl << endl;
    
    //task #3
    cout << "Task #3" << endl;
    //presently not a BST
    BinaryNode* root1 = new BinaryNode{ 10 };
    root1->left = new BinaryNode{ 5 };
    root1->left->left = new BinaryNode{ 1 };
    root1->left->right = new BinaryNode{ 3 };
    root1->left->right->right = new BinaryNode{ 9 };
    root1->right = new BinaryNode{ 15 };
    root1->right->right = new BinaryNode{ 25 };
    root1->right->left = new BinaryNode{ 12 };
    root1->right->right->right = new BinaryNode{ 35 };
    root1->right->right->left = new BinaryNode{ 20 };

    cout << "isBst: " << isBst(root1) << " (expected: false)" << endl;

    //Now, the tree is a valid BST
    root1->left->right->value = 7;
    cout << "isBst: " << isBst(root1) << " (expected: true)" << endl;

    //Now, the tree is not BST
    root1->right->right->left->right = new BinaryNode{ 11 };
    cout << "isBst: " << isBst(root1) << " (expected: false)" << endl;

    //Now, the tree is BST
    root1->right->right->left->right->value = 22;
    root1->right->left->right = new BinaryNode{ 14 };
    cout << "isBst: " << isBst(root1) << " (expected: true)" << endl;
    cout << endl << endl;

    //task #4
    cout << "Task #4" << endl;
    vector<int> result = bstToVector(root1);
    for (auto i : result)
    {
        cout << i << " ";
    }
    cout << endl << endl;

    //task #5
    cout << "Task #5" << endl;
    cout << "find most common: " << findMostCommon("abcaba") << " (expected: a)" << endl;
    cout << "find most common: " << findMostCommon("racecarr") << " (expected: r)" << endl;
    cout << endl << endl;

    //task #6
    vector<string> fb = fizzbuzz(100);
    if (fb.size() > 100)
    {
        cout << "fizzbuzz: [0] = " << fb[0] << "  [12] = " << fb[12] << "  [20] = " << fb[20] << "  [30] = " << fb[30] <<
            "  [98] = " << fb[98] << endl;
        cout << "expected: [0] = fizzbuzz  [12] = fizz  [20] = buzz  [30] = fizzbuzz  [98] = 98" << endl;
        cout << endl;
    }
    else
    {
        cout << "Fizzbuzz not attempted." << endl << endl;
    }
    cout << endl << endl;
    return 0;
}