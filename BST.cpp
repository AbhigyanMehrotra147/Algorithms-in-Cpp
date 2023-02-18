#include <iostream>
#include <vector>
using namespace std;
struct Node
{
    int data;
    Node *right_child;
    Node *left_child;
    Node(int d)
    {
        data = d;
        right_child = NULL;
        left_child = NULL;
    }
};
class Tree
{

    vector<int> inorder;
    vector<int> preorder;
    vector<int> postorder;

public:
    struct Node *root;
    Tree()
    {
        root = NULL;
    }
    void destruct(struct Node *root)
    {
        if (root != NULL)
        {
            destruct(root->left_child);
            destruct(root->right_child);
            root = NULL;
            delete root;
        }
    }

    void traverse_inorder(Node *root)
    {
        if (root == NULL)
        {
            return;
        }
        traverse_inorder(root->left_child);
        inorder.push_back(root->data);
        traverse_inorder(root->right_child);
    }
    void print()
    {
        traverse_inorder(root);
        int siz = inorder.size();
        for (int i = 0; i < siz; i += 1)
        {
            cout << inorder[i] << " ";
        }
    }

    Node *create_node(int data)
    {
        Node *temp = new Node(data);
        return temp;
    }
    Node *insert_node(Node *root, int dat)
    {
        if (root == NULL)
        {
            return create_node(dat);
        }
        if (dat < root->data)
        {
            root->left_child = insert_node(root->left_child, dat);
        }
        else
        {
            root->right_child = insert_node(root->right_child, dat);
        }
        return root;
    }
    ~Tree()
    {
        destruct(root);
    }
};
int main()
{
    Tree t;
    int val;
    cout << "Enter data (enter -9999 to stop): ";
    cin >> val;
    if (val == -9999)
    {
        return 0;
    }
    t.root = t.insert_node(t.root, val);
    cout << "Enter data (enter -9999 to stop): ";
    cin >> val;
    while (val != -9999)
    {
        t.root = t.insert_node(t.root, val);
        cout << "Enter data (-9999 to stop): ";
        cin >> val;
    }
    t.print();
}
