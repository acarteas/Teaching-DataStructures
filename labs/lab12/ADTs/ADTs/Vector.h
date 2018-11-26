#ifndef VECTOR_H
#define VECTOR_H

#include "IndexedCollection.h"
#include <stdexcept>
#include <initializer_list>
using namespace std;

template <typename T>
class Vector : public IndexedCollection<T>
{
private:

    //Calling this method will resize the Vector if necessary
    void checkCapacity(int requested_size)
    {
        //two possibilities: are we too small or are we too large?
        if (requested_size >= _max_size)
        {
            //compute a value of _max_size that will be large
            //enough to accommodate our requested size
            int new_size = _max_size;
            while (requested_size >= new_size)
            {
                new_size = (new_size * 2) + 1;
            }

            //now that we're large enough, we can adjust our size
            adjustSize(new_size);
        }

        //what if, we look at the ratio of _logical_size / _max_size
        //If < .5 w/ at least one free box, shrink
    }

    void adjustSize(int new_size)
    {
        //error checking: new_size > 0
        if (new_size < 1)
        {
            throw out_of_range("new_size is not greater than 0");
        }

        //Assumption (invariant) "We know this to be true"
        //new_size now must be valid
        T *new_array = new T[new_size];

        //Possible relationship between new_size and _logical_size
        //new_size > _logical_size -> grow items
        //new_size < _logical_size -> shrink
        int smaller_size = (new_size < _logical_size)
            ? new_size          //chosen if new_size is smaller
            : _logical_size;    //chosen if _logical_size is smaller

                                //Now that we know the smaller size, we can safely copy
        for (int i = 0; i < smaller_size; i++)
        {
            new_array[i] = _items[i];
        }

        //delete old array
        delete[] _items;

        //assume ownership of temporary array
        _items = new_array;
        _logical_size = smaller_size;
        _max_size = new_size;
    }

    //I'm making variables protected so that I can give access
    //to any potential children.
protected:

    //We are using a pointer to act like an array of T thing
    T *_items = nullptr;

    //tracks the max size of our array
    int _max_size = 0;

    //tracks the actual number of boxes presently in use
    int _logical_size = 0;

public:

    //initializer list constructor
    Vector(initializer_list<T> values)
    {
        _max_size = values.size();
        _logical_size = 0;
        _items = new T[_max_size];

        //cool C++ 11 way to iterate!
        for (auto item : values)
        {
            addElement(item);
        }
    }

    //Constructor.  Gets called automatically when we define
    //a new instance of the class.
    Vector(int initial_size = 0)
        : _max_size(initial_size),  //_max_size = initial_size
        _logical_size(0)
    {
        //if we were given an initial size, allocate memory for
        //_items
        if (initial_size > 0)
        {
            _items = new T[initial_size];
        }
    }

    Vector(const Vector<T> &other)
        : _items(nullptr)
    {
        //don't copy ourselves!
        if (this != &other)
        {
            //delete existing contents if they exit
            if (_items != nullptr)
            {
                delete[] _items;
            }

            //allocate space for new items
            _max_size = other.getSize() + 1;
            _logical_size = other.getSize();
            _items = new T[_max_size];

            //make copies of other's items
            for (int i = 0; i < _logical_size; i++)
            {
                T item = other.getElementAt(i);
                _items[i] = item;
            }
        }
    }

    //Move constructor. 
    Vector(Vector<T> &&other)
        : _items(nullptr)
    {
        //get other's meta data
        _max_size = other._max_size;
        _logical_size = other._logical_size;

        //then steal its pointer
        _items = other._items;

        //and give it nullptr instead
        other._items = nullptr;
    }

    //purpose of destructor: clean up dynamic memory
    virtual ~Vector()
    {
        delete[] _items;
    }

#pragma region Collection interface implementation

    //For Vector, addElement will add item to the end of 
    //the logical space
    virtual void addElement(const T& item)
    {
        //ensure that we have enough space
        checkCapacity(_logical_size + 1);

        //Assumption: once we're here, we are guaranteed that
        //we have enough space to place item
        _items[_logical_size] = item;

        //increment logical size
        _logical_size++;
    }

    //return the index of the first occurrence of item.
    //-1 returned if not found
    virtual int findElement(const T& item) const
    {
        for (int i = 0; i < _logical_size; i++)
        {
            if (_items[i] == item)
            {
                return i;
            }
        }
        return -1;
    }

    //removes first instance of item in vector
    virtual void removeElement(const T& item)
    {
        int index_to_remove = findElement(item);
        if (index_to_remove > -1)
        {
            removeElementAt(index_to_remove);
        }
    }

