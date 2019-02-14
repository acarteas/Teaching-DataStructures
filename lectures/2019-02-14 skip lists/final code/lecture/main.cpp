#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib> 
#include <list>
#include "LinkedList.h"
#include "SkipNode.h"
using namespace std;

int main(void)
{
	//STL LL example
	list<int> numbers{};
	for (int i = 0; i < 10; i++)
	{
		numbers.push_back(i);
	}

	//our LL
	LinkedList<int> our_ll{};
	for (int i = 0; i < 10; i++)
	{
		our_ll.push_back(i);
	}

	//not allowed with STL LL
	/*for (int i = 0; i < numbers.size(); i++)
	{
		cout << numbers[i] << endl;
	}*/
	for (auto item : numbers)
	{
		cout << item << endl;
	}

	for (int i = 0; i < our_ll.size(); i++)
	{
		cout << our_ll[i] << endl;
	}

	return 0;
}