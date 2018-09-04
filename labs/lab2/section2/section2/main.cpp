#include <vector>
#include <string>
#include <fstream>
#include <iostream>
using namespace std;
/*
In this task, you will read an indeterminate number 
of numbers from the user. Continue this process until 
you encounter any negative number. Once this occurs, 
output the average of the series. We will use this 
task to learn more about vectors and obtaining data 
from a file.
*/
void task1()
{
	cout << "Enter a series of numbers: " << endl;
	int user_input = 0;
	vector<int> numbers{};
	cin >> user_input;
	while (user_input >= 0)
	{
		numbers.push_back(user_input);
		cin >> user_input;
	} 

	int total = 0;

	//Classic C++ - works only for vector data
	//structure
	for (int i = 0; i < numbers.size(); i++)
	{
		total += numbers[i];
	}

	//Modern C++ - works for all data structures
	total = 0;  //reset total for this example
	for (auto item : numbers)
	{
		total += item;
	}

	cout << "AVG: " << total * 1.0 / numbers.size() << endl;
}

void task2()
{
	ifstream data{ "inventory.csv" };
	if (data.is_open() == true)
	{
		while (data.good() == true)
		{
			string line;
			getline(data, line, ',');
			cout << line << endl;
            getline(data, line, ',');
            cout << line << endl;
            getline(data, line);
            cout << line << endl;
		}
	}
	data.close();
}

void removeRed(vector<int>& colors)
{
	for (int i = 0; i < colors.size(); i += 3)
	{
		colors[i] = 0;
	}
}

void processPPM()
{
	vector<string> header{};
	vector<int> colors{};
	cout << "Enter PPM file: ";
	string ppm_file_name;
	cin >> ppm_file_name;

	ifstream picture_file{ ppm_file_name };
	if (picture_file.is_open() == true)
	{
		string line;
		for (int i = 0; i < 3; i++)
		{
			getline(picture_file, line);
			header.push_back(line);
		}
		while (picture_file.good() == true)
		{
			//problems encountered with getline:
			//1. Some extra whitespace before number
			//   (e.g. '       123')
			//2. Some blank lines
			getline(picture_file, line, ' ');

			//attempt to address issue #2
			if (line.size() > 0)
			{
				//attempt to address issue #2
				if (line != "\n")
				{
					//converting to a number addresses
					//#1
					int number = stoi(line);
					colors.push_back(number);
				}
			}
		}
	}
	picture_file.close();
	removeRed(colors);

	ofstream output{ "output.ppm" };
	for (auto item : header)
	{
		output << item << endl;
	}
	for (auto item : colors)
	{
		output << item << endl;
	}
	output.close();

}

int main(void)
{
	//task1();
	task2();
	//processPPM();
}