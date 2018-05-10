#ifndef DISJOINT_SET_H
#define DISJOINT_SET_H

#include <unordered_map>
#include <utility>
#include <iterator>
#include <cmath>

using namespace std;

//our underlying data structure is a hash table
//breakdown:
//T - item to be stored (char in our case)
//pair<int, T>> - used to store the value in the box (see class notes).  
//                   A: When the item is a root (set end-point), the int value should 
//                      be set to a negative value.
//                      When the item is not a root, the int value should be positive.
//                   B: When the item is not a root (set end-point), the T value
//                      should be set to the item's "parent" in the set
// A really complete example of how to manipulate this data structure can be found in the
// "find" function.
template <typename T>
class DisjointSet
{
private:
    unordered_map<T, pair<int, T>> _sets;

    //recursive solution to path compression.  Ends up being a little slower than
    //the iterative approach.
    T& pathCompressionHelper(T &start)
    {
        auto result = _sets.find(start);
        if (result != _sets.end() && result->second.first > 0)
        {
            T&root = pathCompressionHelper(result->second.second);
            result->second.second = root;
            return root;
        }
        else
        {
            return start;
        }
    }

public:

    //for benchmarking different types of disjoint sets
    bool use_path_compression = false;

    void union_with(T &&first, T &&second)
    {
        T f = first;
        T s = second;
        return union_with(first, second);
    }

    
    void union_with(T &first, T &second)
    {
        //#1: call find on both items in the set
        T *first_root = find(first);
        T *second_root = find(second);

        //#2: if the items aren't already in the set, perform a union
        if ((*first_root) != (*second_root))
        {
            //#3: union by size
            pair<int, T> &first_pair = _sets[*first_root];
            pair<int, T> &second_pair = _sets[*second_root];

            //error checking: make sure that both items are indeed root of their
            //respective sets
            if (first_pair.first < 0 && second_pair.first < 0)
            {

                //start with the assumption that "first" is larger
                pair<int, T> *largest = &first_pair;
                pair<int, T> *smallest = &second_pair;
                int first_size = first_pair.first;
                int second_size = second_pair.first;

                //use abs to get rid of negative value
                first_size = abs(first_size);
                second_size = abs(second_size);

                //if second is indeed larger, perform a swap
                if (first_size < second_size)
                {
                    largest = &second_pair;
                    smallest = &first_pair;
                }

                //update largest's size
                largest->first = -(first_size + second_size);

                //make smallest a child of the largest
                smallest->second = largest->second;
                smallest->first = 1;
            }
        }
    }

    T *find(T &&start)
    {
        T item = start;
        return find(item);
    }

    //Gets all roots in the set
    vector<T> getRoots()
    {
        vector<T> roots{};
        for (auto item : _sets)
        {
            if (item.second.first < 0)
            {
                roots.push_back(item.second.second);
            }
        }
        return roots;
    }

    //Attempts to find a given value in the set.  If the item does not exist,
    //find will add the item to the set as its own set (disjoint).  
    T *find(T &start)
    {
        //find item in set
        auto result = _sets.find(start);

        //Use the result to "move up" the set's tree.  We continue as long as the
        //second.first is positive.
        while (result != _sets.end() && result->second.first > 0)
        {
            result = _sets.find(result->second.second);
        }

        //AC: it's probably more efficient to perform path compression inline
        if (use_path_compression == true)
        {
            //unroll all items along the way
            auto compression_result = _sets.find(start);
            while (compression_result != _sets.end() && compression_result->second.second != result->second.second)
            {
                compression_result->second.second = result->second.second;
                compression_result = _sets.find(compression_result->second.second);
            }
            //pathCompressionHelper(start);
        }

        //no result, add new item to underlying hashtable
        if (result == _sets.end())
        {
            _sets[start] = pair<int, T>{};
            _sets[start].first = -1;
            _sets[start].second = start;
            result = _sets.find(start);
        }

        //finally, return a pointer to the item's "root" (send end-point)
        return &(result->second.second);
    }
};

#endif