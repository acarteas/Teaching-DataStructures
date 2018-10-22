#pragma once
#ifndef PRINT_JOB_J
#define PRINT_JOB_J
#include <string>
using namespace std;

class PrintJob
{
private:
	int _page_count = 0;
	string _document_name;

public:
	PrintJob(int pc = 0, string name = "")
	{
		_page_count = pc;
		_document_name = name;
	}

	int getPageCount() const
	{
		return _page_count;
	}

	void setPageCount(int pc)
	{
		_page_count = pc;
	}

	string getDocumentName() const
	{
		return _document_name;
	}

	void setDocumentName(string n)
	{
		_document_name = n;
	}

	//priority is based on number of pages
	int getPriority() const
	{
		return -_page_count;
	}
};

//operator overloads needed if we want to use an object inside
//a PQ
//if job1 < job2
bool operator<(const PrintJob& left, const PrintJob& right)
{
	return left.getPriority() < right.getPriority();
}

//if job1 > job2
bool operator>(const PrintJob& left, const PrintJob& right)
{
	return left.getPriority() > right.getPriority();
}

bool operator==(const PrintJob& left, const PrintJob& right)
{
	return left.getPriority() == right.getPriority();
}

#endif // !PRINT_JOB_J
