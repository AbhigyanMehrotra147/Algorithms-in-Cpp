#include <iostream>
#include <vector>
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    Node(int x, struct Node *l, struct Node *r)
    {
        data = x;
        left = l;
        right = r;
    }
    Node(int x)
    {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};
class Solution
{
public:
    vector<int> PO;
    int ans = -999999;
    int zero = 0;
    void post_order(Node *root)
    {
        if (root == nullptr)
        {
            return;
        }

        post_order(root->right);
        PO.push_back(root->data);
        post_order(root->left);
    }
    void post_order(Node *root, int k)
    {
        if (root == nullptr)
        {
            return;
        }
        if (ans != -999999)
        {
            return;
        }
        post_order(root->right, k);
        zero += 1;
        if (zero == k)
        {
            ans = root->data;
        }
        post_order(root->left, k);
    }
    int kthLargest(Node *root, int K)
    {
        // post_order(root);
        // vector<int> ans (PO);
        // PO.clear();
        // return ans[K-1];
        post_order(root, K);
        int s = ans;
        ans = -999999;
        zero = 0;
        return s;
    }
};
int main()
{
    struct Node *r2 = new Node(2);
    struct Node *r3 = new Node(9);
    struct Node *r1 = new Node(4, r2, r3);
    Solution s1;
    cout << s1.kthLargest(r1, 2);
}