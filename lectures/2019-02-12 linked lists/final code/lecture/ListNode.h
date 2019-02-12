#pragma once
#ifndef LIST_NODE_H
#define LIST_NODE_H

template <typename T>
class ListNode
{
private:
	T _value;
	ListNode<T>* _next;

	//ignoring copy and move operations for now
	ListNode(const ListNode<T>& other) {}
	ListNode(ListNode<T>&& other) {}
	ListNode<T>& operator=(const ListNode<T>& other) {}
	ListNode<T>& operator=(ListNode<T>&& other) {}

public:
	ListNode(const T& value)
	{
		_value = value;
		_next = nullptr;
	}

	T& getValue()
	{
		return _value;
	}

	const T& getValue() const
	{
		return _value;
	}
	
	ListNode<T>* getNext()
	{
		return _next;
	}

	void setValue(const T& value)
	{
		_value = value;
	}

	void setNext(ListNode<T>* next)
	{
		_next = next;
	}
};

#endif