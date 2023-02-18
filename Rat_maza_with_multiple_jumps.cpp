//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

struct Path
{
    int step;
    vector<vector<int>> path;
    Path(int n)
    {
        this->step = 0;
        vector<int> path_row(n,0);
        vector<vector<int>> temp(n,path_row);
        this->path = temp;
    }
};
class Solution 
{
    bool sol = false;
    bool declare_out_of_bounds(int i, int j, int m, int n)
    {
        if(i > m-1 || j > n-1) return true;
        if(i < 0 || j < 0) return true;
        return false;
    }
    void find_distances(vector<vector<int>> &Path, vector<pair<int,int>> path, vector<vector<int>> matrix, int i, int j, int m, int n)
    {
        // cout << i << "," << j << endl;
        if(declare_out_of_bounds(i,j,m,n)) return;
        if(matrix[i][j] == 0 && (i != m-1 && j != n-1)) return;
        pair<int,int> temp(i,j);
        path.push_back(temp);
        if(i == m-1 && j == n-1)
        {
            sol = true;
            for(int k = 0;k<path.size();k+=1)
            {
                Path[path[k].first][path[k].second] = 1;
            }
            Path[i][j] = 1;
            return;
        }
        for(int k = 1;k<=matrix[i][j];k+=1)
        {
            find_distances(Path,path,matrix,i,j+k,m,n);
            if(sol) return;
            find_distances(Path,path,matrix,i+k,j,m,n);
            if(sol) return;
            
        }
    }
public:
    
	vector<vector<int>> ShortestDistance(vector<vector<int>>&matrix)
	{
	    int m = matrix.size();
	    int n = matrix[0].size();
	    Path p(n);
        vector<int> path_row(m,0);
        vector<vector<int>> Path(n,path_row);
        vector<pair<int,int>> path;
        find_distances(Path,path,matrix,0,0,m,n);
        if(Path[m-1][n-1]==0)
        {   
            vector<int> temp(1,-1);
            vector<vector<int>> ans(1,temp);
            return ans;
        }
	   return Path;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.ShortestDistance(matrix);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends