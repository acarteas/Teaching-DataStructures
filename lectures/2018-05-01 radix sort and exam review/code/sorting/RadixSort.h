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
		
		return data;
	}


};

#endif