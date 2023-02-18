#include <vector>
#include <iosstream>
using namespace std;
class Solution
{
public:
    /*You are required to complete this method*/
    bool insert(vector<struct Node *> &children, Node *node)
    {
        if (!node)
        {
            return false;
        }
        children.push_back(node);
        return true;
    }
    int minDepth(Node *root)
    {
        vector<struct Node *> Nodes;
        vector<struct Node *> children;
        struct Node *temp1;
        struct Node *temp2;
        if (!root)
        {
            return 0;
        }
        int level = 1;
        Nodes.push_back(root);
        while (Nodes.size() != 0)
        {
            for (int i = 0; i < Nodes.size(); i += 1)
            {
                temp1 = Nodes[i]->left;
                temp2 = (*Nodes[i]).right;
                bool flag1 = insert(children, temp1);
                bool flag2 = insert(children, temp2);
                if (!flag1 && !flag2)
                {
                    return level;
                }
            }
            level += 1;
            Nodes = children;
            children.clear();
        }
        return level;
    }
};