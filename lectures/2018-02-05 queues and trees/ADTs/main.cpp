#include <iostream>
#include <string>
#include "sorting\Sorting.h"
#include "benchmarks\SortingBenchmark.h"
#include "ADTs\Vector.h"
#include "ADTs\StringGraphNode.h"

using namespace std;

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

    //B is connected to A, C, and E
    graph["B"]->addEdge(graph["A"]);
    graph["B"]->addEdge(graph["C"]);
    graph["B"]->addEdge(graph["F"]);

    return 0;
}