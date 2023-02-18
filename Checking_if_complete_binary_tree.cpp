//{ Driver Code Starts
// A program to check if a given binary tree is complete or not
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

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
    Node *root = new Node(stoi(ip[0]));

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

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

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
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

// } Driver Code Ends

#include <queue>
class Solution
{
public:
    int hight(Node *root, int h)
    {
        if (!root)
            return h;
        else
        {
            return max(hight(root->left, h + 1), hight(root->right, h + 1));
        }
    }
    void insert(vector<int> &arr, Node *node)
    {
        if (node)
            arr.push_back(node->data);
        else
        {
            arr.push_back(-9999);
        }
    }
    bool check_last_level(queue<Node *> q)
    {
        vector<int> arr;
        while (!q.empty())
        {
            Node *node = q.front();
            if (!node)
                return false;
            q.pop();
            insert(arr, node->left);
            insert(arr, node->right);
        }
        bool left_side = true;
        for (int i = 0; i < arr.size() - 1; i += 1)
        {
            if (arr[i] == -9999 && arr[i + 1] != -9999)
                return false;
        }
        return true;
    }
    bool isCompleteBT(Node *root)
    {
        int h = hight(root, 0);
        if (h == 0 || h == 1)
            return true;
        queue<Node *> q;
        q.push(root);
        int curr_h = 1;
        while (curr_h < h - 1)
        {
            // cout << curr_h << endl;
            queue<Node *> temp_q;
            while (!q.empty())
            {
                Node *node = q.front();
                q.pop();
                if (!node)
                    return false;
                temp_q.push(node->left);
                temp_q.push(node->right);
            }
            q = temp_q;
            curr_h += 1;
        }
        return check_last_level(q);
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    scanf("%d ", &t);
    while (t--)
    {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);
        Solution ob;
        if (ob.isCompleteBT(root))
        {
            printf("Complete Binary Tree\n");
        }
        else
        {
            printf("Not Complete Binary Tree\n");
        }
    }
    return 0;
}

// } Driver Code Ends