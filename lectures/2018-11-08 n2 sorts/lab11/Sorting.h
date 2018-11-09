#pragma once
#ifndef SORTING_H
#define SORTING_H
#include <vector>
using namespace std;

void insertionSort(vector<int>& data)
{
    //general idea: start with a sorted set of size 1, progressively
    //add one new element to the sorted set.  Reorganize as needed.
    for (int i = 1; i < data.size(); i++)
    {
        for (int j = i; j > 0 && data[j] < data[j - 1]; j--)
        {
            //swap
            int temp = data[j];
            data[j] = data[j - 1];
            data[j - 1] = temp;
        }
    }
}

void bubbleSort(vector<int>& data)
{
    //until sorted: bubble the largest item to the end of the array
    //note: does not include short circuit logic
    for (int i = 0; i < data.size(); i++)
    {
        for (int j = 0; j < data.size() - i - 1; j++)
        {
            if (data[j] > data[j + 1])
            {
                int temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
}
#endif // !SORTING_H
