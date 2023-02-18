#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
class Solution
{
public:
    // Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        if (n == 1)
            return arr[0];
        int max_from_index[n];
        max_from_index[n - 1] = arr[n - 1];
        if (arr[n - 2] > max_from_index[n - 1])
        {
            max_from_index[n - 2] = arr[n - 2];
        }
        else if (arr[n - 2] <= max_from_index[n - 1])
        {
            max_from_index[n - 2] = max_from_index[n - 1];
        }
        for (int i = n - 3; i > -1; i -= 1)
        {
            if (arr[i] + max_from_index[i + 2] > max_from_index[i + 1])
            {
                max_from_index[i] = arr[i] + max_from_index[i + 2];
                continue;
            }
            max_from_index[i] = max_from_index[i + 1];
        }
        return max_from_index[0];
    }
};

//{ Driver Code Starts.
int main()
{
    // taking total testcases
    int t;
    cin >> t;
    while (t--)
    {
        // taking number of houses
        int n;
        cin >> n;
        int a[n];

        // inserting money of each house in the array
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        Solution ob;
        // calling function FindMaxSum()
        cout << ob.FindMaxSum(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends