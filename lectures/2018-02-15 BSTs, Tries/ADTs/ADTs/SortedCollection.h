#ifndef SORTED_BAG_H
#define SORTED_BAG_H

#include <exception>
#include "Collection.h"
#include "Indexed.h"

using namespace std;
template <typename T>
class SortedCollection : public Collection<T>
{
private:
    Indexed<T> *_container;

private:

    int binarySearch(const T& value) const
    {
        int low = 0;
        int mid = 0;
        int high = _container->getSize();
        while (low < high)
        {
            mid = (low + high) / 2;
            if (_container->getElementAt(mid) < value)
            {
                low = mid + 1;
            }
            else
            {
                high = mid;
            }
        }
        return low;
    }

public:
    SortedCollection(Indexed<T> *container)
    {
        _container = container;
    }

    ~SortedCollection()
    {
        delete _container;
    }
    virtual void addElement(const T& item)
    {
        int insertLocation = binarySearch(item);
        _container->addElementAt(item, insertLocation);
    }

    virtual void removeElement(const T& item)
    {
        int location = binarySearch(item);
        _container->removeElementAt(location);
    }

    virtual bool containsElement(const T& item) const
    {
        int location = binarySearch(item);
        return location > 0;
    }

    virtual const T& getFirst() const
    {
        return _container->getElementAt(0);
    }

    virtual T& getFirst()
    {
        return _container->getElementAt(0);
    }

    virtual bool isEmpty() const
    {
        return _container->isEmpty();
    }
    virtual int getSize() const
    {
        return _container->getSize();
    }

    virtual T &getElementAt(int index)
    {
        return _container->getElementAt(index);
    }

    virtual const T& getElementAt(int location) const
    {
        return _container->getElementAt(location);
    }

};

#endif