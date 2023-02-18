//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node *left;
    Node *right;
};

// Utility function to create a new Tree Node
Node *newNode(int val)
{
    Node *temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

// Function to Build Tree
Node *buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size())
    {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N")
        {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

// } Driver Code Ends
// User function Template for C++

/* Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};*/
#include <iostream>
#include <vector>
#include "Binary_Tree_Node.h"
#include <stack>
using namespace std;
#include <stack>

class Solution
{

    void act_through_control(stack<Node *> &Control, stack<Node *> &right, stack<Node *> &parent, vector<int> &Traversal)
    {
        struct Node *temp = Control.top();
        Control.pop();
        if (!temp)
            return;
        if (!temp->left && !temp->right)
        {
            Traversal.push_back(temp->data);
            return;
        }
        parent.push(temp);
        Control.push(parent.top()->left);
        right.push(parent.top()->right);
    }
    void act_through_right(stack<Node *> &Control, stack<Node *> &right, stack<Node *> &parent, vector<int> &Traversal)
    {
        struct Node *temp = right.top();
        right.pop();
        if (!temp)
        {
            Traversal.push_back(parent.top()->data);
            parent.pop();
            return;
        }
        if (!temp->left && !temp->right)
        {
            Traversal.push_back(temp->data);
            Traversal.push_back(parent.top()->data);
            parent.pop();
            return;
        }
        parent.push(temp);
        Control.push(parent.top()->left);
        right.push(parent.top()->right);
    }

public:
    vector<int> postOrder(Node *node)
    {
        stack<Node *> parent;
        stack<Node *> right;
        stack<Node *> Control;
        Control.push(node);
        vector<int> Traversal;
        while (!Control.empty() || !right.empty())
        {
            if (!Control.empty())
            {
                act_through_control(Control, right, parent, Traversal);
                continue;
            }
            if (!right.empty())
            {
                act_through_right(Control, right, parent, Traversal);
                continue;
            }
        }
        if (!parent.empty())
        {
            Traversal.push_back(parent.top()->data);
            parent.pop();
        }
        return Traversal;
    }
};

//{ Driver Code Starts.

/* Driver program to test size function*/

int main()
{

    int t;
    scanf("%d ", &t);
    while (t--)
    {
        string s, ch;
        getline(cin, s);

        Node *root = buildTree(s);

        vector<int> ans;
        Solution ob;
        ans = ob.postOrder(root);

        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";

        cout << endl;
    }
    return 0;
}

// } Driver Code Ends