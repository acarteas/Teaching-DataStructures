#include <iostream>
#include <string>
#include <algorithm>
#include "sorting\Sorting.h"
#include "benchmarks\SortingBenchmark.h"
#include "ADTs\Vector.h"
#include "ADTs\StringGraphNode.h"

using namespace std;

//Use DFS to determine if node is somehow attached to 
//another having the supplied key
bool isConnected(StringGraphNode* node, 
    string key,
    unordered_map<string, int> &found = unordered_map<string, int>{}
)
{
    if (node == nullptr)
    {
        return false;
    }

    //make sure that we haven't been here before
    if (found[node->getKey()] > 0)
    {
        return false;
    }

    cout << "Looking at " << node->getKey() << endl;
    found[node->getKey()]++;

    //pre-order traversal
    if (node->getKey() == key)
    {
        return true;
    }

    //else visit children
    for (auto item : node->getEdges())
    {
        bool is_found = isConnected(
            dynamic_cast<StringGraphNode*>(item), 
            key,
            found);
        if (is_found == true)
        {
            return true;
        }
    }
    return false;
}

int main(void)
{
    //maintains full collection of all vertices
    unordered_map<string, StringGraphNode*> graph{};

    //add vertices to graph
    graph["A"] = new StringGraphNode{ "A" };
    graph["B"] = new StringGraphNode{ "B" };
    graph["C"] = new StringGraphNode{ "C" };
    graph["D"] = new StringGraphNode{ "D" };
    graph["E"] = new StringGraphNode{ "E" };
    graph["F"] = new StringGraphNode{ "F" };

    //A is connected to B and F
    graph["A"]->addEdge(graph["B"]);
    graph["A"]->addEdge(graph["F"]);

    //B is connected to A, C, and F
    graph["B"]->addEdge(graph["A"]);
    graph["B"]->addEdge(graph["C"]);
    graph["B"]->addEdge(graph["F"]);

    //connect E to D
    graph["E"]->addEdge(graph["D"]);

    //Connect C to F and D
    graph["C"]->addEdge(graph["F"]);
    graph["C"]->addEdge(graph["D"]);

    //Connect D to E
    graph["D"]->addEdge(graph["E"]);

    cout << boolalpha << isConnected(graph["A"], "E");

    pair<string, int> foo{};
    foo.first = "Hello";
    foo.second = 5;

    //question related to pairs and graph edge weights 
    unordered_map<string, pair<StringGraphNode*, int>> weights{};
    for (auto item : weights)
    {
        //item.first => string representing key of graph node
        //item.second.first => graph node pointer
        //item.second.second => edge weight
    }

    return 0;
}