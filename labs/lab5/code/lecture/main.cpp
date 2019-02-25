#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib> 
#include <list>
#include <stack>
using namespace std;

int main(void) 
{
	//define new stack
	stack<int> numbers{};

	//add 5 numbers to the stack
	for (int i = 0; i < 5; i++)
	{
		numbers.push(i);
	}

	//remove the numbers from the stack
	while (numbers.size() > 0)
	{
		//.top grabs next element
		int next = numbers.top();

		//.pop removes the element from the stack
		numbers.pop();

		cout << next << endl;
	}

	return 0;
}