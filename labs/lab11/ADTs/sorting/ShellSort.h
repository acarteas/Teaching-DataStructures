#ifndef SHELL_SORTER_H
#define SHELL_SORTER_H

#include "IndexedSort.h"

template <typename T>
class ShellSort : public IndexedSort<T>
{
private:
    //First few numbers taken from https://oeis.org/A102549
    int _gap_sequence[14] = {1, 4, 10, 23, 57, 132, 301, 701, 1750, 3675, 7717, 16206, 34034, 71471};
    int _gap_count = 14;
public:

    //shell sort is basically the same as indexed sort but with an additional "gap" that sorts subparts
    virtual Indexed<T>& sort(Indexed<T>& data)
    {
        for (int gap = _gap_count - 1; gap > -1; gap--)
        {
            for (int i = gap; i < data.getSize(); i++)
            {
                T to_compare = data.getElementAt(i);
                int j = i;
                while (j > gap
                    && data.getElementAt(j - gap) > to_compare
                    )
                {
                    T temp = data.getElementAt(j - gap);
                    data.setElementAt(temp, j);
                    j -= gap;
                }
                data.setElementAt(to_compare, j);
            }
        }
            
        return data;
    }
};

#endif