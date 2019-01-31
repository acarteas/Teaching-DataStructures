#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>
#include "CsvParser.h"
#include "CsvWriter.h"
using namespace std;

int main(void)
{
	CsvStateMachine csm{"FullNames.csv"};
	vector<vector<string>> result = csm.processFile();
	CsvWriter::writeToFile("test_output.csv", result);
	return 0;
}