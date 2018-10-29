#include <string>
#include <vector>
#include <iostream>
#include <queue> //for PQ
#include <unordered_map> //for HT
#include <map>
#include <algorithm> //for sort
#include <ctime>
#include <cstdlib>
#include "PrintJob.h"

using namespace std;

void task1()
{
	string user_input;
	cout << "Enter stuff: ";
	getline(cin, user_input);

	//Task #1: use HT to count characters
	unordered_map<char, int> frequency{};
	//             KEY    VALE
	//fequency[KEY] = VALUE;
	for (auto ch : user_input)
	{
		frequency[ch]++;
	}

	//output frequencies to the screen
	//Remember, the output of the KVP is unknown
	vector<char> keys{};
	for (auto kvp : frequency)
	{
		//kvp.first // key
		//kvp.second //value
		cout << "'" << kvp.first << "': " << kvp.second << endl;
		keys.push_back(kvp.first);
	}

	//If you want KVP to come out ordered, use a map
	//or a parallel key vector
	sort(keys.begin(), keys.end());
	for (auto key : keys)
	{
		cout << "'" << key << "': " << frequency[key] << endl;
	}
}

//simulate printer using priority queue
void task2()
{
	priority_queue<PrintJob> pq{};
	srand(time(NULL));

	//add 100 items to PQ
	for (int i = 0; i < 100; i++)
	{
		PrintJob job{ rand() % 20, to_string(i) };
		cout << "Adding " << job.getDocumentName() << " ("
			<< job.getPageCount() << " pages)" << endl;
		pq.push(job);
	}

	//if each page takes 1 unit of time to print, how many
	//complete documents can we print in 100 units of time?
	int current_time = 0;
	while (pq.size() > 0 && current_time < 100)
	{
		PrintJob top = pq.top();
		pq.pop();
		cout << "Job " << top.getDocumentName() << " begins "
			<< "printing (" << top.getPageCount() << " pages)."
			<< endl;
		current_time += top.getPageCount();
	}
}

void task3Helper(vector<string>& result, int n)
{
	vector<string> temp{};
	for (auto item : result)
	{
		for (char ch = '0'; ch <= '1'; ch++)
		{
			string current = item;
			current += ch;
			temp.push_back(current);
		}
	}
	if (n > 0)
	{
		task3Helper(temp, n - 1);
	}
	for (auto item : temp)
	{
		result.push_back(item);
	}
	
}


//generating permutations of a string
void task3()
{
	//task: generate all possible N character strings
	vector<string> result{};
	for (char ch = '0'; ch <= '1'; ch++)
	{
		result.push_back(string{ ch });
	}
	task3Helper(result, 5);
}

string task4(int n)
{
	if (n == 0)
	{
		return "0";
	}
	string output;
	while (n > 0)
	{
		int result = n & 1;
		if (result == 1)
		{
			output = "1" + output;
		}
		else
		{
			output += "0" + output;
		}
		n = n >> 1;
	}
	return output;
}


int main(void)
{
	//task1();
	//task2();
	task3();
	cout << task4(5) << endl;
	cout << task4(6) << endl;
	cout << task4(8) << endl;
}