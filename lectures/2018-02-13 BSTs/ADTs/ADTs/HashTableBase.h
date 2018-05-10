#ifndef HASH_TABLE_BASE_H
#define HASH_TABLE_BASE_H

#include <utility>
#include <exception>
#include <vector>
#include "HashItem.h"
#include "HasherBase.h"
#include "HasherFactory.h"

using namespace std;

/*
Considerations when implementing a Hash Table:
	* How do we convert the key into an integer value (the hash)?
	* What happens when we try to store a KVP in an already full slot (collision)?
	* What are appropriate sizes of the underlying vector?
	* How does performance change as our underlying vector fills up?
		* When is it necessary to resize?
			* How do we resize?
	
*/

template<typename Key, typename Value>
class HashTableBase
{
protected:

	//AC Note: Java uses 11 as the starting hashtable size.
	vector<HashItem<Key, Value>> _items;
	static const int _primes[];
	static const int _primes_count;
	HasherBase<Key> *_hasher;

	//keeps track of our position in our prime index counter
	int _local_prime_index;
	int _number_of_elements;

	//checks to see whether or not it's time to resize.
	virtual void resizeCheck() = 0;

	//shortcut method for calling full hasher's getHash function
	virtual int getHash(const Key &item)
	{
		return _hasher->getHash(item, _items.size() - 1);
	}
public:
#pragma region constructors, destructors, operator overloads
	
	//Default constructor
	HashTableBase(HasherBase<Key> *hasher, int number_of_elements = 11)
	{
		_hasher = hasher;
		_items = vector<HashItem<Key, Value>>{(unsigned)number_of_elements};
		_local_prime_index = 0;
		_number_of_elements = 0;

		while (_primes[_local_prime_index] < number_of_elements)
		{
			_local_prime_index++;
		}
	}

	//copy constructor
	HashTableBase(const HashTableBase<Key, Value> &other)
	{
		_hasher = HasherFactory::copyHasher<Key>(*other._hasher);
		_items = other._items;
		_local_prime_index = other._local_prime_index;
		_number_of_elements = other._number_of_elements;
	}

	//copy operator
	HashTableBase & operator=(HashTableBase<Key, Value> &other)
	{
		_hasher = HasherFactory::copyHasher<Key>(*other._hasher);
		_items = other._items;
		_local_prime_index = other._local_prime_index;
		_number_of_elements = other._number_of_elements;
		return *this;
	}

	//move constructor
	HashTableBase(HashTableBase<Key, Value> &&other)
	{
		swap(other._items, _items);
		_hasher = other._hasher;
		_local_prime_index = other._local_prime_index;
		_number_of_elements = other._number_of_elements;
	}

	//move operator
	HashTableBase & operator=(HashTableBase<Key, Value> &&other)
	{
		swap(other._buckets, _items);
		_hasher = other._hasher;
		_local_prime_index = other._local_prime_index;
		_number_of_elements = other._number_of_elements;
		return *this;
	}

	//destructor
	~HashTableBase()
	{
		delete _hasher;
	}

	//shortcut for getElement
	virtual Value & operator[](Key key)
	{
		try
		{
			return getElement(key);
		}
		catch (...)
		{
			Value v;
			addElement(key, v);
			return getElement(key);
		}
	}
#pragma endregion

	//determines whether or not a given key exists in the hash table
	virtual bool hasKey(Key key)
	{
		try
		{
			Value &result = getElement(key);
			return true;
		}
		catch (...)
		{
			return false;
		}
	}

	//returns all keys present in the hashtable
	//AC Class Question: How can we make this more efficient?
	virtual vector<Key> getKeys()
	{
		vector<Key> keys;

		//iteration -- C++ 11 style!
		for (auto item : _items)
		{
			if (item.isEmpty() == false)
			{
				keys.push_back(item.getKey());
			}
		}
		return keys;
	}

	//for unit testing only (will be turned off)
	vector<HashItem<Key, Value>> &getItems()
	{
		return _items;
	}

	//TODO: Implement remove function based on desired collision mechanism
	virtual void removeElement(Key key) = 0;

	//TODO: Implement contains check based on desired collision mechanism
	virtual bool containsElement(Key key) = 0;

	//TODO: Implement getElement method based on desired collision mechanism
	virtual Value &getElement(Key key) = 0;

	//TODO: Implement add function based on desired collision mechanism
	virtual void addElement(const Key &key, const Value &value) = 0;
};

template<typename Key, typename Value>
const int HashTableBase<Key, Value>::_primes[] = { 11, 47, 97, 197, 379, 691, 1259, 2557, 5051, 7919, 14149, 28607, 52817, 102149, 209939, 461017, 855683, 1299827 };

template<typename Key, typename Value>
const int HashTableBase<Key, Value>::_primes_count = 18;
#endif