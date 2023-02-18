#include <vector>
#include <iostream>
using namespace std;
class Solution
{
    vector<bool> visited;
    vector<int> zero_deg;
    int count = 0;

public:
    void construct_visited(int N)
    {
        vector<bool> temp(N, false);
        visited = temp;
    }
    bool check_two_odd_degree(vector<vector<int>> graph, int N)
    {
        vector<int> temp(N);
        int No_of_odd_vertices = 0;
        int count = 0;
        for (int i = 0; i < N; i += 1)
        {
            count = 0;
            for (int j = 0; j < N; j += 1)
            {
                if (graph[i][j] == 1)
                {
                    count += 1;
                }
            }
            if (count == 0)
            {
                temp[i] = 1;
            }
            if (count % 2 != 0)
            {
                No_of_odd_vertices += 1;
            }
        }
        zero_deg = temp;
        if (No_of_odd_vertices == 0 || No_of_odd_vertices == 2)
        {
            return true;
        }
        return false;
    }
    bool is_connected(vector<vector<int>> graph, int N, int index)
    {
        if (visited[index] == true)
        {
            count -= 1;
            return false;
        }
        if (count == N)
        {
            return true;
        }
        if (count != N && zero_deg[index] == 1)
        {
            return true;
        }
        for (int i = 0; i < graph[index].size(); i += 1)
        {
            if (graph[index][i] == 0)
            {
                continue;
            }
            count += 1;
            return false || is_connected(graph, N, i);
        }
    }
    int eulerPath(int N, vector<vector<int>> graph)
    {
        if (check_two_odd_degree(graph, N) == false)
        {
            return 0;
        }
        construct_visited(N);
        if (is_connected(graph, N, 0) == true)
        {
            return 1;
        }
        return 0;
    }
};