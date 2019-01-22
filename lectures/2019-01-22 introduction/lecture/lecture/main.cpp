#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>

using namespace std;

vector<string> readFile(ifstream& some_file);

int main(void)
{
	//Goal: Write 100 random names to "FullNames.txt"
	ifstream first_names_file{ "FirstNames.txt" };
	vector<string> first_names = readFile(first_names_file);

	//is the file open?
	if (first_names_file.is_open() == true)
	{
		while (first_names_file.good() == true)
		{
			//two ways to grab data
			string data;
			//first_names >> data; //CIN style
			getline(first_names_file, data); //more robust method
			first_names.push_back(data);
		}
	}
}

vector<string> readFile(ifstream& some_file)
{
	vector<string> result{};
	return result;
}