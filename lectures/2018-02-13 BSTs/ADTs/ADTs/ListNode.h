#ifndef LIST_NODE_H
#define LIST_NODE_H

//A list node represents a single "box" inside a lined list.  In this 
//scheme, the LinkedList is simply a collection of ListNode boxes.
template <typename T>
class ListNode
{
protected:

	//value that our box contains
	T _value;

	//pointer to next node in the LL sequence
	ListNode<T> *_next;

public:

	//constructor must accept a default value
	ListNode(const T &value) : _value(value)
	{
		_next = nullptr;
	}

	ListNode()
	{
		_next = nullptr;
	}

	//copy constructor prevents premature deletion of next pointer
	ListNode(const ListNode<T> &other)
	{
		_value = other.getValue();
		_next = other.getNext();
	}

	virtual ~ListNode()
	{

	}

	//copy operator allows us to reassign previously created list nodes
	ListNode<T> &operator=(const ListNode<T> &other)
	{
		if (this != &other)
		{
			ListNode<T> temp(other);
			swap(*this, temp);
		}
		return *this;
	}

	//returns a pointer to the next list node in the sequence
	ListNode<T> *getNext()
	{
		return _next;
	}

	//sets the pointer to the next node in the sequence
	void setNext(ListNode<T> *next)
	{
		_next = next;
	}

	//returns the value of the list node
	T &getValue()
	{
		return _value;
	}

	//constant version of the getter
	const T& getValue() const
	{
		return _value;
	}

	//sets the value of the current list node
	void setValue(const T &value)
	{
		_value = value;
	}
};

#endif