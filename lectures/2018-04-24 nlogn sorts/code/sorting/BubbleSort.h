#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H

#include "IndexedSort.h"

template <typename T>
class BubbleSort : public IndexedSort<T>
{
public:

	//see http://en.wikipedia.org/wiki/Bubble_sort for a 
	//Bubble Sort implementation
	virtual Indexed<T>& sort(Indexed<T>& data)
	{
        bool is_sorted = false;
        for (int i = 0; i < data.getSize() - 1 && is_sorted == false; i++)
        {
            is_sorted = true;
            for (int j = i + 1; j < data.getSize(); j++)
            {
                if (data.getElementAt(i) > data.getElementAt(j))
                {
                    //i is larger than j, allow i to bubble up
                    T temp = data.getElementAt(i);
                    data.getElementAt(i) = data.getElementAt(j);
                    data.getElementAt(j) = temp;
                    is_sorted = false;
                }
            }
        }
		return data;
	}
};

#endif