#include <vector>
#include <iostream>
using namespace std;
class Solution
{
public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs;
    vector<bool> flag;
    void assign(int V)
    {
        for (int i = 0; i < V; i += 1)
        {
            flag.push_back(false);
        }
    }
    vector<int> add_first_child(vector<int> vertices, vector<int> adj[])
    {
        vector<int> next_level;
        int count1 = 0;
        int count2 = 0;
        for (auto i : vertices)
        {
            for (int j = 0; j < adj[i].size(); j += 1)
            {
                count1 += 1;
                next_level.push_back(adj[i][j]);
                if (flag[adj[i][j]] == true)
                {
                    count2 += 1;
                    continue;
                }
                bfs.push_back(adj[i][j]);
                flag[adj[i][j]] = true;
            }
        }
        if (count1 == count2)
            return bfs;
        if (next_level.empty())
        {
            return bfs;
        }
        return add_first_child(next_level, adj);
    }
    vector<int> bfsOfGraph(int V, vector<int> adj[])
    {

        vector<int> next_level;
        assign(V);
        bfs.push_back(0);
        flag[0] = true;
        for (int i = 0; i < adj[0].size(); i += 1)
        {
            bfs.push_back(adj[0][i]);
            next_level.push_back(adj[0][i]);
            flag[adj[0][i]] = true;
        }
        if (next_level.empty())
        {
            vector<int> ans;
            ans.push_back(0);
            bfs.clear();
            flag.clear();
            return ans;
        }
        vector<int> ans = add_first_child(next_level, adj);
        flag.clear();
        bfs.clear();
        return ans;
    }
};