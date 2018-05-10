#pragma once
#ifndef SORTING_BENCHMARK_H
#define SORTING_BENCHMARK_H

#include <chrono>
#include "../sorting/IndexedSort.h"
#include "../ADTs/RandomNumberGenerator.h"
using namespace std;
using namespace std;
using namespace std::chrono;
class SortingBenchmark
{
public:
    long long emptyBenchmark(IndexedSort<int> *sort, Indexed<int> *data)
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

    long long sortBenchmark(IndexedSort<int> *sort, Indexed<int> *data, int num_trials)
    {
        //setup our stopwatches
        system_clock::time_point start;
        system_clock::time_point end;

        //TODO: any pre-setup
        RandomNumberGenerator rng{};
        for (int i = 0; i < num_trials; i++)
        {
            data->addElement(rng.getRandomNumber());
        }

        //begin benchmark
        start = system_clock::now();

        //TODO: benchmark
        sort->sort(*data);

        //stop timer
        end = system_clock::now();

        //return duration in milliseconds
        return duration_cast<milliseconds>(end - start).count();
    }

    long long sortPreSortedBenchmark(IndexedSort<int> *sort, Indexed<int> *data, int num_trials)
    {
        //setup our stopwatches
        system_clock::time_point start;
        system_clock::time_point end;

        //TODO: any pre-setup
        RandomNumberGenerator rng{};
        for (int i = 0; i < num_trials; i++)
        {
            data->addElement(i);
        }

        //begin benchmark
        start = system_clock::now();

        //TODO: benchmark
        sort->sort(*data);

        //stop timer
        end = system_clock::now();

        //return duration in milliseconds
        return duration_cast<milliseconds>(end - start).count();
    }

    long long sortReverseSortedBenchmark(IndexedSort<int> *sort, Indexed<int> *data, int num_trials)
    {
        //setup our stopwatches
        system_clock::time_point start;
        system_clock::time_point end;

        //TODO: any pre-setup
        RandomNumberGenerator rng{};
        for (int i = 0; i < num_trials; i++)
        {
            data->addElement(num_trials - i);
        }

        //begin benchmark
        start = system_clock::now();

        //TODO: benchmark
        sort->sort(*data);

        //stop timer
        end = system_clock::now();

        //return duration in milliseconds
        return duration_cast<milliseconds>(end - start).count();
    }

};

#endif // !QUEUE_BENCHMARK_H
