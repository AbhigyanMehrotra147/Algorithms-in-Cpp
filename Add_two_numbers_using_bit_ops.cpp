//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

/*
    CAN ONLY ADD POSITIVE NUMBERS TOGETHOR      
*/

class Solution
{
    public:
    int sum(int a , int b)
    {
        int sum = 0;
        int carry = 0;
        int added_num = 0;
        int numb_bits = 0;
        int last_a;
        int last_b;
        while(a || b)
        {
            
            last_a = a%2;
            last_b = b%2;
            sum = (last_a ^ last_b) ^ carry;
            carry = (last_a | last_b) ^ (last_a | carry) ^ (last_b | carry);
            added_num = (sum << numb_bits) | added_num;
            numb_bits += 1;
            a = a >> 1;
            b = b >> 1;
        }
        added_num = (carry << numb_bits) | added_num;
        

        return added_num;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a,b;
        cin >> a>>b;
        
        Solution ob;
        cout<< ob.sum(a,b) <<"\n";
        
    }
    return 0;
}

// } Driver Code Ends