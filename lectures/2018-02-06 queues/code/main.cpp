#include <iostream>
#include <string>
#include <queue> //for BFS
#include <stack> //DFS
#include <vector>
#include "benchmarks\QueueBenchmark.h"
#include "ADTs\QueueAdapter.h"
#include "ADTs\CircularQueue.h"
#include "ADTs\Vector.h"
#include "ADTs\LinkedList.h"

using namespace std;

void doBfs(vector<int> &numbers, int starting_index)
{
    //keeps track of visited indices
    vector<bool> flags{};
    flags.resize(numbers.size());

    //be extra safe: zero out our bools
    for (auto& flag : flags)
    {
        flag = false;
    }

    //queues "run" a BFS
    queue<int> to_visit{};
    to_visit.push(starting_index);
    while (to_visit.empty() == false)
    {
        int current_index = to_visit.front();
        to_visit.pop();
        int prev_index = current_index - 1;
        int next_index = current_index + 1;

        //mark the current index as "visited"
        flags[current_index] = true;
        cout << "Examining " << numbers[current_index] << endl;

        //have we seen previous index?
        if (prev_index > -1 && flags[prev_index] == false)
        {
            to_visit.push(prev_index);
        }

        //have we seen next index?
        if (next_index < numbers.size() && flags[next_index] == false)
        {
            to_visit.push(next_index);
        }
    }
}

void doDfs(vector<int> &numbers, int starting_index)
{
    //keeps track of visited indices
    vector<bool> flags{};
    flags.resize(numbers.size());

    //be extra safe: zero out our bools
    for (auto& flag : flags)
    {
        flag = false;
    }

    //stacks "run" a DFS
    stack<int> to_visit{};
    to_visit.push(starting_index);
    while (to_visit.empty() == false)
    {
        int current_index = to_visit.top();
        to_visit.pop();
        int prev_index = current_index - 1;
        int next_index = current_index + 1;

        //mark the current index as "visited"
        flags[current_index] = true;
        cout << "Examining " << numbers[current_index] << endl;

        //have we seen previous index?
        if (prev_index > -1 && flags[prev_index] == false)
        {
            to_visit.push(prev_index);
        }

        //have we seen next index?
        if (next_index < numbers.size() && flags[next_index] == false)
        {
            to_visit.push(next_index);
        }
    }
}

void doRecursiveDfs(vector<int> &numbers, int index, vector<bool> *flags = nullptr)
{
    if (flags == nullptr)
    {
        flags = new vector<bool>{};
        flags->resize(numbers.size());
        for (auto& flag : *flags)
        {
            flag = false;
        }
    }

    cout << "Examining " << numbers[index] << endl;
    flags->at(index) = true;

    //bounds checking
    int prev_index = index - 1;
    int next_index = index + 1;
    if (prev_index > -1 && flags->at(prev_index) == false)
    {
        doRecursiveDfs(numbers, prev_index, flags);
    }
    if (next_index < numbers.size() && flags->at(next_index) == false)
    {
        doRecursiveDfs(numbers, next_index, flags);
    }
}

int main(void)
{
    vector<int> numbers{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17 };
    //doRecursiveDfs(numbers, 6);
    QueueBenchmark bm{};

    for (int i = 8000; i <= 128000; i *= 2)
    {
        QueueAdapter<int> ll_queue{ new LinkedList<int>{} };
        QueueAdapter<int> vect_queue{ new Vector<int>{} };
        CircularQueue<int> circ_queue{};

        cout << endl << "*** Size: " << i << endl;
        cout << "LL: " << bm.enqueueDequeueBenchmark(&ll_queue, i) << endl;
        cout << "Vector: " << bm.enqueueDequeueBenchmark(&vect_queue, i) << endl;
        cout << "Circular: " << bm.enqueueDequeueBenchmark(&circ_queue, i) << endl;
        cout << endl;
    }

    return 0;
}