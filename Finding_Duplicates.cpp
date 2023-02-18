// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
  public:
    vector<int> duplicates(int arr[], int n) 
    {
        vector<int> repeating;
        int singled[n] = {-9999}
        int hashed[n] = {-9999};
        int key;
        for(int i = 0;i<n;i+=1)
        {   
            key = arr[i]%n; 
            if(singled[key] != -9999)
            {
                hashed[key] = arr[i];
            }
            else
            {
                singled[key] = arr[i];
            }
        }
        for(int i = 0;i<n;i+=1)
        {
            if(hashed[i] == -9999) continue;
            repeating.push_back(hashed[i]);
        }
        if(!repeating.size()) repeating.push_back(-1);
        return repeating;
    }
};


// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution obj;
        vector<int> ans = obj.duplicates(a, n);
        for (int i : ans) cout << i << ' ';
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends