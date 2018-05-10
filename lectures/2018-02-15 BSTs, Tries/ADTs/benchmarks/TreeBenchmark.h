#pragma once
#ifndef TREE_BENCHMARK_H
#define TREE_BENCHMARK_H

#include <chrono>
#include "../ADTs/BinarySearchTree.h"
#include "../ADTs/RandomNumberGenerator.h"
using namespace std;
using namespace std;
using namespace std::chrono;
class TreeBenchmark
{
public:
    long long emptyBenchmark(BinarySearchTree<int> *queue)
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

    long long randomAddBenchmark(BinarySearchTree<int> *bst, int num_trials)
    {
        //setup our stopwatches
        system_clock::time_point start;
        system_clock::time_point end;

        //TODO: any pre-setup
        RandomNumberGenerator rng{};

        //begin benchmark
        start = system_clock::now();

        //TODO: benchmark
        for (int i = 0; i < num_trials; i++)
        {
            bst->addElement(rng.getRandomNumber());
        }


        //stop timer
        end = system_clock::now();

        //return duration in milliseconds
        return duration_cast<milliseconds>(end - start).count();
    }
};

#endif // !QUEUE_BENCHMARK_H
