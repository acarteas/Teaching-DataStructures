#include <vector>
#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <unordered_map>
#include <queue>
#include <utility>
#include <algorithm>
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

int main(void)
{
    vector<vector<int>> graph{};
    buildGraph(graph, 100, 500);
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
	
    //        NODE, DISTANCE
    queue<pair<int, int>> to_visit{};
    vector<int> keys{};

    int start = 0;

    //prime our loop
    to_visit.push(make_pair(start, 0));

    //while we haven't seen our destination and while there is more to visit...
    while (to_visit.empty() == false)
    {
        //record the distance between our start and the current node
        pair<int, int> front = to_visit.front();
        int node = front.first;
        to_visit.pop();

        //record distance if not already there
        if (visited.find(node) == visited.end())
        {
            visited[node] = front.second;
            keys.push_back(node);
        }

        //loop through all outgoing edges
        for (int outgoing = 0; outgoing < graph[node].size(); outgoing++)
        {
            //prevent infinite loop
            if (outgoing == node)
            {
                continue;
            }

            //is there a connection?
            if (graph[node][outgoing] > 0)
            {
                //have we seen this one before?
                if (visited.find(outgoing) == visited.end())
                //if(visited[outgoing] > 0)
                {
                    //add to visit queue adding one to present distance
                    to_visit.push(make_pair(outgoing, front.second + 1));
                }
            }
        }
    }

    sort(keys.begin(), keys.end());
}