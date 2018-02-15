#ifndef COLLECTION_H
#define COLLECTION_H

//This is an interface.  An interface does not have any
//concrete implementation.
template <typename T>
class Collection
{
public:

	//setting a function equal to zero (very ugly) means that
	//the function's implementation will occurr in some child
	//class.  
	virtual void addElement(const T& item) = 0;

	//Remove the first occurrence of "item" in our collection.
	//const T& -> "A constant reference of data type T"
	//C++ pros say passing by constant reference is the fastest
	//way to sent data to a function.
	//assumption: we do not need to modify "item".
	//If we do need to modify, we would either pass by
	//reference, pointer, or value depending on situation
	virtual void removeElement(const T& item) = 0;

	//Returns true when at least one instance of T is in our
	//collection.  False otherwise.
	virtual bool containsElement(const T& item) const = 0;

	//const on right side of function means, "this function
	//promises to not modify the underlying state of the 
	//object."  I.e. this function will not modify member
	//variables.
	virtual const T& getFirst() const = 0;

	//This version of the function will be called whenever we
	//try to modify our collection.
	virtual T& getFirst() = 0;

	virtual int getSize() const = 0;
	virtual bool isEmpty() const = 0;
};

#endif // !COLLECTION_H