    //returns true if item is held inside vector
    virtual bool containsElement(const T& item) const
    {
        return findElement(item) > -1;
    }

    virtual const T& getFirst() const
    {
        //if no items to return, we should probably throw
        //and error
        if (_logical_size == 0)
        {
            throw out_of_range{ "Vector is empty" };
        }
        return _items[0];
    }
    virtual T& getFirst()
    {
        //if no items to return, we should probably throw
        //and error
        if (_logical_size == 0)
        {
            throw out_of_range{ "Vector is empty" };
        }
        return _items[0];
    }

    //returns logical size of vector
    virtual int getSize() const
    {
        return _logical_size;
    }

    //returns whether or not vector is empty
    virtual bool isEmpty() const
    {
        return _logical_size == 0;
    }
#pragma endregion

#pragma region Indexed overrides

    //returns the item at the specified index
    virtual T& getElementAt(int location)
    {
        if (location < 0 || location >= _logical_size)
        {
            throw out_of_range("Index out of range.");
        }
        return _items[location];
    }

    //const version of getElementAt
    virtual const T &getElementAt(int index) const
    {
        if (index < 0 || index >= _logical_size)
        {
            throw out_of_range("Index out of range.");
        }
        return _items[index];
    }

    //sets the item at the specified index
    virtual void setElementAt(T value, int location)
    {
        //check capacity before retrieving
        checkCapacity(location);
        _items[location] = value;

        //if this index is larger than our currently tracked _number_of_items,
        //replace with specified index
        if (_logical_size <= location)
        {
            _logical_size = location + 1;
        }
    }

    //adds the item at the specified index and shifts all larger items
    //"right" by one
    virtual void addElementAt(T value, int location)
    {
        //check to make sure that we have enough room at the end
        //of the array for the add.
        checkCapacity(_logical_size + 1);

        //shift every item to the right
        //worst case is location == 0
        //best case is location == number of items
        for (int i = _logical_size - 1; i >= location; i--)
        {
            setElementAt(_items[i], i + 1);
        }

        //now that we have a spot for our item, add it to our array
        setElementAt(value, location);
    }

    //removes the item at the specified index and shifts all smaller items
    //"left" by one
    virtual void removeElementAt(int index)
    {
        //make sure that we're in bounds
        if (index < 0 || index >= _max_size)
        {
            throw out_of_range("Index out of bounds.");
        }

        //shift everything left
        //worst case: index == 0
        //best case:  index == number of items
        //O(N) - N = size of array
        for (int i = index; i < _logical_size - 1; i++)
        {
            _items[i] = _items[i + 1];
        }

        //do the last shift if we have room
        if (_logical_size < _max_size)
        {
            _items[_logical_size - 1] = _items[_logical_size];
        }

        //decrement the number of items in our array
        _logical_size--;
    }
#pragma endregion

#pragma region operator overloads

    //Copy operator 
    virtual Vector<T> & operator=(const Vector<T> &other)
    {
        //remove existing items if we have any
        if (this->_items != nullptr)
        {
            delete[] _items;
        }

        //allocate new space
        _items = new T[other.getSize()];

        //copy other's meta data
        _max_size = other._max_size;
        _logical_size = other._logical_size;

        //copy other's items
        for (int i = 0; i < other.getSize(); i++)
        {
            setElementAt(other.getElementAt(i), i);
        }

        //Kind of goofy syntax, but we need to return a reference to ourselves.  Recall that
        //"this" refers to whatever object is calling this code.  Also recall that "this"
        //is a pointer, so we have to dereference us in order to return ourselves as a 
        //reference.
        return *this;
    }

    //Move operator
    virtual Vector<T> &operator=(Vector<T> &&other)
    {
        //take care of any information we already have before stealing other's data
        if (_items != nullptr)
        {
            delete[] _items;
        }

        //get other's meta data
        _max_size = other._max_size;
        _logical_size = other._logical_size;

        //then steal its pointer
        _items = other._items;

        //and give it nullptr instead
        other._items = nullptr;

        //return a reference to ourselves
        return *this;
    }

    //shortcut for getElementAt
    virtual T&  operator[](int index)
    {
        return getElementAt(index);
    }

    //shortcut for getElementAt
    virtual const T& operator[](int index) const
    {
        return getElementAt(index);
    }

#pragma endregion

    void setSize(int new_size)
    {
        adjustSize(new_size);
        _logical_size = new_size;
    }
};

#endif // ! VECTOR_H
