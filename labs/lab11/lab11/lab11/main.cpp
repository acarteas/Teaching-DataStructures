#include <vector>
#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <unordered_map>
#include "DfsTreeNode.h"

using namespace std;

void buildGraph(vector<vector<int>> &graph, int graph_size, int num_connections)
{
    srand(time(NULL));

    //zero out graph and ensure that graph is large enough
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
}
DfsTreeNode* buildDfsTree(vector<vector<int>>& graph, int x, int y, unordered_map<int, int>& visited)
{
    return nullptr;
}

vector<int> getArticulationPoints(DfsTreeNode* root)
{
    vector<int> result{};
    return result;
}


int main(void)
{
    vector<vector<int>> graph{};
    buildGraph(graph, 10, 50);
}