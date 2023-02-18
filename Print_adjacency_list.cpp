#include <iostream>
#include <vector>
using namespace std;
class Solution
{
    vector<int> dfs;
    vector<bool> visited;

public:
    // Function to return a list containing the DFS traversal of the graph.
    void fill_visited(int V)
    {
        vector<bool> temp(V, false);
        visited = temp;
    }
    void traverse_single_vertex(vector<int> adj[], int index)
    {
        if (visited[index] == true)
        {
            return;
        }
        dfs.push_back(index);
        visited[index] = true;
        for (int i = 0; i < adj[index].size(); i += 1)
        {
            traverse_single_vertex(adj, adj[index][i]);
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        fill_visited(V);
        for (int i = 0; i < V; i += 1)
        {
            traverse_single_vertex(adj, 0);
        }
        vector<int> ans(dfs);
        dfs.clear();
        return ans;
    }
};