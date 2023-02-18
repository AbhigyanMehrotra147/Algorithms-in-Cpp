#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
class Check_if_Binary_tree_is_heap
{
public:
    int max(int a, int b)
    {
        if (a > b)
            return a;
        return b;
    }
    int height(struct Node *root, int h)
    {
        if (!root)
        {
            return h - 1;
        }
        return max(height(root->left, h + 1), height(root->right, h + 1));
    }
    bool completeness(struct Node *root, int level, int high)
    {
        if (!root)
        {
            // cout << level << endl;
            if (level == high + 1 || level == high)
            {
                return true;
            }
            return false;
        }
        return completeness(root->left, level + 1, high) && completeness(root->right, level + 1, high);
    }
    bool compare_child(struct Node *root)
    {
        if (root->left && root->right)
        {
            return root->left->data <= root->data && root->right->data <= root->data;
        }
        return true;
    }
    bool lesser_children(struct Node *root)
    {
        if (!root)
            return true;
        return compare_child(root) && lesser_children(root->left) && lesser_children(root->right);
    }
    bool isHeap(struct Node *tree)
    {
        bool flag0 = height(tree->left, 0) >= height(tree->right, 0);
        if (!flag0)
            return false;
        int high = height(tree, 0);
        // cout << high << endl;
        bool flag1 = completeness(tree, 0, high);
        // cout << flag1 << endl;
        if (!flag1)
            return false;
        bool flag2 = lesser_children(tree);
        return flag2;
    }
};