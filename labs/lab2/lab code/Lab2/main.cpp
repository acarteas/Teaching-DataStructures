#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include "StringSplitter.h"
using namespace std;
vector<string> readFile(ifstream& some_file);
vector<string> readFile(ifstream&& some_file);
vector<string> readFile(string file_name);

int main(void)
{
	vector<string> ppm_data = readFile("bunny.ppm");
	for (int i = 3; i < ppm_data.size(); i++)
	{
		vector<string> color_values = 
			StringSplitter::split(ppm_data[i], " ");
		for (auto& value : color_values)
		{
			cout << value << endl;
		}
	}
	return 0;
}


vector<string> readFile(ifstream& some_file)
{
	vector<string> result{};
	//is the file open?
	if (some_file.is_open() == true)
	{
		while (some_file.good() == true)
		{
			//two ways to grab data
			string data;
			//first_names >> data; //CIN style
			getline(some_file, data); //more robust method
			result.push_back(data);
		}
	}
	return result;
}

vector<string> readFile(ifstream&& some_file)
{
	ifstream& local_file = some_file;

	//auto is an automatically inferred variable type
	//in our case, vector<string>
	auto result = readFile(local_file);
	local_file.close();
	return result;
}

vector<string> readFile(string file_name)
{
	return readFile(ifstream{ file_name });
}