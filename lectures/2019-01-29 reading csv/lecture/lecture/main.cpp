#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>

using namespace std;

vector<string> readFile(ifstream& some_file);
vector<string> readFile(ifstream&& some_file);
vector<string> readFile(string file_name);

int main(void)
{
	//Goal: Write 100 random names to "FullNames.txt"
	vector<string> first_names = readFile("FirstNames.txt");
	vector<string> last_names = readFile("LastNames.txt");

	//Uncomment to write new random names to a file
	srand(time(NULL));
	ofstream output{ "FullNames.csv" };
	output << "Last,First,Age" << endl;
	for (int i = 0; i < 100; i++)
	{
		string first = first_names[rand() % first_names.size()];
		string last = last_names[rand() % last_names.size()];
		output << first << ",";
		output << last << ",";
		//string full = "\"" + last + ", " + first + "\"";
		output << rand() % 20 + 17 << endl;
	}
	output.close();

	//Goal: output each name as follows:
	//First: <Name>
	//Last: <Name>
	vector<string> csv_data = readFile("FullNames.csv");
	for (auto item : csv_data) 
	{
		int start_index = 0;
		vector<string> cells{};
		for (int i = 0; i < item.size(); i++)
		{
			if (item[i] == ',')
			{
				//01234567890
				//abc,def,hij
				string first = item.substr(start_index, i - start_index);
				start_index = i + 1;
				cells.push_back(first);
			}
		}

		//take care of any remaining data
		cells.push_back(item.substr(start_index, item.length()));
	}
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