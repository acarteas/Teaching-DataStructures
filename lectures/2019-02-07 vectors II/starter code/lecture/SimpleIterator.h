#pragma once
#ifndef SIMPLE_ITERATOR_H
#define SIMPLE_ITERATOR_H
#include <iterator>
using namespace std;

template <typename T>
class SimpleIterator : public iterator<forward_iterator_tag, T>
{
private:
	T* _data;

public:
	SimpleIterator(T* data)
		: _data(data)
	{
	}

	SimpleIterator(const SimpleIterator<T>& other_iterator)
	{
		_data = other_iterator._data;
	}

	//allows us to compare to other iterators
	bool operator==(const SimpleIterator<T>& other)
	{
		return _data == other._data;
	}

	//allows us to compare to other iterators
	bool operator!=(const SimpleIterator<T>& other)
	{
		return _data != other._data;
	}

	//allows us to get the data out of the iterator
	T& operator*()
	{
		return *_data;
	}

	//allows us to move forward in the data
	SimpleIterator<T>& operator++()
	{
		_data++;
		return *this;
	}

	SimpleIterator<T> operator++(int)
	{
		SimpleIterator<T> temp(*this);
		operator++();
		return temp;
	}

	//allows for offsetting of our base pointer
	//WARNING: very dangerous as we can potentially go out of bounds
	//from our original data.
	SimpleIterator<T> operator+(const int& offset)
	{
		return SimpleIterator<T>{&_data[offset]};
	}

};

#endif