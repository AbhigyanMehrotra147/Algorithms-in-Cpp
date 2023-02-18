struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    struct Node *next;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
* /
    class Solution
{
    int lev = 0;
    int llev = 0;
    stack<Node *> s;

public:
    void find_node_level(Node *root, int level, int key)
    {
        if (llev == -1)
        {
            return;
        }
        if (root == NULL)
        {
            return;
        }
        if (root->data == key)
        {
            lev = level;
            llev = -1;
            return;
        }
        find_node_level(root->left, level + 1, key);
        find_node_level(root->right, level + 1, key);
    }
    void next_right(Node *root, int level, int key)
    {
        if (root == NULL)
        {
            return;
        }
        if (lev == -1)
        {
            return;
        }
        if (level > lev)
        {
            return;
        }
        if (level < lev)
        {
            next_right(root->right, level + 1, key);
            next_right(root->left, level + 1, key);
        }
        if (level == lev)
        {
            if (root->data != key)
            {
                s.push(root);
            }
            if (root->data == key)
            {
                lev = -1;
                return;
            }
        }
    }
    Node *nextRight(Node *root, int key)
    {
        find_node_level(root, 1, key);
        // cout << lev << endl;
        next_right(root, 1, key);
        if (s.empty())
        {
            Node *ans = new Node(-1);
            return ans;
        }
        Node *ans = s.top();
        while (!s.empty())
        {
            s.pop();
        }
        return ans;
    }
};