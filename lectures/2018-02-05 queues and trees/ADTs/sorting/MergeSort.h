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
		//start and end greater than two
		if (end_bound - start_bound > 1)
		{
			//main MergeSort algorithm
			int midpoint = (end_bound - start_bound) / 2 + start_bound;

			//ensure sub arrays are sorted
			if (start_bound < midpoint)
			{
				sortHelper(data, start_bound, midpoint);
			}
			if (midpoint < end_bound)
			{
				sortHelper(data, midpoint, end_bound);
			}

			//merge sorted subsets
			Vector<T> merged{};
			int left_index = start_bound;
			int right_index = midpoint;

			//merge while both indices valid
			while (left_index < midpoint && right_index < end_bound)
			{
				//T left = data.getElementAt(left_index);
				//T right = data.getElementAt(right_index);
				merged.addElement(min(data, left_index, right_index));
			}

			//once here, three possibilities:
			//1. both left and right are invalid indices (ignore because we're done)
			//2. left is an invalid index
			//3. right is an invalid index
			if (left_index < midpoint && right_index >= end_bound)
			{
				//case #3
				for (int i = left_index; i < midpoint; i++)
				{
					T item = data.getElementAt(i);
					merged.addElement(data.getElementAt(i));
				}
			}
			else if(right_index < end_bound && left_index >= midpoint)
			{
				//case #2
				for (int j = right_index; j < end_bound; j++)
				{
					T item = data.getElementAt(j);
					merged.addElement(data.getElementAt(j));
				}
			}

			//now, copy our temp array back into main array
			for (int i = 0, j = start_bound; i < merged.getSize(); i++, j++)
			{
				//T item = merged.getElementAt(i);
				data.setElementAt(merged.getElementAt(i), j);
			}

			//all done!
		}
		else if (end_bound - start_bound == 1)
		{
			//swap pairs if necessary
			if (data.getElementAt(end_bound) < data.getElementAt(start_bound))
			{
				swap(data, end_bound, start_bound);
			}
		}
		else if (end_bound - start_bound == 0)
		{
			//nothing to do, so we're done
			return;
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