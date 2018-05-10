#include <iostream>
#include <stack>
#include "StringSplitter.h"
#include <string>
#include <fstream>

using namespace std;

double evaluatePostfixExpression(string postfix_string)
{
	double result = -1;
	stack<double> postfix_stack{};
	vector<string> pieces = StringSplitter::split(postfix_string, " ");

	//TODO: evaluate pieces as a postfix expression
	for (auto piece : pieces)
	{
		//DO NOT DO THIS
		postfix_stack.push(piece[0]);

		

		//stod converts from string to double
	}

	while (postfix_stack.empty() == false)
	{
		//in STL, we use top() to get the top item, pop() returns nothing
		cout << postfix_stack.top();

		//pop is only used to remove the top-most item from the stack
		postfix_stack.pop();
	}

	return result;
}

int main(void)
{
	//prompt user for file to open
	string file_to_open;
	cout << "Enter file name: ";
	getline(cin, file_to_open);

	//open the file
	ifstream input_file{ file_to_open };

	//safety checking
	if (input_file.is_open())
	{
		//read from the file as long as more content is available
		while (input_file.good())
		{
			string current_line;
			getline(input_file, current_line);
			double result = evaluatePostfixExpression(current_line);
			cout << current_line << " = " << result << endl;
			
		}
	}

	return 0;
}