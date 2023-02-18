//{ Driver Code Starts
#include <vector>
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#include <stack>
class Solution
{
public:
    void print(vector<vector<int>> adj, int V)
    {
        for (int i = 0; i < V; i += 1)
        {
            for (int j = 0; j < adj[i].size(); j += 1)
            {
                cout << adj[i][j] << " ";
            }
            cout << endl;
        }
    }
    vector<vector<int>> convert_to_list(vector<vector<int>> adj, int V)
    {
        vector<int> temp;
        vector<vector<int>> adj_list;
        for (int i = 0; i < V; i += 1)
        {
            for (int j = 0; j < V; j += 1)
            {
                if (adj[i][j] == 1)
                {
                    temp.push_back(j);
                }
            }
            adj_list.push_back(temp);
            temp.clear();
        }
        return adj_list;
    }
    int dfs_single_vertex(vector<vector<int>> adj_list, int index, vector<bool> &visited)
    {
        if (adj_list[index].size() == 0)
            return 0;
        stack<int> s;
        s.push(index);
        while (!s.empty())
        {
            int vertex = s.top();
            s.pop();
            if (visited[vertex])
                continue;
            visited[vertex] = true;
            for (int i = 0; i < adj_list[vertex].size(); i += 1)
            {
                s.push(adj_list[vertex][i]);
            }
        }
        return 1;
    }
    int numProvinces(vector<vector<int>> adj, int V)
    {
        vector<vector<int>> adj_list = convert_to_list(adj, V);
        // print(adj_list,V);
        vector<bool> visited(V, false);
        int No_of_islands = 0;
        for (int i = 0; i < V; i += 1)
        {
            if (visited[i])
                continue;
            No_of_islands += dfs_single_vertex(adj_list, i, visited);
        }
        return No_of_islands;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int V, x;
        cin >> V;

        vector<vector<int>> adj;

        for (int i = 0; i < V; i++)
        {
            vector<int> temp;
            for (int j = 0; j < V; j++)
            {
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution ob;
        cout << ob.numProvinces(adj, V) << endl;
    }
    return 0;
}
// } Driver Code Ends