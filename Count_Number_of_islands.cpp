#include <iostream>
#include <stack>
#include <utility>
using namespace std;
class Solution
{
public:
    bool check_entry(int x, int y, int m, int n)
    {
        try
        {
            if (x < m && x > -1 && y < n && y > -1)
            {
                return true;
            }
            else
            {
                throw(false);
            }
        }
        catch (bool val)
        {
            return val;
        }
    }
    void conduct_dfs(vector<vector<char>> grid, vector<vector<bool>> &visited, int a, int b)
    {

        stack<pair<int, int>> s;
        pair<int, int> p(a, b);
        s.push(p);
        while (!s.empty())
        {
            pair<int, int> vertex = s.top();
            s.pop();
            if (visited[vertex.first][vertex.second])
                continue;
            visited[vertex.first][vertex.second] = true;
            int x = vertex.first;
            int y = vertex.second;
            for (int i = x - 1; i <= x + 1; i += 1)
            {
                for (int j = y - 1; j <= y + 1; j += 1)
                {
                    if (!check_entry(i, j, grid.size(), grid[0].size()))
                        continue;
                    if (visited[i][j])
                        continue;
                    if (grid[i][j] == '0')
                    {
                        visited[i][j] = true;
                        continue;
                    }
                    pair<int, int> p(i, j);
                    s.push(p);
                }
            }
        }
    }
    int numIslands(vector<vector<char>> &grid)
    {
        if (grid.size() == 1 && grid[0].size() == 1)
            return 0;
        int No_of_islands = 0;
        vector<bool> temp(grid[0].size(), false);
        vector<vector<bool>> visited(grid.size(), temp);
        for (int i = 0; i < grid.size(); i += 1)
        {
            for (int j = 0; j < grid[0].size(); j += 1)
            {
                if (visited[i][j])
                    continue;
                if (grid[i][j] == '0')
                    continue;
                No_of_islands += 1;
                conduct_dfs(grid, visited, i, j);
            }
        }
        return No_of_islands;
    }
};