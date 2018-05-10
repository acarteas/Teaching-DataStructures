#ifndef SELECTION_SORTER_H
#define SELECTION_SORTER_H

#include "IndexedSort.h"

template <typename T>
class SelectionSort : public IndexedSort<T>
{
public:
	//see http://en.wikipedia.org/wiki/Selection_sort for a 
	//Selection Sort implementation
	virtual Indexed<T>& sort(Indexed<T>& data)
	{
		//For each item:
        //  Find the smallest element in the unsorted portion of the array
        //  Move to last sorted location + 1
        for (int i = 0; i < data.getSize() - 1; i++)
        {
            //The I value represents the "sorted" portion of the array

            //begin with the assumption that element at i is smaller
            int smallest_index = i;

            //verify that assumption
            for (int j = i + 1; j < data.getSize(); j++)
            {
                if (data.getElementAt(j) < data.getElementAt(smallest_index))
                {
                    //assumption violated: index j has a smaller value
                    smallest_index = j;
                }
            }

            //we are guaranteed to know the smallest index
            T temp = data.getElementAt(i);
            data.getElementAt(i) = data.getElementAt(smallest_index);
            data.getElementAt(smallest_index) = temp;
        }
		return data;
	}
};

#endif