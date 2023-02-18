#include <vector>
#include <iosstream>
#include <queue>
using namespace std;
class LCA
{
public:
    bool found_node = false;
    queue<struct Node *> q;
    struct Node *Root;
    // Function to return the lowest common ancestor in a Binary Tree.
    void get_parent_array(Node *root, int n)
    {
        if (!root)
        {
            return;
        }
        if (found_node == true)
        {
            return;
        }
        if (root->data == n)
        {
            found_node = true;
            // cout << root->data << endl;
            q.push(root);
            return;
        }
        get_parent_array(root->left, n);
        get_parent_array(root->right, n);
        if (found_node == false)
        {
            return;
        }
        q.push(root);
        // cout << root->data << endl;
    }
    bool in_sub_tree(Node *root, int n)
    {
        if (!root)
            return false;
        if (root->data == n)
            return true;
        return in_sub_tree(root->left, n) || in_sub_tree(root->right, n);
    }
    void remove_before_root()
    {
        while (q.front()->data != Root->data)
        {
            q.pop();
        }
    }
    Node *lca(Node *root, int n1, int n2)
    {
        Root = root;
        get_parent_array(root, n1);
        // remove_before_root();
        while (!q.empty() && q.front() != Root)
        {
            // cout << q.front()->data << endl;
            if (in_sub_tree(q.front(), n2))
                return q.front();
            q.pop();
        }
        q.pop();
        if (in_sub_tree(Root, n2))
            return Root;
        return nullptr;
    }
};