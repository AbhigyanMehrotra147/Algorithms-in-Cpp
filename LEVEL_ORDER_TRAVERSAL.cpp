#include <iostream>
#include <vector>
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    Node(int x)
    {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};
class Solution
{
    vector<int> lvl_ord;

public:
    // Function to return the level order traversal of a tree.
    int max(int a, int b)
    {
        if (a > b)
        {
            return a;
        }
        else
        {
            return b;
        }
    }
    int H(struct Node *node, int hight)
    {
        if (node == NULL)
        {
            hight = hight - 1;
            return hight;
        }
        return max(H(node->left, hight + 1), H(node->right, hight + 1));
    }
    void get_current_level_nodes(Node *root, int hight)
    {
        if (root == NULL)
        {
            return;
        }
        if (hight == 1)
        {
            lvl_ord.push_back(root->data);
            return;
        }
        get_current_level_nodes(root->left, hight - 1);
        get_current_level_nodes(root->right, hight - 1);
    }
    vector<int> levelOrder(Node *node)
    {
        int higt = H(node, 1);
        for (int i = 1; i <= higt; i += 1)
        {
            get_current_level_nodes(node, i);
        }
        vector<int> ans(lvl_ord);
        lvl_ord.clear();
        return ans;
    }
};