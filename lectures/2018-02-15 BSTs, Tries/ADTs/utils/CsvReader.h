#ifndef CSV_READER_H
#define CSV_READER_H

#include <vector>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

class CsvStateMachine;
class CsvState;
class DefaultState;
class QuoteState;
class DoubleQuoteState;
class EndState;

class CsvState
{
public:
	virtual ~CsvState() {}

	//All CSV state are going to have this one function
	virtual void handle() = 0;
};

class DefaultState : public CsvState
{
private:
	CsvStateMachine* _machine = nullptr;

public:
	DefaultState(CsvStateMachine* csm)
	{
		_machine = csm;
	}

	//to be defined later
	virtual void handle();
};

class QuoteState : public CsvState
{
private:
	CsvStateMachine* _machine = nullptr;

public:
	QuoteState(CsvStateMachine *csm)
	{
		_machine = csm;
	}
	virtual void handle();
};

class DoubleQuoteState : public CsvState
{
private:
	CsvStateMachine* _machine = nullptr;
public:
	DoubleQuoteState(CsvStateMachine* csm)
	{
		_machine = csm;
	}
	virtual void handle();
};

class EndState : public CsvState
{
private:
	CsvStateMachine* _machine = nullptr;
public:
	EndState(CsvStateMachine* csm)
	{
		_machine = csm;
	}
	virtual void handle();
};

class CsvStateMachine
{
private:
	//all stats in our machine
	CsvState* _default_state = nullptr;
	CsvState* _quote_state = nullptr;
	CsvState* _double_qoute_state = nullptr;
	CsvState* _end_state = nullptr;

	//keeps track of current active state in machine
	CsvState* _current_state = nullptr;

	//represents the entire fiel in object form
	vector<vector<string>> _table;

	//represents the file in raw form
	ifstream _csv_stream;

	//represents the current row being processed in object form
	vector<string> _current_row;

	//represents the current row in raw form
	string _current_line;

	//points to current character of current line
	int _current_line_position = 0;

	//reprents the current cell being operated on
	ostringstream _current_cell;

public:
	CsvStateMachine(string file_name)
	{
		//set up states
		_default_state = new DefaultState(this);
		_quote_state = new QuoteState(this);
		_double_qoute_state = new DoubleQuoteState(this);
		_end_state = new EndState(this);

		//set current state to default
		_current_state = _default_state;

		//set up file stream for processing
		_csv_stream = ifstream{ file_name };
		_current_cell = ostringstream{};
	}

	//always remember to clean up dynamically created variables
	~CsvStateMachine()
	{
		delete _default_state;
		delete _quote_state;
		delete _double_qoute_state;
		delete _end_state;
	}

	//adds the supplied character to the cell presently under
	//construction
	void appendToCurrentCell(char to_append)
	{
		_current_cell << to_append;
	}

	//returns the next character to be processed
	char getNextCharToProcess()
	{
		//prevents array out of bounds
		if (_current_line.length() <= _current_line_position)
		{
			return '\0';
		}
		char result = _current_line[_current_line_position];
		_current_line_position++;
		return result;
	}

	void setStateToDefaultState()
	{
		_current_state = _default_state;
	}

	void setStateToQuoteState()
	{
		_current_state = _quote_state;
	}

	void setStateToDoubleQuoteState()
	{
		_current_state = _double_qoute_state;
	}

	void setStateToEndState()
	{
		_current_state = _end_state;
	}

	//this function drives the underlying state machine and 
	//produces the final 2D table of CSV data
	vector<vector<string>> processFile()
	{
		getline(_csv_stream, _current_line);
		while (_csv_stream.good() == true || _current_line.length() > 0)
		{
			//check for boundary conditions
			//in end state
			//or end of line
			if (_current_state == _end_state ||
				_current_line_position == _current_line.length())
			{
				//add current cell to current row and reset states
				_current_row.push_back(_current_cell.str());
				_current_cell = ostringstream{};
				setStateToDefaultState();

				//is row done?
				if (_current_line_position == _current_line.length())
				{
					//check for empty cell
					if (_current_line[_current_line_position - 1] == ',')
					{
						_current_row.push_back("");
					}

					//we are done with row, so add row to table, reset row
					//and grab a new line
					_table.push_back(_current_row);
					_current_row = vector<string>{};
					_current_line_position = 0;
					getline(_csv_stream, _current_line);
					
					//account for EOF
					if (_csv_stream.good() == false)
					{
						break;
					}
				}
			}

			//make state machine do work
			_current_state->handle();
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
		//add character to cell
		_machine->appendToCurrentCell(next_char);

		if (next_char == '"')
		{
			_machine->setStateToQuoteState();
		}
		else
		{
			_machine->setStateToDefaultState();
		}
	}
}

void EndState::handle()
{

}

#endif // !CSV_READER_H