#ifndef GRAPH_NODE_H
#define GRAPH_NODE_H

#include <unordered_map>
#include <vector>
using namespace std;

template <typename Key, typename Value>
class GraphNode
{
protected:

    //what's inside of our node
    Value _value;

    //how we refer to this node
    Key _key;

    //Key to HT is our key type
    //Value of HT is another node in our graph
    unordered_map<Key, GraphNode<Key, Value>*> _vertices;

public:

    GraphNode(const Key &k, const Value &v)
    {
        _value = v;
        _key = k;
    }

    GraphNode()
    {

    }

    //allows for polymorphic behavior
    virtual ~GraphNode() {}

    Value &getValue()
    {
        return _value;
    }

    void setValue(const Value& v)
    {
        _value = v;
    }

    Key& getKey()
    {
        return _key;
    }

    const Key& getKey() const
    {
        return _key;
    }

    void setKey(const Key& k)
    {
        _key = k;
    }

    void addEdge(GraphNode<Key, Value> *node)
    {
        _vertices[node->getKey()] = node;
    }

    vector<GraphNode<Key, Value>*> getEdges()
    {
        vector<GraphNode<Key, Value>*> result{};
        for (auto vertex : _vertices)
        {
            result.push_back(vertex.second);
        }
        return result;
    }

};

template <typename Key, typename Value>
bool operator<(const GraphNode<Key, Value> &left,
               const GraphNode<Key, Value> &right
    )
{
    return left.getKey() < right.getKey();
}

template <typename Key, typename Value>
bool operator>(const GraphNode<Key, Value> &left,
    const GraphNode<Key, Value> &right
    )
{
    return left.getKey() > right.getKey();
}

template <typename Key, typename Value>
bool operator==(const GraphNode<Key, Value> &left,
    const GraphNode<Key, Value> &right
    )
{
    return left.getKey() == right.getKey();
}

template <typename Key, typename Value>
class GraphNodeComparer
{
public:
    bool operator() (GraphNode<Key, Value>* left, 
                    GraphNode<Key, Value>* right
        )
    {
        return left > right;
    }
};

#endif // !GRAPH_NODE_H
