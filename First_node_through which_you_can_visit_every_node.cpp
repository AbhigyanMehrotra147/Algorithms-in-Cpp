#include <vector>
using namespace std;
class Solution
{
    vector<bool> visited;
    int count;

public:
    // Function to find a Mother Vertex in the Graph.
    void fill_visited(int V)
    {
        vector<bool> temp(V, false);
        visited = temp;
    }
    void single_node_traverse(int V, vector<int> adj[], int index)
    {
        if (count == V)
        {
            return;
        }
        if (visited[index] == true)
        {
            return;
        }
        count += 1;
        visited[index] = true;
        for (int i = 0; i < adj[index].size(); i += 1)
        {
            single_node_traverse(V, adj, adj[index][i]);
        }
    }
    int findMotherVertex(int V, vector<int> adj[])
    {
        // vector<int> ans;
        for (int i = 0; i < V; i += 1)
        {
            count = 0;
            fill_visited(V);
            single_node_traverse(V, adj, i);
            if (count == V)
            {
                // ans.push_back(i);
                return i;
            }
        }
        /*if(ans.size() == 0)
        {
            return -1;
        }
        sort(ans.begin(),ans.end());
       // cout << ans.size() << endl;*/
        return -1;
    }
};