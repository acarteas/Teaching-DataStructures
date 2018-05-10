#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include "sorting\Sorting.h"
#include "ADTs\Vector.h"
#include "ADTs\RandomNumberGenerator.h"
#include "benchmarks\SortingBenchmark.h"

using namespace std;

int main(void)
{
    Vector<int> data{};
    RandomNumberGenerator rng{};
    SortingBenchmark bm{};
    /*
    for (int i = 0; i < 500; i++)
    {
        data.addElement(rng.getRandomNumber(1, 100));
    }
    */
    BubbleSort<int> sort{};
    cout << bm.sortPreSortedBenchmark(&sort, &data, 5000) << endl;
    /*
    sort.sort(data);
    for (int i = 0; i < data.getSize(); i++)
    {
        cout << data[i] << " ";
    }
    */

    cout << endl;
    return 0;
}