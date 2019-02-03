#pragma once
#ifndef CSV_WRITER_H
#define CSV_WRITER_H
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;
class CsvWriter
{
public:
	static void writeToFile(const string& file_name, 
		const vector<vector<string>>& data)
	{
		ofstream output{ file_name };
		for (auto row : data)
		{
			for (auto cell : row)
			{
				ostringstream  sanitized_cell{};
				sanitized_cell << "\"";

				//sanitize all (quotes)
				for (auto ch : cell)
				{
					if (ch == '"')
					{
						sanitized_cell << "\"";
					}
					sanitized_cell << ch;
				}
				sanitized_cell << "\",";
				output << sanitized_cell.str();
			}
			output << endl;
		}

		output.close();
	}
};

#endif // !CSV_WRITER_H
