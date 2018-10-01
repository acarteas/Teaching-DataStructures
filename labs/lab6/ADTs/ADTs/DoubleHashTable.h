#ifndef DOUBLE_HASH_TABLE_H
#define DOUBLE_HASH_TABLE_H

#include <string>
#include <sstream>
#include "LinearHashTable.h"

using namespace std;

template <typename Key, typename Value>
class DoubleHashTable : public LinearHashTable<Key, Value>
{
private:
    template<typename S>
    string to_string(S data)
    {
        ostringstream output{};
        output << data;
        return output.str();
    }

protected:

	//double hash uses another hashing attempt for next probe location
	virtual int getNextProbe(int starting_hash, int probe_attempt)
	{
		int second_try = (
			starting_hash + 
			HashTableBase<Key, Value>::getHash(to_string(starting_hash + probe_attempt))
			) % HashTableBase<Key, Value>::_items.size();
		return second_try;
	}

	//to turn off resize, just always return false
	virtual bool needsResize()
	{
		//based on results, it looks like double hashing gets worse at about 50%
		if (HashTableBase<Key, Value>::_number_of_elements > (0.50 * HashTableBase<Key, Value>::_primes[HashTableBase<Key, Value>::_local_prime_index]))
		{
			return true;
		}
		return false;
	}

	virtual void resizeCheck()
	{
		//Right now, resize when load factor > .5; it might be worth it to experiemnt with
		//this value for different kinds of hashtables
		if (needsResize())
		{
			HashTableBase<Key, Value>::_local_prime_index++;

			HasherBase<Key> *hasher = HasherFactory::copyHasher<Key>(*HashTableBase<Key, Value>::_hasher);
			DoubleHashTable<Key, Value> new_hash{ hasher, HashTableBase<Key, Value>::_primes[HashTableBase<Key, Value>::_local_prime_index] };

			for (auto item : HashTableBase<Key, Value>::_items)
			{
				if (item.isEmpty() == false)
				{
					//add to new hash table
					new_hash.addElement(item.getKey(), item.getValue());
				}
			}

			//AC Note: this calls copy operator.  Ideally, we want to call move operator.
			*this = move(new_hash);
		}
	}

public:
	DoubleHashTable(HasherBase<Key> *hasher, int number_of_elements = 11)
		: LinearHashTable<Key, Value>::LinearHashTable(hasher, number_of_elements)
	{
	}

	DoubleHashTable(DoubleHashTable<Key, Value> &other)
		: HashTableBase<Key, Value>::HashTableBase(other)
	{

	}

	DoubleHashTable(DoubleHashTable<Key, Value> &&other)
		: HashTableBase<Key, Value>::HashTableBase(other)
	{

	}

	DoubleHashTable & operator=(DoubleHashTable<Key, Value> &other)
	{
		HashTableBase<Key, Value>::operator=(other);
		return *this;
	}

	DoubleHashTable & operator=(DoubleHashTable<Key, Value> &&other)
	{
		HashTableBase<Key, Value>::operator=(other);
		return *this;
	}
};
#endif
