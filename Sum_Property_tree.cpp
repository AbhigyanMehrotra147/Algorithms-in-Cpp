#include <iostream>
#include "Binary_Tree_Node.h"
using namespace std;
class Solution
{
public:
    // Function to check whether all nodes of a tree have the value
    // equal to the sum of their child nodes.
    int add_Node(Node *root)
    {
        try
        {
            if (root != nullptr)
            {
                return root->data;
            }
            else
            {
                throw 505;
            }
        }
        catch (int y)
        {
            return 0;
        }
    }
    bool isSum(Node *root)
    {
        if (!root)
            return true;
        if (!root->left && !root->right)
            return true;
        if (add_Node(root->left) + add_Node(root->right) == root->data)
        {
            return true && isSum(root->left) && isSum(root->right);
        }
        return false;
    }
    int isSumProperty(Node *root)
    {
        if (isSum(root))
            return 1;
        return 0;
    }
};