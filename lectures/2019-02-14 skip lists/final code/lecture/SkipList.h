#pragma once
#ifndef SKIP_LIST_H
#define SKIP_LIST_H
#include "SkipNode.h"
#include <vector>
using namespace std;

template <typename T>
class SkipList
{
private:

	//each item represents a higher layer in our skip list
	//element 0 is our base layer, 1 is one level higher, etc.
	vector<SkipNode*> _layers;

	SkipNode<T>* findElementBefore(SkipNode<T>* start, const T& item)
	{
		//go until we hit ground floor
		while (start != nullptr && start->getBelow() != nullptr)
		{
			//go right as far as we can
			while (start->getNext()->getValue() < item)
			{
				start = start->getNext();
			}

			//go down one level, repeat process.  Do this until we can't go down any more
			start = start->getBelow();
		}

		//at ground floor, move as far right as we can
		while (start != nullptr && start->getNext()->getValue() < item)
		{
			start = start->getNext();
		}

		//start should be element prior to desired location
		return start;
	}

public:

};

#endif // ! SKIP_LIST_H
