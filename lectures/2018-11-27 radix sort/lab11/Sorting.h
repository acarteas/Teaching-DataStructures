#pragma once
#ifndef SORTING_H
#define SORTING_H
#include <vector>
#include <cmath>
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

void selectionSort(vector<int>& data)
{
    for (int i = 0; i < data.size(); i++)
    {
        //find the smallest item in the unsorted section
        int smallest_index = i;
        for (int j = i + 1; j < data.size(); j++)
        {
            if (data[j] < data[smallest_index])
            {
                smallest_index = j;
            }
        }

        //we know for sure where the next smallest item is located
        //we also know where it needs to go in the array (index i)
        int temp = data[i];
        data[i] = data[smallest_index];
        data[smallest_index] = temp;
    }
}

//C++ 11-style swap, taken from Stroustrup's book
void swap(vector<int>& data, int from, int to)
{
    int& left = data[from];
    int& right = data[to];
    int temp{static_cast<int&&>(left)};
    left = static_cast<int&&>(right);
    right = static_cast<int&&>(temp);
}
void mergeSortHelper(vector<int>& data, int start_bound, int end_bound);
void mergeSort(vector<int>& data)
{
    mergeSortHelper(data, 0, data.size() - 1);
}

void mergeSortHelper(vector<int>& data, int start_bound, int end_bound)
{
    //base case #1: array of size 1
    if (end_bound - start_bound == 0)
    {
        //array of size 1 is sorted.  Do nothing!
        return;
    }
    else if (end_bound - start_bound == 1)
    {
        //base case #2: array of size 2
        if (data[end_bound] < data[start_bound])
        {
            swap(data, end_bound, start_bound);
        }
        return;
    }

    //recursion happens here
    int midpoint = (end_bound + start_bound) / 2;

    //ensure midpoint is okay before making recursive call
    if (start_bound < midpoint)
    {
        mergeSortHelper(data, start_bound, midpoint);
    }
    if (midpoint < end_bound)
    {
        mergeSortHelper(data, midpoint, end_bound);
    }

    //INVARIANT (we know this to be true):
    //right and left sides are sorted
    vector<int> merged{};
    int left_index = start_bound;
    int right_index = midpoint;
    while (left_index < midpoint && right_index < end_bound)
    {
        if (data[left_index] < data[right_index])
        {
            merged.push_back(data[left_index]);
            left_index++;
        }
        else
        {
            merged.push_back(data[right_index]);
            right_index++;
        }
    }

    //after the WHILE loop above breaks, three possibilities:
    //1. left_index and right_index are invalid (all data is in the merged array)
    //2. left_index is still in bounds
    //3. right_index is still in bounds
    //we must only worry about cases 2 and 3

    //case 2: more stuff in left side of array
    while (left_index < midpoint)
    {
        merged.push_back(data[left_index]);
        left_index++;
    }

    //case 3: more stuff in right side of array
    while (right_index < end_bound)
    {
        merged.push_back(data[right_index]);
        right_index++;
    }

    //finally, replace data in original array with data
    //in merged array
    for (int i = 0, j = start_bound; i < merged.size(); i++, j++)
    {
        data[j] = merged[i];
    }
}

void quickSortHelper(vector<int>& data, int start_bound, int end_bound)
{
    //base case #1: array of size 1
    if (end_bound - start_bound == 0)
    {
        //array of size 1 is sorted.  Do nothing!
        return;
    }
    else if (end_bound - start_bound == 1)
    {
        //base case #2: array of size 2
        if (data[end_bound] < data[start_bound])
        {
            swap(data, end_bound, start_bound);
        }
        return;
    }

    //find the pivot
    int pivot_index = start_bound;
    int midpoint = (start_bound + end_bound) / 2;
    int front = data[start_bound];
    int mid = data[midpoint];
    int end = data[end_bound];
    
    //is middle the best pivot
    if ( (mid > front && mid < end) || (mid < front && mid > end) )
    {
        pivot_index = midpoint;
    }
    //is end the best pivot?
    else if ((end > front && end < mid) || (end < front && end > mid))
    {
        pivot_index = end_bound;
    }

    //swap pivot with end value
    swap(data, pivot_index, end_bound);

    //set i and j
    int i = start_bound;
    int j = end_bound - 1;
    int pivot_value = data[pivot_index];

    while (i < j)
    {
        //while i < pivot, increment i
        while (data[i] < pivot_value && i < j)
        {
            i++;
        }
        //while j > pivot, decrement j
        while (data[j] > pivot_value && i < j)
        {
            j--;
        }
        if (i != j)
        {
            swap(data, i, j);
        }
    }

    //swap i and pivot
    swap(data, i, end_bound);

    //do this again recursively
    if (start_bound < i)
    {
        quickSortHelper(data, start_bound, i);
    }
    if (end_bound > i)
    {
        quickSortHelper(data, i, end_bound);
    }
}

void quickSort(vector<int>& data)
{
    quickSortHelper(data, 0, data.size() - 1);
}

void shellSort(vector<int>& data)
{
    vector<int> skip_sequence{1, 4, 10, 23, 57, 132, 301, 701, 1750, 3675, 7717, 16206, 34034, 71471};
    for (int skip_counter = skip_sequence.size() - 1; skip_counter > -1; skip_counter--)
    {
        int skip = skip_sequence[skip_counter];
        for (int i = skip; i < data.size(); i++)
        {
            for (int j = i; j > 0 && j - skip > -1; j -= skip)
            {
                if (data[j] < data[j - skip])
                {
                    swap(data, j, j - skip);
                }
            }
        }
    }
}

void radixSort(vector<int>& data)
{
    //NOTE: This won't work if all numbers have a 0 in the 0s place

    vector<vector<int>> current_buckets{};
    vector<vector<int>> next_buckets{};

    //set bucket size for both current and next to 10
    current_buckets.resize(10);
    next_buckets.resize(10);

    //put all elements in data into the first bucket of current
    for (auto item : data)
    {
        current_buckets[0].push_back(item);
    }

    int power_of_ten = 0;
    bool keep_going = true;
    while (keep_going == true)
    {
        //proof by contradiction: assume last iteration
        keep_going = false;

        int divisor = pow(10, power_of_ten);
        power_of_ten++;
        for (int i = 0; i < 10; i++)
        {
            for (auto item : current_buckets[i])
            {
                int destination_bucket = (item / divisor) % 10;

                //if destination is not a zero, then we have more sorting
                //to do
                if (destination_bucket != 0)
                {
                    keep_going = true;
                }

                //place item in next bucket
                next_buckets[destination_bucket].push_back(item);
            }
        }

        //at this point next_buckets has all of the data
        current_buckets = move(next_buckets);
        next_buckets.resize(10);

    }

    //move data in current buckets back into original array
    data = move(current_buckets[0]);
}
#endif // !SORTING_H
