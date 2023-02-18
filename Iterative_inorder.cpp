#include <iostream>
#include <vector>
#include "Binary_Tree_Node.h"
#include <stack>
using namespace std;
class Iterative_Inorder
{
public:
    void insert_in_inorder(stack<Node *> &s1, vector<int> &inorder)
    {
        if (s1.empty())
            return;
        if (s1.top())
            inorder.push_back(s1.top()->data);
        s1.pop();
    }
    void insert_in_s1(stack<Node *> &s1, stack<Node *> &s2)
    {
        if (s2.empty())
            return;
        s1.push(s2.top());
        s2.pop();
    }
    vector<int> inOrder(Node *root)
    {
        stack<Node *> s1;
        stack<Node *> s2;
        vector<int> inorder;
        s1.push(root);
        // cout << s2.empty() << endl;
        while (!s1.empty() || !s2.empty())
        {
            if ((!s1.top()) || (!s1.top()->left && !s1.top()->right))
            {
                insert_in_inorder(s1, inorder);
                insert_in_inorder(s1, inorder);
                insert_in_s1(s1, s2);
                continue;
            }
            if (s1.top()->left || s1.top()->right)
            {
                s2.push(s1.top()->right);
                s1.push(s1.top()->left);
            }
        }
        return inorder;
    }
};
class Better_iterative_in_order
{
public:
    vector<int> inOrder(Node *root)
    {
        stack<Node *> s;
        s.push(root);
        vector<int> in_order;
        if (!root)
            return in_order;
        Node *temp = root->left;
        while (!s.empty() || temp)
        {
            if (temp)
            {
                s.push(temp);
                temp = temp->left;
            }
            else
            {
                temp = s.top();
                s.pop();
                in_order.push_back(temp->data);
                temp = temp->right;
            }
        }
        return in_order;
    }
};