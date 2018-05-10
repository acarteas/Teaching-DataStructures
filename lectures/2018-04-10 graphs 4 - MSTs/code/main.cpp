#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include "sorting\Sorting.h"
#include "benchmarks\SortingBenchmark.h"
#include "ADTs\Vector.h"
#include "ADTs\StringGraphNode.h"
#include "ADTs\GraphEdge.h"

using namespace std;

//wrapper class easy way to compare pointers in STL PQ
class Edge
{
public:
    GraphEdge<string, string>* edge;

    Edge(GraphEdge<string, string>* e = nullptr)
    {
        edge = e;
    }

    //operator overload allows us to use this class within the STL
    //priority queue
    bool operator()(const Edge &lhs,
        const Edge &rhs)
    {
        //to convert between min and max queue, all you need to do
        //is to switch the > with a <
        return lhs.edge->getWeight() > rhs.edge->getWeight();
    }
};

//retuns all edges that have the supplied edge as the source
//NOTE: Adam knows this is very slow.  He made a poor design choice
//when selecting a vector to hold all of his edges.  But he doesn't
//want to go back and do the copy paste of the 100+ lines that connect
//all the edges.
vector<GraphEdge<string, string>*> getEdgesWithSource(
    vector<GraphEdge<string,string>*> all_edges,
    StringGraphNode* source)
{
    vector<GraphEdge<string, string>*> result{};
    for (auto edge : all_edges)
    {
        if (edge->getSource()->getKey() == source->getKey())
        {
            result.push_back(edge);
        }
    }
    return result;
}

vector<GraphEdge<string, string>*> computeMST(
    vector<GraphEdge<string,string>*> &edges,
    StringGraphNode* start
    )
{
    vector<GraphEdge<string, string>*> result{};

    //PQ allows us to pick the least cost edge available to us
    //TODO: check to make sure PQ is being built
    priority_queue <Edge, // what is in our queue
                    vector<Edge>, //stored in a vector
                    Edge //how are we comparing
                    > edge_queue;

    //track what's already connected
    unordered_map<string, StringGraphNode*> connected_vertices{};
    connected_vertices[start->getKey()] = start;

    //begin by placing all edges that have "start" as the source
    //into the PQ
    vector<GraphEdge<string, string>*> edges_to_add =
        getEdgesWithSource(edges, start);
    for (auto edge : edges_to_add)
    {
        edge_queue.push(Edge{ edge });
    }

    //now, we can begin the MST process
    //O(E)
    while (edge_queue.empty() == false)
    {
        //grab next edge
        auto edge = edge_queue.top();

        //O(LogE)
        edge_queue.pop();
       
        //does the edge point to a new place
        if (connected_vertices.count(edge.edge->getSink()->getKey()) == 0)
        {
            StringGraphNode* vertex = dynamic_cast<StringGraphNode*>(edge.edge->getSink());

            //if it is a new place, push on all the new edges.

            //Too slow.  If done properly, can be done in O(1) time
            //O(E)
            auto sink_edges = getEdgesWithSource(edges, vertex);

            for (auto sink_edge : sink_edges)
            {
                //O(LogE)
                edge_queue.push(Edge{ sink_edge });
            }

            //remember that we've been there
            connected_vertices[vertex->getKey()] = vertex;
            result.push_back(edge.edge);
        }
    }

    return result;
}

int main(void)
{
    //maintains full collection of all vertices
    unordered_map<string, StringGraphNode*> graph{};

    //maintains edge connections
    vector<GraphEdge<string, string>*> edges{};

#pragma region graph setup
    //add vertices to graph
    graph["A"] = new StringGraphNode{ "A" };
    graph["B"] = new StringGraphNode{ "B" };
    graph["C"] = new StringGraphNode{ "C" };
    graph["D"] = new StringGraphNode{ "D" };
    graph["E"] = new StringGraphNode{ "E" };
    graph["F"] = new StringGraphNode{ "F" };
    graph["G"] = new StringGraphNode{ "G" };
    graph["H"] = new StringGraphNode{ "H" };

    //A
    edges.push_back(new GraphEdge<string, string>{
        graph["A"],
        graph["B"],
        1
        });
    edges.push_back(new GraphEdge<string, string>{
        graph["A"],
        graph["C"],
        2
        });
    edges.push_back(new GraphEdge<string, string>{
        graph["A"],
        graph["E"],
        3
        });


    //B
    edges.push_back(new GraphEdge<string, string>{
        graph["B"],
        graph["A"],
        1
        });
    edges.push_back(new GraphEdge<string, string>{
        graph["B"],
        graph["C"],
        2
        });
    edges.push_back(new GraphEdge<string, string>{
        graph["B"],
        graph["D"],
        1
        });

    //C
    edges.push_back(new GraphEdge<string, string>{
        graph["B"],
        graph["A"],
        2
        });
    edges.push_back(new GraphEdge<string, string>{
        graph["C"],
        graph["B"],
        2
        });
    edges.push_back(new GraphEdge<string, string>{
        graph["C"],
        graph["D"],
        3
        });
    edges.push_back(new GraphEdge<string, string>{
        graph["C"],
        graph["E"],
        4
        });
    edges.push_back(new GraphEdge<string, string>{
        graph["C"],
        graph["F"],
        5
        });
    edges.push_back(new GraphEdge<string, string>{
        graph["C"],
        graph["G"],
        2
        });
    edges.push_back(new GraphEdge<string, string>{
        graph["C"],
        graph["H"],
        3
        });

    //D
    edges.push_back(new GraphEdge<string, string>{
        graph["D"],
        graph["B"],
        1
        });
    edges.push_back(new GraphEdge<string, string>{
        graph["D"],
        graph["C"],
        3
        });
    edges.push_back(new GraphEdge<string, string>{
        graph["D"],
        graph["H"],
        5
        });

    //E
    edges.push_back(new GraphEdge<string, string>{
        graph["E"],
        graph["A"],
        3
        });
    edges.push_back(new GraphEdge<string, string>{
        graph["E"],
        graph["C"],
        4
        });
    edges.push_back(new GraphEdge<string, string>{
        graph["E"],
        graph["F"],
        4
        });

    //F
    edges.push_back(new GraphEdge<string, string>{
        graph["F"],
        graph["E"],
        4
        });
    edges.push_back(new GraphEdge<string, string>{
        graph["F"],
        graph["C"],
        5
        });
    edges.push_back(new GraphEdge<string, string>{
        graph["F"],
        graph["G"],
        1
        });

    //G
    edges.push_back(new GraphEdge<string, string>{
        graph["G"],
        graph["C"],
        2
        });
    edges.push_back(new GraphEdge<string, string>{
        graph["G"],
        graph["H"],
        4
        });
    edges.push_back(new GraphEdge<string, string>{
        graph["G"],
        graph["F"],
        1
        });

    //H
    edges.push_back(new GraphEdge<string, string>{
        graph["H"],
        graph["G"],
        4
        });
    edges.push_back(new GraphEdge<string, string>{
        graph["H"],
        graph["C"],
        3
        });
    edges.push_back(new GraphEdge<string, string>{
        graph["H"],
        graph["D"],
        5
        });

#pragma endregion

    auto result = computeMST(edges, graph["D"]);
    return 0;
}