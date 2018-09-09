#ifndef CSVWRITER_H
#define CSVWRITER_H

#include <vector>
#include <string>
#include <iterator>

using namespace std;
class CsvWriter
{
private:
	vector<string> _lines;
	int _currentLine;
public:
	CsvWriter()
	{
		_currentLine = 0;
		_lines.push_back("");
	}

	//Adds a new cell to the current row
	void addText(string text)
	{
		string &currentLine = _lines[_currentLine];
		if(currentLine.length() > 0)
		{
			currentLine += ",";
		}
		currentLine += "\"" + text + "\"";
	}

	//Moves the CsvWriter to the next line in the CSV file
	void nextLine()
	{
		_lines.push_back("");
		_currentLine++;
	}

	//Converts the class into a string-based CSV file.
	string toCsvString() const
	{
		string output = "";
		for(vector<string>::const_iterator iter = _lines.begin(); iter != _lines.end(); iter++)
		{
			output += *iter + "\n";
		}
		return output;
	}
};
#endif