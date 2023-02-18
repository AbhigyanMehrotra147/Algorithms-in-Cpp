#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class Cycle_detect
{
public:
    // Function to detect cycle in a directed graph.
    bool compare_child_parent(int curr, int child, int parent[])
    {

        // cout << parent[curr] << " ";
        if (parent[curr] == child)
        {
            return true;
        }
        if (parent[curr] == -1)
        {
            return false;
        }
        return compare_child_parent(parent[curr], child, parent);
    }
    bool dfs(int V, int index, vector<int> adj[], vector<bool> &visited, int parent[])
    {
        stack<int> s;
        s.push(index);
        int curr_vertex;
        vector<int> children;
        int count;
        while (!s.empty())
        {
            curr_vertex = s.top();
            s.pop();
            // if(visited[curr_vertex]) continue;
            visited[curr_vertex] = true;
            children = adj[curr_vertex];
            for (int i = 0; i < children.size(); i += 1)
            {
                parent[children[i]] = curr_vertex;
                if (visited[children[i]])
                {
                    // cout << curr_vertex << endl;
                    bool flag = compare_child_parent(curr_vertex, children[i], parent);
                    // cout << endl;
                    if (flag)
                        return true;
                    continue;
                }
                s.push(children[i]);
            }
        }
        return false;
    }
    bool isCyclic(int V, vector<int> adj[])
    {
        vector<bool> visited(V, false);
        int parent[V];
        for (int i = 0; i < V; i += 1)
        {
            parent[i] = -1;
        }
        // cout << endl;
        for (int i = 0; i < V; i += 1)
        {
            if (visited[i])
                continue;
            if (dfs(V, i, adj, visited, parent))
                return true;
        }
        return false;
    }
};
