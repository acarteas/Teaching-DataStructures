#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib> 
#include <vector>
#include "Vector.h"
using namespace std;

/*
Agenda for 2019-02-07
   swap, erase, for auto loop, clear, find
*/
int main(void)
{

	srand(time(NULL));
	Vector<int> numbers{};
	for (int i = 0; i < 15; i++)
	{
		numbers.push_back(i);
	}
	numbers.erase(numbers.begin() + 2);
	for (auto item : numbers)
	{
		cout << item << endl;
	}

	Vector<int> foo{};
	//foo = numbers; //copy operator
	//Vector<int> foo1{ numbers }; //copy constructor
	//foo1 = Vector<int>{  }; //move operator
	//Vector<int> foo3{ Vector<int>{} }; //move constructor
	//Vector<int>::swap(numbers, foo);

	vector<int> stl_vector{ 1, 2,3, 4, 5, 6, 7, 8,9, 10 };

	//old classic C++ style to do a FOR loop without I
	vector<int>::const_iterator start = stl_vector.begin();
	for (start; start != stl_vector.end(); start++)
	{
		cout << *start;
	}

	//versus modern C++
	for (auto item : stl_vector)
	{
		cout << item;
	}

	return 0;
}