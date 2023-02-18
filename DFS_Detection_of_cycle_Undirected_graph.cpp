#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class Cycle_detect
{
public:
    vector<bool> visited;
    // Function to detect cycle in an undirected graph.

    bool dfs(int V, int index, vector<int> adj[])
    {
        stack<int> s;
        s.push(index);
        int count = 0;
        while (!s.empty())
        {
            count = 0;
            int vertex = s.top();
            s.pop();
            visited[vertex] = true;
            for (int i = 0; i < adj[vertex].size(); i += 1)
            {
                if (visited[adj[vertex][i]] == true)
                {
                    count += 1;
                    continue;
                }
                s.push(adj[vertex][i]);
            }
            if (count == 1 || count == 0)
                continue;
            if (count == adj[vertex].size())
                return true;
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[])
    {
        vector<bool> temp(V, false);
        visited = temp;
        for (int i = 0; i < V; i += 1)
        {
            if (visited[i] == true)
                continue;
            if (dfs(V, i, adj))
                return true;
        }
        return false;
    }
};
