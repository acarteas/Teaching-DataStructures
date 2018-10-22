#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <queue>
#include <ctime>
#include <cstdlib>
#include "Patient.h"

using namespace std;

//Use a HT to count character frequencies
void task1()
{
	string user_input;
	cout << "Enter stuff: ";
	getline(cin, user_input);

	unordered_map<char, int> frequencies{};
	//             KEY   VALUE
	//frequences[KEY] = VALUE
	for (auto ch : user_input)
	{
		frequencies[ch]++;
	}

	//for auto loop MUST be used on HTs
	//Items in an unordered_map are output in an indeterminte manner
	vector<char> keys{};
	for (auto kvp : frequencies)
	{
		//kvp.first => KEY
		//kvp.second => VALUE
		//goal: output something like 'a': 5
		cout << "'" << kvp.first << "':" << kvp.second << endl;
		keys.push_back(kvp.first);
	}

	//IF we want order, we either have to use "parallel vector" or
	//just a MAP data structure
	sort(keys.begin(), keys.end());
	for (auto key : keys)
	{
		cout << "'" << key << "':" << frequencies[key] << endl;
	}
}

//Use a Max-Heap of custom objects
void task2()
{
	priority_queue<Patient> waitlist{};
	srand(time(NULL));

	//create 100 patients with random values
	for (int i = 0; i < 100; i++)
	{
		Patient p{};
		p.name = to_string(i);
		p.age = rand() % 99 + 1;
		p.severity = rand() % 99 + 1;
		p.arrival_time = i;
		p.life_points = rand() % 99 + 1;
		waitlist.push(p);
	}

	int timer = 0;
	while (waitlist.size() > 0)
	{
		timer++;
		Patient p = waitlist.top();
		waitlist.pop();

		cout << "Looking at patient: " << endl
			<< "Name: " << p.name << endl
			<< "Age: " << p.age << endl
			<< "Severity: " << p.severity << endl
			<< "Priority: " << p.getPriority() << endl << "..." << endl;
		if (timer > p.life_points)
		{
			cout << "DEAD!" << endl;
		}
		else
		{
			cout << "Saved, Yay!" << endl;
		}
		cout << endl;
	}
}

//how do you create a string of 0s and 1s?
string task3(int n)
{
	int power = 1;
	string output;
	int mask = 1;
	if (n == 0)
	{
		return "0";
	}
	while (mask <= n)
	{
		int digit = (n / mask) % 2;
		if (digit == 1)
		{
			output = "1" + output;
		}
		else
		{
			output = "0" + output;
		}
		mask = pow(2, power);
		power++;
	}
	
	return output;
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
			output = "0" + output;
		}
		n = n >> 1;
	}
	return output;
}

void task5Helper(vector<string>& data, int length)
{
	vector<string> temp{};
	for (auto item : data)
	{
		for (char ch = '0'; ch <= '1'; ch++)
		{
			string current = item + ch;
			temp.push_back(current);
		}
	}
	if (length > 0)
	{
		task5Helper(temp, length - 1);
	}
	for (auto item : temp)
	{
		data.push_back(item);
	}
}

//generate all permutations of strings up to a certain length
void task5(int length)
{
	vector<string> result{};
	for (char ch = '0'; ch <= '1'; ch++)
	{
		result.push_back(string{ ch });
	}
	task5Helper(result, length - 1);
}

int main(void)
{
	//task1();
	//task2();
	cout << task4(1) << endl;
	cout << task4(2) << endl;
	cout << task4(3) << endl;
	cout << task4(4) << endl;
	cout << task4(5) << endl;
	cout << task4(6) << endl;
	cout << task4(7) << endl;
	cout << task4(8) << endl;
	task5(10);
}