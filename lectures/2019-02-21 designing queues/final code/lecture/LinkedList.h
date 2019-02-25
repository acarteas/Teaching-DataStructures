#pragma once
#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include "ListNode.h"
#include <exception>
#include <utility>

using namespace std;

template <typename T>
class LinkedList
{
private:
	ListNode<T>* _front = nullptr;
	ListNode<T>* _end = nullptr;
	pair<ListNode<T>*, int> _last_access;

	int _size;

public:

	void removeAt(const int& index)
	{
		//is index in bounds?
		if (index < _size)
		{
			//our size has changed!
			_size--;

			if (index == 0)
			{
				//hold pointer to new front before deleting existing front
				ListNode<T>* temp = _front->getNext();
				delete _front;
				_front = temp;
				_last_access = make_pair(_front, 0);
			}
			else
			{
				//is our last access a better starting point than the front?
				int start = 0;
				ListNode<T>* current = _front;
				if (_last_access.second < index)
				{
					start = _last_access.second;
					current = _last_access.first;
				}

				//loop until we hit the box before our delete target
				for (int i = start; i < index - 1; i++)
				{
					current = current->getNext();
				}

				//Grab pointer to one we want to delete, then "hop over"
				//deleted item.
				ListNode<T>* temp = current->getNext();
				current->setNext(temp->getNext());
				delete temp;

				//if asked to delete last element, reassign end pointer
				if (_size == index)
				{
					_end = current;
				}
			}
		}
		else
		{
			throw out_of_range("Index out of bounds");
		}
	}

	void push_back(const T& item)
	{
		//special case when LL is empty
		if (_front == nullptr)
		{
			//empty list
			_front = new ListNode<T>{ item };
			_end = _front;
			_last_access = pair<ListNode<T>*, int>{ _front, 0 };
		}
		else
		{
			_end = _end->setNext(new ListNode<T>{ item });
		}
		_size++;
	}

	int size()
	{
		return _size;
	}

	T& operator[](int index)
	{
		//is index in bounds?
		if (index < _size)
		{
			if (index == _size - 1)
			{
				return _end->getValue();
			}

			//is our last access a better starting point than the front?
			int start = 0;
			ListNode<T>* current = _front;
			if (_last_access.second <= index)
			{
				start = _last_access.second;
				current = _last_access.first;
			}

			//loop until we hit the index
			for (int i = start; i < index; i++)
			{
				current = current->getNext();
			}
			_last_access = pair<ListNode<T>*, int>{ current, index };
			return current->getValue();
		}
		else
		{
			throw out_of_range("Index out of bounds");
		}
	}
};
#endif