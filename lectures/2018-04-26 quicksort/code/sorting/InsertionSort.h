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
        //we're starting at 1 becaues an array of size 1 (element 0) is
        //by definition sorted
        for (int i = 1; i < data.getSize(); i++)
        {
            for (int j = i; j > 0; j--)
            {
                //out of order, swap
                if (data.getElementAt(j) < data.getElementAt(j - 1))
                {
                    T temp = data.getElementAt(j);
                    data.getElementAt(j) = data.getElementAt(j - 1);
                    data.getElementAt(j - 1) = temp;
                }
                else
                {
                    //no more comparisons to be made on this J loop
                    break;
                }
            }
        }
		return data;
	}
};

#endif