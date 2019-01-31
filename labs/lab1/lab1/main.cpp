#include <iostream>
#include "CsvReader.h"
using namespace std;
int main(void)
{
	CsvStateMachine csm{ "death_rates.csv" };
	vector<vector<string>> result = 
		csm.processFile();
	return 0;
}