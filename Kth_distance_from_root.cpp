#include <iostream>
#include <vector>
using namespace std;
void insert(struct Node *node, vector<struct Node *> &children)
{
    if (!node)
    {
        return;
    }
    children.push_back(node);
}
vector<int> Kdistance(struct Node *root, int k)
{
    vector<struct Node *> Nodes;
    vector<struct Node *> children;
    vector<int> ans;
    int level = 0;
    if (!root)
    {
        return ans;
    }
    Nodes.push_back(root);
    while (Nodes.size() != 0 && level != k)
    {
        for (int i = 0; i < Nodes.size(); i += 1)
        {
            struct Node *temp1 = Nodes[i]->left;
            struct Node *temp2 = Nodes[i]->right;
            insert(temp1, children);
            insert(temp2, children);
        }
        Nodes = children;
        children.clear();

        level += 1;
    }
    if (!Nodes.size())
    {
        return ans;
    }
    for (int i = 0; i < Nodes.size(); i += 1)
    {
        ans.push_back(Nodes[i]->data);
    }
    return ans;
}