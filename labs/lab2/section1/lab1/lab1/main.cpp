#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

/*
In this task, you will read an indeterminate number of 
numbers from the user. Continue this process until you 
encounter any negative number. Once this occurs, output 
the average of the series. We will use this task to learn 
more about vectors and obtaining data from a file.
*/
void task1()
{
	//contains full list of numbers
	vector<int> numbers{};
	int current_number = 0;
	do
	{
		cin >> current_number;
		if (current_number > -1)
		{
			numbers.push_back(current_number);
		}
	} while (current_number >= 0);

	//sum values (only works for vectors)
	int total = 0;
	for (int i = 0; i < numbers.size(); i++)
	{
		total += numbers[i];
	}

	//sum values using c++ 11 syntax
	//preferred way for most data structures
	total = 0;
	for (auto item : numbers)
	{
		total += item;
	}

	cout << total / (numbers.size() * 1.0) << endl;
}

//starter code for parsing PA #1 csv file
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
		}
	}
}

void removeRed(vector<int> &data)
{
	for (int i = 0; i < data.size(); i += 3)
	{
		data[i] = 0;
	}
}

//IF value > 127 THEN set value = 255
//ELSE set value to 0

void secret(vector<int> &data)
{
	//Replace each RGB pixel (group of 3 values)
	//with the AVERAGE of the three values.
	//So, if R = 0, G = 100, B = 200
	//Now    R = 100, G = 100, B = 100
}

void manipulatePPM()
{
	string file_name;
	cout << "Enter file name: ";
	cin >> file_name;

	vector<string> header{};
	vector<int> color_data{};

	ifstream picture{ file_name };
	if (picture.is_open() == true)
	{
		string line;

		//processes header
		for (int i = 0; i < 3; i++)
		{
			getline(picture, line);
			header.push_back(line);
		}
		while (picture.good() == true)
		{	
			int number = -1;
			picture >> number;

			//add to color data
			color_data.push_back(number);
		}
	}

	//close input file
	picture.close();

	//remove red from image
	removeRed(color_data);

	//write back to file
	ofstream output{ "output.ppm" };

	//write back header data
	for (auto item : header)
	{
		output << item << endl;
	}

	//write back color data
	for (auto item : color_data)
	{
		output << item << endl;
	}
	output.close();

}

int main(void)
{
	//task1();
	//task2();
	manipulatePPM();
}