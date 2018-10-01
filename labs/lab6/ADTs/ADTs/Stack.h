#ifndef STACK_H
#define STACK_H

//Stacks allow us to add and remove items from the "end" of a collection.
template <typename T>
class Stack
{
public:

	//removes the "top"-most element from the stack and returns its value
	virtual T pop() = 0;
	
	//returns the "top"-most element in the stack.
	virtual const T &getTop() const = 0;
    virtual T &getTop() = 0;

	//adds the supplied element to the "top" of the stack.
	virtual void push(const T& item) = 0;

    virtual int getSize() const = 0;
};

#endif