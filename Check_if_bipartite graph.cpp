#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;
class Custom_Node
{
public:
    string color;
    int parent;
    int value;
    Custom_Node(string c, int p, int v)
    {
        color = c;
        parent = p;
        value = v;
    }
};

class Solution
{
public:
    vector<Custom_Node> make_custom(int V)
    {
        vector<Custom_Node> CD_array;
        for (int i = 0; i < V; i += 1)
        {
            Custom_Node cn("None", -1, i);
            CD_array.push_back(cn);
        }
        return CD_array;
    }
    string opp_color(string color)
    {
        if (color == "green")
        {
            return "red";
        }
        return "green";
    }
    bool check_same_color(string color1, string color2)
    {
        if (color1 == color2)
        {
            return true;
        }
        return false;
    }
    bool isBipartite(int V, vector<int> adj[])
    {
        vector<Custom_Node> CD = make_custom(V);
        vector<bool> visited(V, false);
        stack<int> s;
        for (int i = 0; i < V; i += 1)
        {
            if (visited[i] == true)
                continue;
            s.push(i);
            CD[i].color = "red";
            while (!s.empty())
            {
                int vertex = s.top();
                s.pop();
                visited[vertex] = true;
                for (int i = 0; i < adj[vertex].size(); i += 1)
                {
                    if (check_same_color(CD[adj[vertex][i]].color, CD[vertex].color))
                    {
                        return false;
                    }
                    if (CD[adj[vertex][i]].color == "None")
                    {
                        CD[adj[vertex][i]].color = opp_color(CD[vertex].color);
                    }
                    if (visited[adj[vertex][i]] == false)
                    {
                        CD[adj[vertex][i]].parent = vertex;
                        s.push(adj[vertex][i]);
                    }
                }
            }
        }
        return true;
    }
};