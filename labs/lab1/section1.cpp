#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
int main(void)
{
	/*
		Store values in an array
		(array size may be an issue)
	**Order data (sorting data)
	If array size is odd
		print middlemost value
	Else
		print avg(two middle most numbers)
	*/
	int* numbers = nullptr;
	int numbers_count = 0;

	//Open a file (prompt user)
	string file_to_process;
	cout << "Enter file name: ";
	getline(cin, file_to_process);
	ifstream input_file{file_to_process};

	//Read data in from file
	if (input_file.is_open())
	{
		//figure out how many numbers are in our file
		while (input_file.good() == true)
		{
			string line;
			getline(input_file, line);
			numbers_count++;
		}

		//once here, we now will know how many
		//many numbers we have
		numbers = new int[numbers_count];

		//now, we can actually grab values from array
		input_file.seekg(0, input_file.beg);
		numbers_count = 0;
		while (input_file.good() == true)
		{
			string line;
			getline(input_file, line);

			//modern way
			numbers[numbers_count] = stoi(line);

			//old way
			numbers[numbers_count] = atoi(line.c_str());
			numbers_count++;
		}
	}

	//general idea for my sort:
	//find the smallest value, put in first slot
	//then find 2nd smallest, put in 2nd slot
	//...
	for (int i = 0; i < numbers_count; i++)
	{
		int smallest = numbers[i];
		int smallest_index = i;
		for (int j = i; j < numbers_count; j++)
		{
			if (smallest > numbers[j])
			{
				smallest = numbers[j];
				smallest_index = j;
			}
		}

		//swap
		numbers[smallest_index] = numbers[i];
		numbers[i] = smallest;
	}

	//even array size?
	if (numbers_count % 2 == 0)
	{
		//even
		int middle_index = (numbers_count - 2) / 2;
		double avg =
			(numbers[middle_index] + numbers[middle_index + 1])
			/ 2.0;
		cout << avg << endl;
	}
	else
	{
		//odd
		cout << numbers[(numbers_count - 1) / 2] << endl;
	}

	/* for visual debugging */
	for (int i = 0; i < numbers_count; i++)
	{
		cout << numbers[i] << endl;
	}


	return 0;
}