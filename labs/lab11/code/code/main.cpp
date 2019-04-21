#include <iostream>
#include <string>
#include <vector>
#include <ctime>
using namespace std;

void generateRandomGraph(vector<vector<int>> &graph,
   int graph_size,
   int num_connections)
{
   //uncomment to allow for "random" graph generation
   //srand(time(NULL));

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

bool dfsConnectedSearch(vector<vector<int>>& graph, int start, int end)
{
   return false;
}

bool bfsConnectedSearch(vector<vector<int>>& graph, int start, int end)
{
   return false;
}

int main(void)
{
   vector<vector<int>> graph{};
   generateRandomGraph(graph, 10, 25);
   return 0;
}