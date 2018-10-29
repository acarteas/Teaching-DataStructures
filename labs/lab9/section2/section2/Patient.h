#pragma once
#ifndef PATIENT_H
#define PATIENT_H
#include <string>
using namespace std;

class Patient
{
public:
	string name;
	int age;
	int arrival_time;
	int severity;
	int life_points;

	int getPriority() const
	{
		return severity * (100 - arrival_time) - 2 * age;
	}
};

//patient1 < patient2
bool operator<(const Patient& left, const Patient& right)
{
	return left.getPriority() < right.getPriority();
}

bool operator>(const Patient& left, const Patient& right)
{
	return left.getPriority() > right.getPriority();
}

bool operator==(const Patient& left, const Patient& right)
{
	return left.getPriority() == right.getPriority();
}

#endif // !PATIENT_H
