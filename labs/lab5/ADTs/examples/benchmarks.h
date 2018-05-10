#pragma once
#ifndef BENCHMARKS_H
#define BENCHMARKS_H
#include "ADTs\Vector.h"
#include "ADTs\LinkedList.h"
#include "ADTs\QueueAdapter.h"
#include "ADTs\CircularQueue.h"
#include "benchmarks\QueueBenchmark.h"
#include <iostream>
#include <string>
using namespace std;
void queueBenchmarks()
{
    QueueAdapter<int> vq{ new Vector<int>{} };
    QueueAdapter<int> lq{ new LinkedList<int>{} };
    CircularQueue<int> cq{};
    string names[] = { "Vector", "Linked List", "Circular" };
    QueueBenchmark bm{};
    Queue<int> *queues[] = { &vq, &lq, &cq };
    for (int i = 0; i < 3; i++)
    {
        cout << names[i] << endl;
        for (int j = 10; j < 60; j += 10)
        {
            cout << "\tj: " << j
                << " time: " << bm.sequentialOperationBenchmark(queues[i], j)
                << endl;
        }
    }
}

#endif // !BENCHMARKS_H
