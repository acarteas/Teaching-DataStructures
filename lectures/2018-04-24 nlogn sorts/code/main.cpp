#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include "sorting\Sorting.h"
#include "ADTs\Vector.h"
#include "ADTs\RandomNumberGenerator.h"
#include "benchmarks\SortingBenchmark.h"
#include <unordered_map>

using namespace std;

int main(void)
{
    Vector<int> data{};
    RandomNumberGenerator rng{};
    SortingBenchmark bm{};
    InsertionSort<int> insertion_sort{};
    BubbleSort<int> bubble_sort{};
    SelectionSort<int> selection_sort{};
    ShellSort<int> shell_sort{};
    MergeSort<int> merge_sort{};
    unordered_map<string, IndexedSort<int>*> sorters{};
    for (int i = 0; i < 500; i++)
    {
        data.addElement(rng.getRandomNumber(1, 100));
    }
    
    /*
    merge_sort.sort(data);
    for (int i = 0; i < data.getSize(); i++)
    {
    cout << data[i] << " ";
    }
    return 0;
    */
    
    sorters["Insertion Sort"] = &insertion_sort;
    sorters["Bubble Sort"] = &bubble_sort;
    sorters["Selection Sort"] = &selection_sort;
    sorters["Shell Sort"] = &shell_sort;
    sorters["Merge Sort"] = &merge_sort;
    for (int i = 5000; i <= 20000; i += 5000)
    {
        for (auto sorter : sorters)
        {
            cout << sorter.first << " on: " << i << " elements: "
                << bm.sortBenchmark(sorter.second, &data, i) << endl;
        }
        cout << endl;
        
    }
    

    cout << endl;
    return 0;
}