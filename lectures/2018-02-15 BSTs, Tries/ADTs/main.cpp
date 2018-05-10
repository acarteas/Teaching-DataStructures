#include <iostream>
#include <string>
#include "ADTs\BinarySearchTree.h"
#include "ADTs\TreeTraversal.h"
#include "ADTs\RandomNumberGenerator.h"
#include "benchmarks\TreeBenchmark.h"

using namespace std;

int main(void)
{
    RandomNumberGenerator rng{};
    BinarySearchTree<int> *bst = nullptr;
    TreeBenchmark bm{};

    for (int i = 10000; i < 100000; i += 10000)
    {
        if (bst != nullptr)
        {
            delete bst;
        }
        bst = new BinarySearchTree<int>{};
        cout << "i: " << i << " time: " << bm.randomAddBenchmark(bst, i) << endl;
    }

    return 0;
}