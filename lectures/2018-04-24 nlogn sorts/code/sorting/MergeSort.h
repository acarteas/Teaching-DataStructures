#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include "IndexedSort.h"
#include "../ADTs/Vector.h"
template <typename T>
class MergeSort : public IndexedSort<T>
{
private:

	//C++ 11-style swap
	void swap(Indexed<T> &data, int from, int to)
	{
		T &left = data.getElementAt(from);
		T &right = data.getElementAt(to);
		T tmp{ static_cast<T&&>(left) };
		left = static_cast<T&&>(right);
		right = static_cast<T&&>(tmp);
	}

	//finds min of two, also increments my left and right pointers
	T& min(Indexed<T> &data, int &left, int &right)
	{
		if (data.getElementAt(left) < data.getElementAt(right))
		{
			T& item = data.getElementAt(left);
			left++;
			return item;
		}
		else
		{
			T& item = data.getElementAt(right);
			right++;
			return item;
		}
	}

	void sortHelper(Indexed<T> &data, int start_bound, int end_bound)
	{
        if (end_bound - start_bound == 0)
        {
            //single element array.  Just return
            return;
        }
        else if (end_bound - start_bound == 1)
        {
            //compare two elements, swap as necessary
            if (data.getElementAt(end_bound) < data.getElementAt(start_bound))
            {
                swap(data, end_bound, start_bound);
            }
        }
        else
        {
            //recursion happens here
            int midpoint = (end_bound + start_bound) / 2;

            //break down the array
            if (start_bound < midpoint)
            {
                //spit on left side
                sortHelper(data, start_bound, midpoint);
            }
            if (midpoint < end_bound)
            {
                //split on right side
                sortHelper(data, midpoint, end_bound);
            }

            //INVARIANT: right and left are sorted
            //Now, peform merge on sorted arrays
            Vector<T> merged{};
            int left_index = start_bound;
            int right_index = midpoint;
            while (left_index < midpoint && right_index < end_bound)
            {
                merged.addElement(min(data, left_index, right_index));
            }

            //Once we're here, three possibilities
            //1. left and right are invalid indices (do not need to account for)
            //2. left is still valid
            //3. right is still valid

            //case 2
            while (left_index < midpoint)
            {
                merged.addElement(data.getElementAt(left_index));
                left_index++;
            }

            //case 3
            while (right_index < end_bound)
            {
                merged.addElement(data.getElementAt(right_index));
                right_index++;
            }
            
            //now, copy over merged vector into original array
            for (int i = 0, j = start_bound; i < merged.getSize(); i++, j++)
            {
                data.setElementAt(merged.getElementAt(i), j);
            }
        }
	}


public:
	virtual Indexed<T>& sort(Indexed<T>& data)
	{
		sortHelper(data, 0, data.getSize() - 1);
		return data;
	}


};

#endif