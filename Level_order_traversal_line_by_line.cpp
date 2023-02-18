#include <iostream>
#include <vector>
#include "Binary_Tree_Node.h"
using namespace std;
void assign(struct Node *node, vector<struct Node *> &next_level)
{
    if (node->left)
    {
        next_level.push_back(node->left);
    }
    if (node->right)
    {
        next_level.push_back(node->right);
    }
}
vector<vector<int>> levelOrder(Node *node)
{
    vector<struct Node *> prev_level;
    vector<struct Node *> next_level;
    vector<int> data;
    vector<vector<int>> ans;
    prev_level.push_back(node);
    while (prev_level.size() != 0)
    {

        for (int i = 0; i < prev_level.size(); i += 1)
        {
            assign(prev_level[i], next_level);
            data.push_back(prev_level[i]->data);
        }
        prev_level = next_level;
        next_level.clear();
        ans.push_back(data);
        data.clear();
    }
    return ans;
}
