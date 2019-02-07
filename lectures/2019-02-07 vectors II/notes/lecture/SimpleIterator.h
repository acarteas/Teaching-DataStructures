#ifndef SIMPLE_ITERATOR
#define SIMPLE_ITERATOR
#include <iterator>

using namespace std;
template <typename T>
class SimpleIterator : public iterator<forward_iterator_tag, T>
{
private:
   T *p;

public:
   SimpleIterator(T *x)
   {
      p = x;
   }

   SimpleIterator(const T &iter)
   {
      p = iter.p;
   }

   SimpleIterator & operator++()
   {
      p++;
      return *this;
   }

   SimpleIterator operator++(int)
   {
      SimpleIterator<T> tmp(*this);
      operator++();
      return tmp;
   }

   bool operator==(const SimpleIterator<T> other)
   {
      return p == other.p;
   }

   bool operator!=(const SimpleIterator<T> other)
   {
      return p != other.p;
   }

   T & operator*()
   {
      return *p;
   }

   //allows for adding offsets to base value.  
   //WARNING: dangerous as you can easily get an array index out of bounds exception
   T& operator+(const int& other)
   {
      return p[other];
   }
};

#endif