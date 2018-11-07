#pragma once
#ifndef DFS_TREE_NODE_H
#define DFS_TREE_NODE_H
#include <vector>
using namespace std;
class DfsTreeNode
{
public:
    int value;
    vector<DfsTreeNode*> children;
    vector<DfsTreeNode*> back_edges;

};

#endif // !DFS_TREE_NODE_H
