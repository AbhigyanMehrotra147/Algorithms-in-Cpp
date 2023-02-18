//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    bool check_if_inside(int N, pair<int,int> d, pair<int,int> current)
    {
        if(current.first + d.first < N && current.first + d.first > -1 && current.second + d.second < N && current.second + d.second > -1)
        {
            return true;
        }
        return false;
    }
	int minStepToReachTarget(vector<int>&KnightPos, vector<int>&TargetPos, int N)
	{
	    pair<int,int> start_pos(KnightPos[0]-1, KnightPos[1]-1);
	    pair<int,int> dest_pos(TargetPos[0]-1, TargetPos[1]-1);
	    vector<bool> tempvec(N,false);
	    vector<vector<bool>> visited(N,tempvec);
	    vector<vector<bool>> next_visited(N,tempvec);
	    int dx[8] = {-1,-1,1,1,-2,-2,2,2};
	    int dy[8] = {-2,2,-2,2,-1,1,-1,1};
	    queue<pair<int,int>> q;
	    queue<pair<int,int>> temp;
	    q.push(start_pos);
	    int steps = 0;
	    while(!q.empty())
	    {
	        pair<int,int> curr = q.front();
	        q.pop();
	        if(curr.first == dest_pos.first && curr.second == dest_pos.second) return steps;
	        visited[curr.first][curr.second] = true;
	        for(register int i = 0;i<8;i+=1)
	        {
	            pair<int,int> d(dx[i],dy[i]);
	            if(!check_if_inside(N,d,curr)) continue;
	            pair<int,int> new_dest(curr.first+d.first, curr.second+d.second);
	            if(visited[new_dest.first][new_dest.second]) continue;
	            if(next_visited[new_dest.first][new_dest.second]) continue;
	            next_visited[new_dest.first][new_dest.second] = true;
	            temp.push(new_dest);
	        }
	        if(q.empty())
	        {
	            steps+=1;
	            q = temp;
                queue<pair<int,int>> temp2;
                temp = temp2;
                vector<vector<bool>> tempvec2(N,tempvec);
                next_visited = tempvec2;
	        }
	    }
	    return -1;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends