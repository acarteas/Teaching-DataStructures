#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib> 
#include "Vector.h"
using namespace std;

/*
Agenda for 2019-02-05
   1. Introduce PA #2
   2. Implement custom Vector class

   swap, erase, for auto loop, clear, find
*/
int main(void)
{
   //Vector<int> numbers{};
   //Vector<int> foo = numbers; //copy operator
   //Vector<int> foo1{ numbers }; //copy constructor
   //Vector<int> foo2 = Vector<int>{ 1234 }; //move opeartor
   //Vector<int> foo3{ Vector<int>{1234} }; //move constructor

	srand(time(NULL));
	Vector<int> numbers{};
	for (int i = 0; i < 15; i++)
	{
		numbers.push_back(i);
	}
	for (int i = 0; i < numbers.size(); i++)
	{
		cout << numbers[i] << endl;
	}

	return 0;
}