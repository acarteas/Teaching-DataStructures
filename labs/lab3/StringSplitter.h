#ifndef STRINGSPLITTER_H
#define STRINGSPLITTER_H

#include <string>
#include <vector>

using namespace std;

class StringSplitter
{
public:

	//Accepts a string and a delimiter.  Will use items_found to return the number
	//of items found as well as an array of strings where each element is a piece of
	//the original string.
	static string * split(string text, string delimiter, int &items_found)
	{
		//vectors are dynamically expanding arrays
		vector<string> pieces;

		//find the first delimiter
		int location = text.find(delimiter);

		//we are starting at the beginning of our string
		int start = 0;

		//go until we have no more delimiters
		while(location != string::npos)
		{
			//add the current piece to our list of pieces
			string piece = text.substr(start, location - start);
			pieces.push_back(piece);

			//update our index markers for the next round
			start = location + 1;
			location = text.find(delimiter, start);
		}

		//at the end of our loop, we're going to have one trailing piece to take care of.
		//handle that now.
		string piece = text.substr(start, location - start);
		pieces.push_back(piece);

		//convert from vector into an array of strings
		int size = pieces.size();
		string *pieces_str = new string[size];
		for(int i = 0; i < size; i++)
		{
			pieces_str[i] = pieces.at(i);
		}
		items_found = size;
		return pieces_str;			
	}
};

#endif