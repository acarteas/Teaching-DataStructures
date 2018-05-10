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
		for (int i = 0; i < data.getSize(); i++)
		{
			int j = i - 1;
            T to_compare = data.getElementAt(i);
			while (j > 0
				&& data.getElementAt(j) > to_compare
				)
			{
                T temp = data.getElementAt(j);
                data.setElementAt(temp, j + 1);
				j--;
			}
            data.setElementAt(to_compare, j + 1);
		}
		return data;
	}
};

#endif