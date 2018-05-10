#ifndef RADIX_SORT_H
#define RADIX_SORT_H

#include "IndexedSort.h"
#include "../ADTs/Vector.h"

#include <cmath>

using namespace std;
class RadixSort : public IndexedSort<int>
{
private:

public:
	virtual Indexed<int>& sort(Indexed<int>& data)
	{
		Vector<Vector<int>> buckets{};
		Vector<Vector<int>> temp_buckets{};
		buckets.setSize(10);
		temp_buckets.setSize(10);
		
		bool needs_another_iteration = true;
		int power_of_ten = 0;
		for (int i = 0; i < data.getSize(); i++)
		{
			buckets[0].addElement(data.getElementAt(i));
		}

		while (needs_another_iteration)
		{
			//assume last iteration
			needs_another_iteration = false;
			int divisor = pow(10, power_of_ten);
			for (int i = 0; i < 10; i++)
			{
				for (int j = 0; j < buckets[i].getSize(); j++)
				{
					int item = buckets[i].getElementAt(j);
					int bucket_to_place = (item / divisor) % 10;
					temp_buckets[bucket_to_place].addElement(item);

					//if we placed something in a bucket other than zero, we need to keep going
					if (bucket_to_place != 0)
					{
						needs_another_iteration = true;
					}
				}
			}

			buckets = move(temp_buckets);
			temp_buckets = Vector<Vector<int>>{};
			temp_buckets.setSize(10);

			//increment next power multiplier
			power_of_ten += 1;
		}

		//after iteration, put everything back into data
		for (int i = 0; i < buckets[0].getSize(); i++)
		{
			data.setElementAt(buckets[0][i], i);
		}
		return data;
	}


};

#endif