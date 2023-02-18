#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Srecursive_bfs
{
public:
    vector<vector<int>> create_list(int N, vector<vector<int>> graph)
    {
        vector<vector<int>> adjacency_list;

        for (int i = 0; i < N; i += 1)
        {
            vector<int> temp;
            for (int j = 0; j < N; j += 1)
            {
                if (graph[i][j] == 0)
                {
                    continue;
                }
                temp.push_back(j);
            }
            adjacency_list.push_back(temp);
        }
        return adjacency_list;
    }
    vector<vector<int>> transitiveClosure(int N, vector<vector<int>> graph)
    {
        vector<int> temp(N, 0);
        vector<vector<int>> transitive(N, temp);
        stack<int> s;
        vector<vector<int>> adjacency_list = create_list(N, graph);
        // Each i is a vertex
        for (int i = 0; i < N; i += 1)
        {
            vector<bool> visited(N, false);
            s.push(i);
            transitive[i][i] = 1;
            while (!s.empty())
            {
                int vertex = s.top();
                s.pop();
                if (visited[vertex] == true)
                {
                    continue;
                }
                visited[vertex] = true;
                for (int j = adjacency_list[vertex].size() - 1; j > -1; j -= 1)
                {
                    // cout << adjacency_list[vertex][j] << " ";
                    transitive[i][adjacency_list[vertex][j]] = 1;
                    s.push(adjacency_list[vertex][j]);
                }
            }
        }
        return transitive;
    }
};
#include <queue>
class Efficient_bfs
{
public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[])
    {
        queue<int> q;
        vector<int> bfs;
        vector<bool> visited(V, false);
        q.push(0);
        while (!q.empty())
        {
            int vertex = q.front();
            q.pop();
            if (visited[vertex] == true)
            {
                continue;
            }
            bfs.push_back(vertex);
            visited[vertex] = true;
            for (int i = 0; i < adj[vertex].size(); i += 1)
            {
                q.push(adj[vertex][i]);
            }
        }
        return bfs;
    }
};