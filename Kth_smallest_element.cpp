#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class K_th_smallet
{
public:
    K_th_smallet() {}
    void swap(int arr[], int i, int j)
    {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    int partition(int arr[], int low, int pivot)
    {
        int divide = 0;
        for (int i = 0; i < pivot; i += 1)
        {
            if (arr[i] < arr[pivot])
            {
                swap(arr, i, divide);
                divide += 1;
            }
        }
        swap(arr, pivot, divide);
        return divide;
    }
    void quick_sort_till_key(int arr[], int low, int pivot, int key)
    {
        if (low == pivot)
            return;
        int divide = partition(arr, low, pivot);
        if (divide == key - 1)
            return;
        else if (divide < key - 1)
        {
            quick_sort_till_key(arr, divide + 1, pivot, key);
        }
        else
        {
            quick_sort_till_key(arr, low, divide - 1, key);
        }
    }
    void print_arr(int arr[], int n)
    {
        for (int i = 0; i < n; i += 1)
        {
            printf("%d\t", arr[i]);
        }
    }
};
//{ Driver Code Starts

class Solution
{
public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    void swap(int arr[], int i, int j)
    {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    int partition(int arr[], int low, int pivot)
    {
        int divide = 0;
        for (int i = 0; i < pivot; i += 1)
        {
            if (arr[i] < arr[pivot])
            {
                swap(arr, i, divide);
                divide += 1;
            }
        }
        swap(arr, pivot, divide);
        return divide;
    }
    void quick_sort_till_key(int arr[], int low, int pivot, int key)
    {
        if (low == pivot)
            return;
        int divide = partition(arr, low, pivot);
        if (divide == key - 1)
            return;
        else if (divide < key - 1)
        {
            quick_sort_till_key(arr, divide + 1, pivot, key);
        }
        else
        {
            quick_sort_till_key(arr, low, divide - 1, key);
        }
    }
    int kthSmallest(int arr[], int l, int r, int k)
    {
        quick_sort_till_key(arr, l, r, k);
        return arr[k - 1];
    }
};

//{ Driver Code Starts.

int main()
{
    int test_case;
    cin >> test_case;
    while (test_case--)
    {
        int number_of_elements;
        cin >> number_of_elements;
        int a[number_of_elements];

        for (int i = 0; i < number_of_elements; i++)
            cin >> a[i];

        int k;
        cin >> k;
        Solution ob;
        cout << ob.kthSmallest(a, 0, number_of_elements - 1, k) << endl;
    }
    return 0;
}
// } Driver Code Ends
// int main()
// {
//     K_th_smallet k;
//     int arr[] = {5, 7, 11, 4, 3, 8, 9, 6};
//     k.quick_sort_till_key(arr, 0, 7, 4);
//     k.print_arr(arr, 8);
// }