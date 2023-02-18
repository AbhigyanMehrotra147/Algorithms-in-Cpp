#include <iostream>
#include <vector>
using namespace std;
class Cycle_detect
{
public:
    // Function to detect cycle using DSU in an undirected graph.
    int find(int x, int parent[])
    {
        if (parent[x] == x)
        {
            return x;
        }
        return find(parent[x], parent);
    }
    void _union(int x, int y, int parent[])
    {
        parent[x] = y;
    }
    int detectCycle(int V, vector<int> adj[])
    {
        int parent[V] = {0};
        for (int i = 0; i < V; i += 1)
        {
            parent[i] = i;
        }
        vector<bool> temp(V, false);
        vector<vector<bool>> visited(V, temp);
        int f1;
        int f2;
        for (int i = 0; i < V; i += 1)
        {
            for (int j = 0; j < adj[i].size(); j += 1)
            {
                if (visited[adj[i][j]][i] == true)
                    continue;
                visited[i][adj[i][j]] = true;
                visited[adj[i][j]][i] = true;
                f1 = find(i, parent);
                f2 = find(adj[i][j], parent);
                if (f1 == f2)
                    return 1;
                _union(f1, f2, parent);
            }
        }
        return 0;
    }
};