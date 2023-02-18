#include <iostream>
#include <vector>
using namespace std;
class Solution
{
    vector<int> hash_table;

public:
    // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int generate_key(int k)
    {
        return k % hash_table.size();
    }
    void insert_element(int ele)
    {
        int key = generate_key(ele);
        hash_table[key] += 1;
    }
    bool check_majoirity(int ele, int size)
    {
        int key = generate_key(ele);
        if (hash_table[key] > size / 2)
            return true;
        return false;
    }
    int majorityElement(int a[], int size)
    {
        int arr_max = INT_MIN;
        for (int i = 0; i < size; i += 1)
        {
            if (arr_max < a[i])
            {
                arr_max = a[i];
            }
        }
        vector<int> temp(arr_max, 0);
        hash_table = temp;
        for (int i = 0; i < size; i += 1)
        {
            insert_element(a[i]);
            if (check_majoirity(a[i], size))
            {
                return a[i];
            }
        }
        return -1;
    }
};
