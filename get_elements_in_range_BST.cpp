#include <iostream>
#include <vector>
#include "Binary_Tree_Node.h"
using namespace std;
class Elements_in_range
{
public:
    bool check_range(Node *root, int low, int high)
    {
        if (root->data <= high && root->data >= low)
        {
            return true;
        }
        return false;
    }
    void in_range(Node *root, int low, int high, vector<int> &inside_range)
    {
        if (!root)
            return;
        if (check_range(root, low, high))
        {
            in_range(root->left, low, high, inside_range);
            inside_range.push_back(root->data);
            in_range(root->right, low, high, inside_range);
            return;
        }
        if (root->data > high)
        {
            in_range(root->left, low, high, inside_range);
            return;
        }
        if (root->data < low)
        {
            in_range(root->right, low, high, inside_range);
        }
    }
    vector<int> printNearNodes(Node *root, int low, int high)
    {
        vector<int> inside_range;
        in_range(root, low, high, inside_range);
        return inside_range;
    }
};