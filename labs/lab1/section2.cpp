#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(void)
{	
	//track number of items in our array
	int* numbers = nullptr;
	int number_of_items = 0;

	//1. prompt user for file to open
	string file_to_open;
	cout << "Enter file name: ";
	getline(cin, file_to_open);

	//2. Use string to open an actual file
	ifstream input_file{ file_to_open };

	//3. Read numbers from file
	if (input_file.is_open() == true)
	{
		//good means while there's still stuff to read
		while (input_file.good() == true)
		{
			number_of_items++;
			string line;
			getline(input_file, line);
		}

		//at this point, we know how large our array
		//must be.
		numbers = new int[number_of_items];

		//reset file 
		input_file.seekg(0);

		//Now, copy data from file into array
		number_of_items = 0;
		while (input_file.good() == true)
		{
			string line;
			getline(input_file, line);

			//Modern C++ way
			numbers[number_of_items] = stoi(line);

			//Classic C++ way
			numbers[number_of_items] = atoi(line.c_str());

			number_of_items++;
		}
	}
	
	//4. Order values in ascending value (sort)
	//MAY BE WRONG
	for (int i = number_of_items - 1; i > 0; i--)
	{
		for (int j = 0; j < i - 1; j++)
		{
			if (numbers[j] > numbers[j + 1])
			{
				int temp = numbers[j];
				numbers[j] = numbers[j + 1];
				numbers[j + 1] = temp;
			}
		}
	}

	//5. IF array size is even
	if (number_of_items % 2 == 0)
	{
		//	a. return average of middle two-most numbers
		int mid = (number_of_items - 1) / 2;
		double avg =
			(numbers[mid] + numbers[mid + 1]) / 2.0;
		cout << avg << endl;
	}
	else
	{
		//odd //	a. return middle most number
		cout << numbers[(number_of_items - 1) / 2] << endl;
	}
	return 0;
}