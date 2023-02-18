#include <iostream>
using namespace std;
struct Node
{
    struct Node *next;
    int data;
    Node(int x, Node *temp = nullptr)
    {
        data = x;
        next = temp;
    }
};
class Hash
{
public:
    int size;
    Node **arr;
    Hash(int sizes)
    {
        arr = new Node *[size];
        size = sizes;
        for (int i = 0; i < size; i += 1)
        {
            arr[i] = nullptr;
        }
    }
    int hash_func(int val)
    {
        return val % size;
    }
    void allot(int val)
    {
        int key = hash_func(val);
        if (arr[key] == nullptr)
        {
            arr[key] = new Node(val);
        }
        else
        {
            struct Node *temp = arr[key];
            while (temp)
            {
                temp = temp->next;
            }
            temp->next = new Node(val);
        }
    }
    bool count_search(int key, int val, int k)
    {
        struct Node *temp = arr[key];
        int count = 0;
        while (temp)
        {
            if (temp->data == val)
            {
                count += 1;
            }
            temp = temp->next;
        }
        if (count == k)
        {
            return true;
        }
        return false;
    }
};
class Solution
{
public:
    int firstElementKTime(int a[], int n, int k)
    {
        Hash h(n);
        for (int i = 0; i < n; i += 1)
        {
            h.allot(a[i]);
        }
        for (int i = 0; i < n; i += 1)
        {
            bool indicate = h.count_search(h.hash_func(a[i]), a[i], k);
            if (indicate == true)
                return k;
        }
        return -1;
    }
};
int main()
{
    Solution S;
    int arr[10] = {1, 2, 2, 4, 3, 5, 12, 12, 6, 7};
    int k = 2;
    int n = 10;
    cout << S.firstElementKTime(arr, n, k);
    return -1;
}