#ifndef BUCKET_HASH_TABLE_H
#define BUCKET_HASH_TABLE_H

#include "HashTableBase.h"
#include "HashItem.h"
#include <vector>
#include <stdexcept>
using namespace std;

template <typename Key, typename Value>
class BucketHashTable : public HashTableBase<Key, Value>
{
private:

	//bucket hash table uses its own data structure to hold items.  There's
	//probably a better OOP appraoch to this, but it works for instructional purposes.
	vector<HashItem<Key, vector<HashItem<Key, Value>>>> _buckets;

protected:

	virtual int getHash(const Key &item)
	{
		return HashTableBase<Key, Value>::_hasher->getHash(item, _buckets.size() - 1);
	}

	//determines whether or not we need to resize
	//to turn off resize, just always return false
	virtual bool needsResize()
	{
		//class activity: explore impact of load factor
		if (HashTableBase<Key, Value>::_number_of_elements > (0.5 * HashTableBase<Key, Value>::_primes[HashTableBase<Key, Value>::_local_prime_index]))
		{
			return true;
		}
		return false;
	}

	//called to check to see if we need to resize
	virtual void resizeCheck()
	{
		//resize if necessary
		if (needsResize())
		{
			HashTableBase<Key, Value>::_local_prime_index++;


			HasherBase<Key> *hasher = HasherFactory::copyHasher<Key>(*HashTableBase<Key, Value>::_hasher);
			BucketHashTable<Key, Value> new_hash{ hasher, HashTableBase<Key, Value>::_primes[HashTableBase<Key, Value>::_local_prime_index] };

			for (HashItem<Key, vector<HashItem<Key, Value>>> item : _buckets)
			{
				for (auto sub_item : item.getValue())
				{
					if (sub_item.isEmpty() == false)
					{
						//add to new hash table
						new_hash.addElement(sub_item.getKey(), sub_item.getValue());
					}
				}
			}
			*this = move(new_hash);
		}
	}

public:

	//Default constructor
	BucketHashTable(HasherBase<Key> *hasher, int number_of_elements = 11)
		: HashTableBase<Key, Value>::HashTableBase(hasher)
	{
		_buckets = vector<HashItem<Key, vector<HashItem<Key, Value>>>>{(unsigned)number_of_elements};
		HashTableBase<Key, Value>::_local_prime_index = 0;
		HashTableBase<Key, Value>::_number_of_elements = 0;

		while (HashTableBase<Key, Value>::_primes[HashTableBase<Key, Value>::_local_prime_index] < number_of_elements)
		{
			HashTableBase<Key, Value>::_local_prime_index++;
		}
	}

	//copy constructor
	BucketHashTable(const BucketHashTable<Key, Value> &other)
		: HashTableBase<Key, Value>::HashTableBase(other)
	{
		_buckets = other._buckets;
	}

	//copy operator
	BucketHashTable & operator=(BucketHashTable<Key, Value> &other)
	{
		HashTableBase<Key, Value>::operator=(other);
		_buckets = other._buckets;
		return *this;
	}

	//move constructor
	BucketHashTable(BucketHashTable<Key, Value> &&other)
		: HashTableBase<Key, Value>::HashTableBase(other)
	{
		swap(other._buckets, _buckets);
	}

	//move operator
	BucketHashTable & operator=(BucketHashTable<Key, Value> &&other)
	{
		HashTableBase<Key, Value>::operator=(other);
		swap(other._buckets, _buckets);
		return *this;
	}

	//concrete implementation for parent's addElement method
	virtual void addElement(const Key &key, const Value &value)
	{
		//check for size restrictions
		resizeCheck();

		//calculate hash based on key
		int hash = getHash(key);

		//find the bucket
		HashItem<Key, vector<HashItem<Key, Value>>> *bucket = &_buckets[hash];

		//and then find the item in the bucket if it exists
		HashItem<Key, Value> *item = nullptr;
		for (auto bucket_item : bucket->getValue())
		{
			if (bucket_item.getKey() == key)
			{
				item = &bucket_item;
			}
		}

		//create value if none exists
		if (item == nullptr)
		{
			HashItem<Key, Value> kvp = HashItem<Key, Value>{key, value};
			kvp.setIsEmpty(false);
			bucket->getValue().push_back(kvp);
		}
		else
		{
			item->setValue(value);
		}

		//bucket cannot be empty
		bucket->setIsEmpty(false);

		//remember how many things we're presently storing
		HashTableBase<Key, Value>::_number_of_elements++;
	}

	//removes supplied key from hash table
	virtual void removeElement(Key key)
	{
		//calculate hash
		int hash = getHash(key);

		//find key in bucket
		HashItem<Key, vector<HashItem<Key, Value>>> *bucket = &_buckets[hash];
		bool found = false;
		for (auto item : bucket->getValue())
		{
			if (item.getKey() == key)
			{
				//lazy delete -- will actually get removed on next resize
				item.setIsEmpty(true);
				found = true;
			}
		}

		//throw exception if key not found
		if (found == false)
		{
			throw out_of_range{"Key not found."};
		}
		HashTableBase<Key, Value>::_number_of_elements--;
	}

	//returns true if the key is contained in the hash table
	virtual bool containsElement(Key key)
	{
		//calculate hash
		int hash = getHash(key);

		//find key in bucket
		HashItem<Key, vector<HashItem<Key, Value>>> *bucket = &_buckets[hash];
		bool found = false;
		for (auto item : bucket->getValue())
		{
			if (item.getKey() == key)
			{
				found = true;
				break;
			}
		}
		return found;
	}

	//returns the item pointed to by key
	virtual Value &getElement(string key)
	{
		//calculate hash
		int hash = getHash(key);

		//find key in bucket
		HashItem<Key, vector<HashItem<Key, Value>>> *bucket = &_buckets[hash];
		bool found = false;
		for (auto item : bucket->getValue())
		{
			if (item.getKey() == key)
			{
				return item.getValue();
			}
		}

		//throw exception if key not found
		throw out_of_range{"Key not found."};
	}

	//returns all keys present in the hashtable
	//BHT has to override this because it uses _buckets instead
	//of base class' _items
	virtual vector<Key> getKeys()
	{
		vector<Key> keys;

		for (auto bucket : _buckets)
		{
			for (auto item : bucket.getValue())
			{
				if (item.isEmpty() == false)
				{
					keys.push_back(item.getKey());
				}
			}
		}
		return keys;
	}
};

#endif
