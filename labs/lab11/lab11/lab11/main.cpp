#include <vector>
#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <unordered_map>
#include "DfsTreeNode.h"

using namespace std;

void buildGraph(vector<vector<int>> &graph, 
	int graph_size, 
	int num_connections)
{
    srand(time(NULL));

    //zero out graph and ensure that graph is 
	//large enough
    if (graph.size() < graph_size)
    {
        graph.resize(graph_size);
    }
    for (int i = 0; i < graph.size(); i++)
    {
        if (graph[i].size() < graph_size)
        {
            graph[i].resize(graph_size);
        }
        for (int j = 0; j < graph[i].size(); j++)
        {
            graph[i][j] = 0;
        }
    }
    for (int i = 0; i < num_connections; i++)
    {
        int x = rand() % graph_size;
        int y = rand() % graph_size;
        graph[x][y] = 1;
    }

	//zero out diagonal (do not allow self-connections)
	for (int i = 0; i < graph_size; i++)
	{
		graph[i][i] = 0;
	}
}
void buildDfsTree(
	vector<vector<int>>& graph, 
	int node, 
	int visit_order,
	unordered_map<int, int>& visited
	)
{
	
	return;
}

void getArticulationPoints(
	vector<vector<int>>& graph,
	int node,
	unordered_map<int, int>& low_values,
	vector<int>& articulation_points
)
{
	
}

int main(void)
{
    vector<vector<int>> graph{};
    buildGraph(graph, 5, 0);
	graph[0][3] = 1;
	graph[1][2] = 1;
	graph[1][4] = 1;
	graph[2][0] = 1;
	graph[2][1] = 1;
	graph[2][4] = 1;
	graph[3][0] = 1;
	graph[3][1] = 1;
	graph[3][4] = 1;
	unordered_map<int, int> visited{};
	buildDfsTree(graph, 0, 1, visited);
	unordered_map<int, int> low_values{};
	vector<int> articulation_points{};
	getArticulationPoints(
		graph, 
		0, 
		low_values, 
		articulation_points
	);
}