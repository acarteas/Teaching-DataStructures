#pragma once
#ifndef CSV_PARSER_H
#define CSV_PARSER_H

#include <vector>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

class CsvStateMachine; //this HAS states
class CsvState;        //this IS a state
class DefaultState;    //this IS a state
class QuoteState;      //this IS a state
class DoubleQuoteState;//this IS a state
class EndState;        //this IS a state

class CsvState
{
protected:
	CsvStateMachine* _machine = nullptr;

public:
	virtual ~CsvState() {};
	CsvState(CsvStateMachine* machine) {
		_machine = machine;
	}

	//pure virtual function does 2 things:
	//1. means that we CANNOT create an instance
	//of this class directly because this class
	//is now marked as Abstract.
	//2. Ensures that every concrete instance
	//   of CsvState MUST implement this function.
	virtual void handle() = 0;
};

class DefaultState : public CsvState
{
public:
	DefaultState(CsvStateMachine* machine)
		: CsvState(machine)
	{
	}

	//to be defined later
	virtual void handle();
};

class QuoteState : public CsvState
{
public:
	QuoteState(CsvStateMachine* machine)
		: CsvState(machine)
	{
	}

	//to be defined later
	virtual void handle();
};

class DoubleQuoteState : public CsvState
{
public:
	DoubleQuoteState(CsvStateMachine* machine)
		: CsvState(machine)
	{
	}

	//to be defined later
	virtual void handle();
};

class EndState : public CsvState
{
public:
	EndState(CsvStateMachine* machine)
		: CsvState(machine)
	{
	}

	//to be defined later
	virtual void handle();
};

void DefaultState::handle()
{

}

void QuoteState::handle()
{

}

void DoubleQuoteState::handle()
{

}

void EndState::handle()
{

}

#endif // !CSV_PARSER_H
