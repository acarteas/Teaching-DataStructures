#ifndef  INDEXED_COLLECTION_H
#define  INDEXED_COLLECTION_H
#include "Collection.h"
#include "Indexed.h"

//combines Collection and Indexed interfaces.  Adds nothing itself.
template <typename T>
class IndexedCollection : public Collection<T>, public Indexed<T>
{
};

#endif // ! INDEXED_COLLECTION_H
