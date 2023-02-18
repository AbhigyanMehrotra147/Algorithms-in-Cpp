#include <iostream>
#include <vector>
using namespace std;
class Pair
{
private:
    int row;
    int coloumns;
    friend class Solution;
    Pair() {}
    Pair(int x, int y)
    {
        row = x;
        coloumns = y;
    }
    void make_pair(int x, int y)
    {
        row = x;
        coloumns = y;
    }
};
class Solution
{
    int run;
    vector<vector<bool>> flag;
    vector<vector<int>> Nearest;
    int count = 0;

public:
    Solution() { run = 0; }
    // Function to find distance of nearest 1 in the grid for each cell.
    void assign_nearest(int r, int c)
    {
        Nearest.clear();
        vector<int> temp(c, 2147483647);
        /*for(int i = 0;i<r;i+=1)
        {
            Nearest.push_back(temp);
        }*/
        vector<vector<int>> temp2(r, temp);
        Nearest = temp2;
    }
    void assign_flag(int r, int c)
    {
        vector<bool> temp(c, false);
        flag.clear();
        vector<vector<bool>> temp2(r, temp);
        flag = temp2;
    }
    void assign_pos(vector<Pair> &positions, int row, int coloumns, vector<vector<int>> grid)
    {
        try
        {
            if (row > -1 && row < grid.size() && coloumns > -1 && coloumns < grid[0].size())
            {
                Pair P(row, coloumns);
                positions.push_back(P);
            }
            else
            {
                throw 505;
            }
        }
        catch (...)
        {
            return;
        }
    }
    void check_nearest_1(vector<Pair> positions, vector<vector<int>> grid, int r, int c, int count)
    {
        vector<Pair> Pos;
        for (int i = 0; i < positions.size(); i += 1)
        {
            if (flag[positions[i].row][positions[i].coloumns] == true)
            {
                continue;
            }

            if (grid[positions[i].row][positions[i].coloumns] == 1)
            {
                Nearest[r][c] = count;
                return;
            }
            flag[positions[i].row][positions[i].coloumns] = true;
            assign_pos(Pos, positions[i].row + 1, positions[i].coloumns, grid);
            assign_pos(Pos, positions[i].row - 1, positions[i].coloumns, grid);
            assign_pos(Pos, positions[i].row, positions[i].coloumns + 1, grid);
            assign_pos(Pos, positions[i].row, positions[i].coloumns - 1, grid);
        }
        return check_nearest_1(Pos, grid, r, c, count + 1);
    }
    bool check_grid(vector<vector<int>> grid)
    {
        for (int i = 0; i < grid.size(); i += 1)
        {
            for (int j = 0; j < grid[0].size(); j += 1)
            {
                if (grid[i][j] != 0)
                {
                    return true;
                }
            }
        }
        return false;
    }
    vector<vector<int>> nearest(vector<vector<int>> grid)
    {
        run += 1;
        assign_nearest(grid.size(), grid[0].size());
        if (!check_grid(grid))
        {
            return Nearest;
        }

        vector<Pair> Pos;
        for (int i = 0; i < grid.size(); i += 1)
        {
            for (int j = 0; j < grid[0].size(); j += 1)
            {
                assign_flag(grid.size(), grid[0].size());
                Pos.clear();
                Pair P(i, j);
                Pos.push_back(P);
                check_nearest_1(Pos, grid, i, j, 0);
            }
        }
        return Nearest;
    }
};
int main()
{
    vector<vector<int>> grid;
    vector<int> temp(4, 1);
    vector<int> temp2(4, 0);
    grid.push_back(temp);
    grid.pop_back(temp2);
    grid.push_back(temp);
    grid.push_back(temp2);
    Solution S;
    vector<vector<int>> Nearest;
    Nearest = S.nearest(grid);
    for (int i = 0; i < grid.size(); i += 1)
    {
        for (int j = 0; j, grid.size(); j += 1)
        {
            cout << Nearest[i][j] << " ";
        }
        cout << endl;
    }
}