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

class CsvStateMachine
{
private:
	//the state machine needs to have a record of all
	//possible states
	CsvState* _default_state = nullptr;
	CsvState* _quote_state = nullptr;
	CsvState* _double_quote_state = nullptr;
	CsvState* _end_state = nullptr;

	//keeps track of active state in state machine
	CsvState* _active_state = nullptr;

	//file form of CSV file
	ifstream _csv_stream;

	//represents current row in raw form
	string _raw_line;

	//Object form of CSV file
	vector<vector<string>> _table;

	//Object form of current row being processed
	vector<string> _current_row;

	//tracks where we are at in the current row being processed
	int _current_row_position;

	//represents current cell being operated on, programmatically
	//constructed
	ostringstream _current_cell;

public:
	CsvStateMachine(string file_name)
	{
		//set up states
		_default_state = new DefaultState(this);
		_quote_state = new QuoteState(this);
		_double_quote_state = new DoubleQuoteState(this);
		_end_state = new EndState(this);

		//set initial state
		_active_state = _default_state;

		//set up file stream for processing
		_csv_stream = ifstream{ file_name };
		_current_cell = ostringstream{};
	}

	//always remember to clean up dynamically created variables
	~CsvStateMachine()
	{
		delete _default_state;
		delete _quote_state;
		delete _double_quote_state;
		delete _end_state;
		_csv_stream.close();
	}

	//setter functions allow individual states to alter overall state machine
	void setStateToDefault()
	{
		_active_state = _default_state;
	}
	void setStateToQuoteState()
	{
		_active_state = _quote_state;
	}
	void setStateToDoubleQuoteState()
	{
		_active_state = _double_quote_state;
	}
	void setStateToEndState()
	{
		_active_state = _end_state;
	}

	//allows active state to add content to the current cell
	void appendToCurrentCell(char ch)
	{
		_current_cell << ch;
	}

	//allows active state to learn about the char it's supposed to
	//process
	char getNextCharToProcess()
	{
		//make sure that there is info to be processed
		if (_raw_line.length() <= _current_row_position)
		{
			return '\0';
		}
		char result = _raw_line[_current_row_position];
		_current_row_position++;
		return result;
	}

	//this function drives the underlying state machine and produces
	//the final 2D table of CSV data
	vector<vector<string>> processFile()
	{
		//prime loop by grabbing first line in file
		getline(_csv_stream, _raw_line);
		while (_csv_stream.good() == true || _raw_line.length() > 0)
		{

			//are we done processing current line or are we at the end state?
			if (_raw_line.length() == _current_row_position
				|| _active_state == _end_state)
			{
				//remember _current_cell is an ostringstream
				//so we need to convert into raw string using .str() 
				_current_row.push_back(_current_cell.str());

				//reset current cell
				_current_cell = ostringstream{};

				//reset state machine
				setStateToDefault();

				//are we done with the line?
				if (_raw_line.length() == _current_row_position)
				{
					//check for dangling comma (empty cell)
					if (_current_row_position > 0 
						&& _raw_line[_current_row_position - 1] == ',')
					{
						_current_row.push_back("");
					}

					//we are done with the row, so add row to table, rest row
					//and grab a new line
					_table.push_back(_current_row);
					_current_row = vector<string>{};
					_current_row_position = 0;			

					//account for end of file
					if (_csv_stream.good() == true)
					{
						getline(_csv_stream, _raw_line);
					}
					else
					{
						break;
					}			
				}
			}
			else
			{
				//no new cell or line needed, continue to run state machine
				_active_state->handle();
			}
		}
		return _table;
	}

	vector<vector<string>> getTable()
	{
		return _table;
	}
};

void DefaultState::handle()
{
	char next_char = _machine->getNextCharToProcess();
	if (next_char == ',')
	{
		_machine->setStateToEndState();
	}
	else if (next_char == '"')
	{
		_machine->setStateToQuoteState();
	}
	else
	{
		_machine->appendToCurrentCell(next_char);
	}
}

void QuoteState::handle()
{
	char next_char = _machine->getNextCharToProcess();
	if (next_char == '"')
	{
		_machine->setStateToDoubleQuoteState();
	}
	else
	{
		_machine->appendToCurrentCell(next_char);
	}
}

void DoubleQuoteState::handle()
{
	char next_char = _machine->getNextCharToProcess();
	if (next_char == ',')
	{
		_machine->setStateToEndState();
	}
	else 
	{
		//Note: this isn't 100% correct in certain fringe cases
		_machine->appendToCurrentCell(next_char);
		if (next_char == '"')
		{
			_machine->setStateToQuoteState();
		}
		else
		{
			_machine->setStateToDefault();
		}
	}
}

void EndState::handle()
{

}

#endif // !CSV_PARSER_H
