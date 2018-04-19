#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H

#include "IndexedSort.h"

template <typename T>
class InsertionSort : public IndexedSort<T>
{
public:

	//Insertion Sort taken from Wikipedia: http://en.wikipedia.org/wiki/Insertion_sort
	//See site for a nice visualization of the process
	virtual Indexed<T>& sort(Indexed<T>& data)
	{
		
		return data;
	}
};

#endif