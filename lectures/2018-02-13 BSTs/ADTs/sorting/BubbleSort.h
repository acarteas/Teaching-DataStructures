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
		int data_size = data.getSize();
		bool swapped = false;
		while (false == swapped)
		{
			swapped = true;

            //TODO: We should be able to change the FOR loop
            //to shrink for every pass
			for (int i = 0; i < data_size - 1; i++)
			{

				//is the current item greater than the
				//next adjacent item
				if (data.getElementAt(i) > 
					data.getElementAt(i + 1))
				{
					//..if so, swap the values
					T first = data.getElementAt(i);
					T second = data.getElementAt(i + 1);
					data.setElementAt(first, i + 1);
					data.setElementAt(second, i);
					swapped = false;
				}
			}
			data_size--;
		}
		return data;
	}
};

#endif