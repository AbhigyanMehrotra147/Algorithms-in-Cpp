#include <iostream>
#include <vector>
#include <utility>
#include <stack>
using namespace std;
class Largest_area
{
public:
    // Function to find unit area of the largest region of 1s.
    bool check_if_dimension(int x, int y, int m, int n)
    {
        if (x < m && x > -1 && y < n && y > -1)
        {
            return true;
        }
        return false;
    }
    int find_area(vector<vector<int>> grid, vector<vector<bool>> &visited, int index_x, int index_y)
    {
        int area = 0;
        pair<int, int> p(index_x, index_y);
        visited[index_x][index_y] = true;
        stack<pair<int, int>> s;
        s.push(p);
        pair<int, int> vertex;
        int x;
        int y;
        while (!s.empty())
        {
            vertex = s.top();
            x = vertex.first;
            y = vertex.second;
            s.pop();
            // cout << x << " " << y << endl;
            area += 1;
            for (int i = x - 1; i <= x + 1; i += 1)
            {
                for (int j = y - 1; j <= y + 1; j += 1)
                {
                    if (!check_if_dimension(i, j, grid.size(), grid[0].size()))
                        continue;
                    if (grid[i][j] == 0)
                        continue;
                    if (visited[i][j])
                        continue;
                    visited[i][j] = true;
                    pair<int, int> temp(i, j);
                    s.push(temp);
                }
            }
        }
        return area;
    }
    int findMaxArea(vector<vector<int>> &grid)
    {
        if (grid.size() == 0 || grid[0].size() == 0)
            return 0;
        vector<bool> temp(grid[0].size(), false);
        vector<vector<bool>> visited(grid.size(), temp);
        int max_area = INT_MIN;
        int curr_area;
        for (int i = 0; i < grid.size(); i += 1)
        {
            for (int j = 0; j < grid[0].size(); j += 1)
            {
                if (visited[i][j])
                    continue;
                if (grid[i][j] == 0)
                    continue;
                curr_area = find_area(grid, visited, i, j);
                if (max_area < curr_area)
                {
                    max_area = curr_area;
                }
            }
        }
        return max_area;
    }
};