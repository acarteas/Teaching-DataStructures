#ifndef STRING_STREAM_STRING_HASHER_H
#define STRING_STREAM_STRING_HASHER_H

#include "HasherBase.h"
#include <string>
#include <sstream>

using namespace std;

//A simple implementation of using StringStreams to hash a string by Joshua Alpert
class StringStreamStringHasher : public HasherBase<string>
{
	virtual int getHash(const string &item, int mod_by)
	{
		stringstream hash{};
		for (char ch : item)
		{
			hash << (int) ch; //type cast each char in the inputed string into a int
		}
		return stoi(hash.str()) % mod_by;
	}

};


#endif // !STRING_STREAM_STRING_HASHER_H

