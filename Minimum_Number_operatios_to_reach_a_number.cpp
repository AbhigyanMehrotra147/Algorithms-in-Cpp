//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int minOperation(int n)
    {
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;
        int arr[n];
        arr[n - 1] = 1;
        for (int i = n - 2; i > 0; i -= 1)
        {
            if (i * 2 > n)
            {
                arr[i] = arr[i + 1] + 1;
            }
            else if (i * 2 < n)
            {
                arr[i] = min(arr[i * 2], arr[i + 1]) + 1;
            }
            else
            {
                arr[i] = 1;
            }
        }
        arr[0] = arr[1] + 1;
        return arr[0];
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.minOperation(n) << endl;
    }
}
// } Driver Code Ends