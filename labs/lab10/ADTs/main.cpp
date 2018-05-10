#include <iostream>
#include "examples\hashtables.h"
using namespace std;
int main(void)
{
	BucketHashTable<string, string> bht{ new SimpleStringHasher{} };
	LinearHashTable<string, string> lht{ new SimpleStringHasher{} };
	DoubleHashTable<string, string> dht{ new SimpleStringHasher{} };

	cout << "Running bucket hash on 1000 elements: "
		<< exampleBenchmark(bht, 1000) << endl;
	cout << "Running linear hash on 1000 elements: "
		<< exampleBenchmark(lht, 1000) << endl;
	cout << "Running double hash on 1000 elements: "
		<< exampleBenchmark(dht, 1000) << endl;


	for (auto item : bht.getKeys())
	{
		cout << item << endl;
	}
    return 0;
}