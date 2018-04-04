#pragma once
#ifndef QUEUE_BENCHMARK_H
#define QUEUE_BENCHMARK_H

#include <chrono>
#include "../ADTs/Queue.h"
using namespace std;
using namespace std;
using namespace std::chrono;
class QueueBenchmark
{
public:
    long long emptyBenchmark(Queue<int> *queue)
    {
        //setup our stopwatches
        system_clock::time_point start;
        system_clock::time_point end;

        //TODO: any pre-setup

        //begin benchmark
        start = system_clock::now();

        //TODO: benchmark

        //stop timer
        end = system_clock::now();

        //return duration in milliseconds
        return duration_cast<milliseconds>(end - start).count();
    }

};

#endif // !QUEUE_BENCHMARK_H
