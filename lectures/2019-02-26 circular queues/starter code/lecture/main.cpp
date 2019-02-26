#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib> 
#include <list>
#include "LinkedList.h"
#include "ListQueue.h"
#include "VectorQueue.h"
#include "CircularQueue.h"
#include "QueueBenchmark.h"
#include "StlQueue.h"
using namespace std;

/*
AGENDA:
   
   *Implement CircularQueue structure
   *Benchmark differences
   *Create a wrapper for STL queue
*/
int main(void) 
{
	ListQueue<int> ll_q{};
	VectorQueue<int> v_q{};
	CircularQueue<int> cq{};
	StlQueue<int> stl_queue{};
	QueueBenchmark bench{};

	//Adam's fancy way to help us not know what we're doing when we
	//benchmark
	vector<pair<Queue<int>*, string>> queues{};
	queues.push_back(make_pair(&ll_q, "LL Queue"));
	queues.push_back(make_pair(&v_q, "Vector Queue"));
	queues.push_back(make_pair(&cq, "Circular Queue"));
	queues.push_back(make_pair(&stl_queue, "STL Queue"));

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