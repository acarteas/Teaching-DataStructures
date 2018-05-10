#ifndef GRAPH_EDGE_H
#define GRAPH_EDGE_H

#include "GraphNode.h"

template <typename Key, typename Value>
class GraphEdge
{
private:
    //source = starting location
    GraphNode<Key, Value>* _source = nullptr;

    //sink = destination
    GraphNode<Key, Value>* _sink = nullptr;
    int _weight = 0;

public:

    GraphEdge(GraphNode<Key, Value>* source = nullptr,
            GraphNode<Key, Value>* sink = nullptr,
            int weight = 0
        )
    {
        _source = source;
        _sink = sink;
        _weight = weight;
    }

    int getWeight() const
    {
        return _weight;
    }

    GraphNode<Key, Value>* getSource()
    {
        return _source;
    }

    GraphNode<Key, Value>* getSink()
    {
        return _sink;
    }

    //operator overload allows us to use this class within the STL
    //priority queue
    bool operator()(const GraphEdge<Key, Value> &lhs,
        const GraphEdge<Key, Value> &rhs)
    {
        //to convert between min and max queue, all you need to do
        //is to switch the > with a <
        return lhs.getWeight() > rhs.getWeight();
    }
};

#endif