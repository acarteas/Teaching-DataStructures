#ifndef HASH_ITEM_H
#define HASH_ITEM_H
#include <utility>

using namespace std;
template <typename Key, typename Value>
class HashItem
{
private:
	bool _is_empty = true;
	Value _item;
	Key _key;

public:

	HashItem()
	{

	}

	HashItem(const Key &key, const Value &value, const bool is_empty = true)
	{
		_key = key;
		_item = value;
		_is_empty = is_empty;
	}

	HashItem(Key &&key, Value &&value)
	{
		swap(_key, key);
		swap(_item, _item);
	}

	const Value &getValue() const
	{
		return _item;
	}

	Value &getValue()
	{
		return _item;
	}

	//copy "set" operation
	void setValue(const Value &item)
	{
		_item = item;
	}

	//move "set" operation
	void setValue(Value &&item)
	{
		swap(_item, item);
	}

	const Key &getKey() const
	{
		return _key;
	}

	Key &getKey()
	{
		return _key;
	}

	void setKey(const Key &key)
	{
		_key = key;
	}

	void setKey(Key &&key)
	{
		swap(_key, key);
	}

	bool isEmpty() const
	{
		return _is_empty;
	}

	void setIsEmpty(bool value)
	{
		_is_empty = value;
	}
};

#endif