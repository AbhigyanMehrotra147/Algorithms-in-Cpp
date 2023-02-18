#include <bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    bool declare_if_out_bounds(int i, int j, int n)
    {
        if(i > 2 || j > n-1) return true;
        if(i < 0 || j < 0) return true;
        return false; 
    }   
    void find_totals(int wealth, int i, int j, int n, vector<int> &totals, vector<vector<int>> grid, vector<vector<bool>> visited)
    {
        if(visited[i][j])
        {
            return;
        }

        if(i == 2 && j == n-1)
        {
            totals.push_back(wealth + grid[i][j]);
            return;
        }

        visited[i][j] = true;
        if(!declare_if_out_bounds(i+1,j,n)) 
        {
            find_totals(wealth + grid[i][j],i+1,j,n,totals,grid,visited);
        }
        if(!declare_if_out_bounds(i,j+1,n)) 
        {
            find_totals(wealth + grid[i][j],i,j+1,n,totals,grid,visited);
        }
        if(!declare_if_out_bounds(i-1,j,n)) 
        {
            find_totals(wealth + grid[i][j],i-1,j,n,totals,grid,visited);
        }
    }
    int get_max(int Three, int N, vector<vector<int>> Grid)
    {
        vector<bool> temp_visited(N,false);
        vector<vector<bool>> visited(3,temp_visited);
        vector<int> totals;
        find_totals(0,0,0,N,totals,Grid,visited);
        sort(totals.begin(), totals.end());
        return totals[totals.size()-1]%998244353;
    }
};
int getMax(int Three, int N, vector<vector<int>> Grid)
{
    Solution s;
    return s.get_max(Three,N,Grid);
}

int main()
{
    vector<int>temp1{1,-1,1};
    vector<int>temp2{-1,1,-1};
    vector<int>temp3{1,-1,1};
    vector<vector<int>>grid;
    grid.push_back(temp1);
    grid.push_back(temp2);
    grid.push_back(temp3);
    cout << getMax(3,3,grid);
    return 0;
}