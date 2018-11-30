#include <vector>
#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <unordered_map>
#include <queue>
#include <utility>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

long long sortBenchmark(vector<int> data, void(*sort)(vector<int>&))
{
    system_clock::time_point start;
    system_clock::time_point end;

    //start the benchmark
    start = system_clock::now();

    //do sorting
    sort(data);

    //end benchmark
    end = system_clock::now();

    long long duration = duration_cast<milliseconds>(end - start).count();
    return duration;
}

#include "Sorting.h"
typedef void(*GenericSort)(vector<int>&);
int main(void)
{
   /*
   AGENDA:
      Implement HeapSort
      Benchmark all sorting algorithms
      //void (*sort)(vector<int>&)
   */
    //srand(time(NULL));
    vector<int> numbers{};
    for (int i = 0; i < 2000; i++)
    {
        numbers.push_back(rand());
    }
    vector<int> simple{ 3, 1, 6, 5, 8, 7 };
    unordered_map<string, GenericSort> sorting_algorithms{};
    //sorting_algorithms["Insertion Sort"] = &insertionSort;
    //sorting_algorithms["Bubble Sort"] = &bubbleSort;
    //sorting_algorithms["Selection Sort"] = &selectionSort;
    //sorting_algorithms["Merge Sort"] = &mergeSort;
    sorting_algorithms["Quick Sort"] = &quickSort;
    //sorting_algorithms["Shell Sort"] = &shellSort;
    //sorting_algorithms["Radix Sort"] = &radixSort;
    //sorting_algorithms["Heap Sort"] = &heapSort;

    vector<vector<int>> things_to_sort{};
    int counter = 0;
    for (int i = 1000; i <= 5000; i += 1000)
    {
        things_to_sort.push_back(vector<int>{});
        for (int j = 0; j < i; j++)
        {
            things_to_sort[counter].push_back(rand());
        }
        counter++;
    }

    for (auto sorter : sorting_algorithms)
    {
        cout << sorter.first << endl;
        for (auto data : things_to_sort)
        {
            cout << data.size() << ": " << sortBenchmark(data, sorter.second) << endl;
        }
        cout << endl;
    }
    
}