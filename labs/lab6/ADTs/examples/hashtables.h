#ifndef EXAMPLES_H
#define EXAMPLES_H

#include <string>
#include <chrono>
#include <sstream>
#include <iostream>
#include "../ADTs/LinearHashTable.h"
#include "../ADTs/BucketHashTable.h"
#include "../ADTs/QuadraticHashTable.h"
#include "../ADTs/DoubleHashTable.h"

using namespace std;
using namespace std::chrono;  //for benchmarks
void hashtableUsageExample()
{
    LinearHashTable<string, int> lht{ new SimpleStringHasher{} };
    BucketHashTable<string, int> bht{ new SimpleStringHasher{} };
    QuadraticHashTable<string, int> qht{ new SimpleStringHasher{} };
    DoubleHashTable<string, int> dht{ new SimpleStringHasher{} };

    lht.addElement("foo", 1);
}

long long exampleBenchmark(HashTableBase<string, string> &ht, int num_inputs)
{
    //set up clock variables
    system_clock::time_point start;
    system_clock::time_point end;

	//pre modifications go here

    //benchmark clock begins as soon as this line finishes
    start = system_clock::now();

	//add a bunch of items to the HT
	for (int i = 0; i < num_inputs; i++)
	{
		//build key
		ostringstream temp{};
		for (int j = 0; j < 3; j++)
		{
			temp << i;
		}
		string key = temp.str();

		//put key into hashtable
		ht.addElement(key, key);
	}

    //end clock as soon as benchmark is complete
    end = system_clock::now();

    //return duration in milliseconds
    return duration_cast<milliseconds>(end - start).count();
}

#endif // !EXAMPLES_H
