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
   Vector<T>&& operator=(const Vector<T>&& other) {};

protected:

   //We are using a pointer to act like an array of T thing
   T *_items = nullptr;

   //tracks the physical size of our array
   int _physical_size = 0;

   //tracks the actual number of boxes presently in use
   int _logical_size = 0;

public:

   Vector(int starting_size = 0) {

   }
};

#endif // !VECTOR_H
