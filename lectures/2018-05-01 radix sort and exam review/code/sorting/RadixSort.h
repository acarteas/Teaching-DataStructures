#ifndef RADIX_SORT_H
#define RADIX_SORT_H

#include "IndexedSort.h"
#include <vector>

#include <cmath>

using namespace std;
class RadixSort : public IndexedSort<int>
{
private:

public:
	virtual Indexed<int>& sort(Indexed<int>& data)
	{
        //two sets of buckets.  One for the current iteration and one
        //for the next iteration
        vector<vector<int>> buckets{};
        vector<vector<int>> temp_buckets{};

        //10 buckets - one for each digit
        buckets.resize(10);
        temp_buckets.resize(10);

        //prime loop by throwing all values into the 0s bucket
        for (int i = 0; i < data.getSize(); i++)
        {
            buckets[0].push_back(data.getElementAt(i));
        }

        //tracks whether or not we've processed all digits
        //for all numbers
        bool needs_another_iteration = true;

        //tracks current power of ten that we're processing
        int power_of_ten = 0;
        while (needs_another_iteration == true)
        {
            //begin by assuming that we don't need another iteration
            needs_another_iteration = false;

            //find next divisor
            int divisor = pow(10, power_of_ten);

            //find new location of all data based on this power
            for (int i = 0; i < 10; i++)
            {
                for (int j = 0; j < buckets[i].size(); j++)
                {
                    int item = buckets[i][j];
                    int division_result = item / divisor;
                    int destination_bucket = division_result % 10;
                    temp_buckets[destination_bucket].push_back(item);

                    //proof by contradiction: is the bucket not zero
                    if (destination_bucket != 0 || division_result != 0)
                    {
                        needs_another_iteration = true;
                    }
                }
            }

            //move everything from temp bucket to bucket
            buckets = move(temp_buckets);
            temp_buckets = vector<vector<int>>{};
            temp_buckets.resize(10);

            //ensure that next iteration considers next power of 10
            power_of_ten++;

        }

        //copy things over from 0s bucket to the final return value
        for (int i = 0; i < buckets[0].size(); i++)
        {
            data.setElementAt(buckets[0][i], i);
        }

		return data;
	}


};

#endif