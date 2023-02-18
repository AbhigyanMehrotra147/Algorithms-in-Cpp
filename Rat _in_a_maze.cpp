//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

"""
Figures out all possible paths to n-1,n-1 cell number. uses backtracking(some form of recurstion)
"""
class Solution
{
    public:
    
    bool declare_if_out_bounds(int i, int j, int n)
    {
        if(i > n-1 || j > n-1) return true;
        if(i < 0 || j < 0) return true;
        return false;
    }
    void find_paths(vector<string> &paths, vector<vector<int>> m, vector<vector<bool>> visited, string path, int i, int j, int n)
    {
        if(visited[i][j])
        {
            return;
        }
        if(m[i][j] == 0)
        {
            return;
        }
        if(i == n-1 && j == n-1)
        {
            if(m[i][j] == 0) return;
            else
            {
                paths.push_back(path);
                return;
            }
        }
        visited[i][j] = true;
        if(!declare_if_out_bounds(i+1,j,n)) 
        {
            find_paths(paths,m,visited,path+"D",i+1,j,n);
        }
        if(!declare_if_out_bounds(i,j+1,n)) 
        {
            find_paths(paths,m,visited,path+"R",i,j+1,n);
        }
        if(!declare_if_out_bounds(i-1,j,n)) 
        {
            find_paths(paths,m,visited,path+"U",i-1,j,n);
        }
        if(!declare_if_out_bounds(i,j-1,n)) 
        {
            find_paths(paths,m,visited,path+"L",i,j-1,n);
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n)
    {
        vector<bool> visited_row(n,false);
        vector<vector<bool>> visited(n,visited_row);
        vector<string> paths;
        string path = "";
        find_paths(paths,m,visited,path,0,0,n);
        return paths;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends