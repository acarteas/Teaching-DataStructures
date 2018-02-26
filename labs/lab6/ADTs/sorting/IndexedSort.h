#ifndef INDEXED_SORT_H
#define INDEXED_SORT_H

#include "../ADTs/Indexed.h"

template <typename T>
class IndexedSort
{
public:
	virtual Indexed<T>& sort(Indexed<T>& data) = 0;
};

#endif