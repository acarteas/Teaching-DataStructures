#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib> 
#include <list>
#include "LinkedList.h"
#include "ListQueue.h"
#include "VectorQueue.h"
#include "QueueBenchmark.h"
using namespace std;

/*
AGENDA:
   *Implement removeAt() for our LL
   *Implement queue() using our LL
   *Implement queue() using STL vector
   *Benchmark differences
   *Implement CircularQueue structure
*/
int main(void) 
{
	ListQueue<int> ll_q{};
	VectorQueue<int> v_q{};
	QueueBenchmark bench{};

	//Adam's fancy way to help us not know what we're doing when we
	//benchmark
	vector<pair<Queue<int>*, string>> queues{};
	queues.push_back(make_pair(&ll_q, "LL Queue"));
	queues.push_back(make_pair(&v_q, "Vector Queue"));

	ofstream output{ "output.csv" };

	for (int i = 5000; i <= 100000; i += 5000)
	{
		for (auto queue : queues)
		{
			output << bench.simpleBenchmark(queue.first, i) << ",";
			/*
			cout << queue.second << " on " << i << ": " 
				 << bench.simpleBenchmark(queue.first, i) << endl;
				 */
		}
		output << endl;
	}

	output.close();

	return 0;
}