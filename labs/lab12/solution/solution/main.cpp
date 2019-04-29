#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <fstream>

using namespace std;

class MazeSpace
{
public:
	unordered_map<string, MazeSpace*> neighbors;
	char value;
	bool can_visit = false;

	MazeSpace()
	{
		value = '#';
	}
};

bool solve(MazeSpace* space)
{
	//pattern: left, right, down, up

	//mark that we've been here
	if (space->value == '.')
	{
		space->value = 'x';
		space->can_visit = false;
	}
	vector<MazeSpace*> to_visit{
		space->neighbors["left"],
		space->neighbors["right"],
		space->neighbors["down"],
		space->neighbors["up"]
	};
	for (auto next : to_visit)
	{
		if (next->can_visit == true)
		{
			if (next->value == 'o')
			{
				return true;
			}
			if (solve(next) == true)
			{
				return true;
			}
		}
	}
	return false;
}

int main(void)
{
	//builds the maze in raw vector form
	vector<vector<char>> raw_map{};
	ifstream input_file{"maze4.txt"};
	if (input_file.is_open() == true)
	{
		string line;

		//kills the dimensions as we don't need them
		getline(input_file, line);
		while (input_file.good() == true)
		{
			getline(input_file, line);
			raw_map.push_back(vector<char>{});
			for (char ch : line)
			{
				raw_map.rbegin()->push_back(ch);
			}
		}
	}

	//convert into edge list (pointer based)
	vector<vector<MazeSpace>> map{};

	//dimension the map
	map.resize(raw_map.size());
	for (auto& row : map)
	{
		row.resize(raw_map[0].size());
	}

	MazeSpace* start = nullptr;
	MazeSpace* end = nullptr;

	//starting at 1 and ending at end - 1 ignores walls
	for (int i = 1; i < raw_map.size() - 1; i++)
	{
		for (int j = 1; j < raw_map[i].size() - 1; j++)
		{
			//assign value
			map[i][j].value = raw_map[i][j];

			if (map[i][j].value != '#')
			{
				map[i][j].can_visit = true;
			}

			if (map[i][j].value == '*')
			{
				start = &map[i][j];
			}
			else if (map[i][j].value == 'o')
			{
				end = &map[i][j];
			}

			//assign neighbors
			map[i][j].neighbors["up"] = &map[i - 1][j];
			map[i][j].neighbors["down"] = &map[i + 1][j];
			map[i][j].neighbors["left"] = &map[i][j - 1];
			map[i][j].neighbors["right"] = &map[i][j + 1];
		}
	}
	cout << solve(start) << endl;
	for (auto& row : map)
	{
		for (auto& cell : row)
		{
			cout << cell.value;
		}
		cout << endl;
	}
	return 0;
}