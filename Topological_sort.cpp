//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Function to return list containing vertices in Topological order.

    void connected_component_topo_sort(vector<int> adj[], vector<bool> &visited, stack<int> &s1, stack<int> &s2)
    {
        int count;
        while (!s1.empty())
        {
            int vertex = s1.top();
            count = 0;
            for (register int i = 0; i < adj[vertex].size(); i += 1)
            {
                if (visited[adj[vertex][i]])
                    continue;
                count += 1;
                s1.push(adj[vertex][i]);
                visited[adj[vertex][i]] = true;
            }
            if (!count)
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
    }
    vector<int> topoSort(int V, vector<int> adj[])
    {
        stack<int> s1;
        stack<int> s2;
        vector<bool> visited(V, false);
        vector for (register int i = 0; i < V; i += 1)
        {
            if (visited[i])
                continue;
            s1.push(i);
            visited[i] = true;
            connected_component_topo_sort(adj, visited, s1, s2);
        }
        vector<int> sorted;
        while (!s2.empty())
        {
            sorted.push_back(s2.top());
            s2.pop();
        }
        cout << sorted.size() << endl;
        for (int k = 0; k < sorted.size(); k += 1)
        {
            cout << sorted[k] << " ";
        }
        cout << endl;
        return sorted;
    }
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
 *   contains the elements in topological sorted form
 *   V: number of vertices
 *   *res: array containing elements in topological sorted form
 *   adj[]: graph input
 */
int check(int V, vector<int> &res, vector<int> adj[])
{

    if (V != res.size())
        return 0;

    vector<int> map(V, -1);
    for (int i = 0; i < V; i++)
    {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++)
    {
        for (int v : adj[i])
        {
            if (map[i] > map[v])
                return 0;
        }
    }
    return 1;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++)
        {
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }

    return 0;
}
// } Driver Code Ends