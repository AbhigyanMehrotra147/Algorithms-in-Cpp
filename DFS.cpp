#include <iostream>
#include <vector>
using namespace std;
class Recursive_dfs
{
    vector<int> DDFS;
    vector<bool> flag;

public:
    // Function to return a list containing the DFS traversal of the graph.
    void assign(int V, vector<int> adj[])
    {
        for (int i = 0; i < V; i += 1)
        {
            flag.push_back(false);
        }
    }
    void a_vertex(vector<int> adj[], int index)
    {
        if (flag[index] == true)
        {
            return;
        }
        DDFS.push_back(adj[index][0]);
        flag[index] = true;
        for (int i = 0; i < adj[index].size(); i += 1)
        {
            int k = adj[index][i];
            int j = 0;
            while (k != adj[j][0])
            {
                j = j + 1;
            }
            a_vertex(adj, k);
            return;
        }
    }
    void DFS(int V, vector<int> adj[])
    {
        assign(V, adj);
        for (int i = 0; i < V; i += 1)
        {
            a_vertex(adj, i);
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        DFS(V, adj);
        vector<int> ans(DDFS);
        DDFS.clear();
        return ans;
    }
};
#include <stack>
class Efficient_dfs
{
public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        vector<int> dfs;
        vector<bool> visited(V, false);
        stack<int> s;
        s.push(0);
        while (!s.empty())
        {
            int vertex = s.top();
            if (visited[vertex] == true)
            {
                s.pop();
                continue;
            }
            dfs.push_back(vertex);
            visited[vertex] = true;
            s.pop();
            for (int i = adj[vertex].size() - 1; i > -1; i -= 1)
            {
                s.push(adj[vertex][i]);
            }
        }
        return dfs;
    }
};
