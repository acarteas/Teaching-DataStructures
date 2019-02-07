#pragma once
#ifndef VECTOR_H
#define VECTOR_H

template <typename T>
class Vector {

private:

   //disallow copy and move constructors
   Vector(const Vector<T>& other) {};
   Vector(const Vector<T>&& other) {};

   //disallow copy and move operators
   Vector<T>& operator=(const Vector<T>& other) {};
   Vector<T>& operator=(const Vector<T>&& other) {};

   //determines if we are able to put a value at the requested location
   void checkCapacity(int requested_location)
   {
	   if (requested_location >= _physical_size)
	   {
		   //too small, need to resize
		   int new_size = requested_location * 2 + 1;
		   T* new_data = new T[new_size];

		   //take everything out of the old array first
		   for (int i = 0; i < _logical_size; i++)
		   {
			   new_data[i] = _items[i];
		   }

		   //finally, out with the old, in with the new
		   delete[] _items;
		   _physical_size = new_size;
		   _items = new_data;
	   }
   }

protected:

   //We are using a pointer to act like an array of T thing
   T *_items = nullptr;

   //tracks the physical size of our array
   int _physical_size = 0;

   //tracks the actual number of boxes presently in use
   int _logical_size = 0;

public:

   Vector(int starting_size = 0)
	   : _logical_size(starting_size)
   {
	   if (starting_size == 0)
	   {
		   starting_size = 11;
	   }
	   //allocate space for physical memory
	   _physical_size = starting_size;
	   _items = new T[_physical_size];
   }

   ~Vector()
   {
	   //always remember to deallocate memory
	   delete[] _items;
   }

   //Adds new item to end of vector
   void push_back(const T& value)
   {
	   //is it okay to add to our vector, or are we out of space?
	   checkCapacity(_logical_size);
	   _items[_logical_size] = value;
	   _logical_size++;
   }

   //returns logical size of vector
   const int& size() const
   {
	   return _logical_size;
   }

   T& operator[](const int& index)
   {
	   return _items[index];
   }
};

#endif // !VECTOR_H
