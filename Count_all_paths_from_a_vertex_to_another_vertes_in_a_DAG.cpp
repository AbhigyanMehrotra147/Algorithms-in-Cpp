#include <vector>
#include <iostream>
using namespace std;
class Solution
{
public:
    vector<vector<int>> adj;
    int paths = 0;
    void print_all_edges()
    {
        for (int i = 0; i < adj.size(); i += 1)
        {
            cout << i << " ";
            for (int j = 0; j < adj[i].size(); j += 1)
            {
                cout << adj[i][j] << " ";
            }
            cout << endl;
        }
    }
    void create_vector_adj(vector<vector<int>> edges, int n)
    {
        vector<vector<int>> temp(n);
        for (int i = 0; i < edges.size(); i += 1)
        {
            temp[edges[i][0]].push_back(edges[i][1]);
        }
        adj = temp;
    }
    void count(int index, int d)
    {
        if (index == d)
        {
            paths += 1;
            return;
        }
        // cout << adj[index].size();
        for (int i = 0; i < adj[index].size(); i += 1)
        {
            // cout << adj[index][i] << " ";
            count(adj[index][i], d);
        }
    }
    int possible_paths(vector<vector<int>> edges, int n, int s, int d)
    {
        create_vector_adj(edges, n);
        // print_all_edges();
        count(s, d);
        int ans = paths;
        paths = 0;
        return ans;
    }
};