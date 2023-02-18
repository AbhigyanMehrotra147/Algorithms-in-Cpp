#include <iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    Node(int d = INT_MIN, struct Node *l = nullptr, struct Node *r = nullptr)
    {
        this->data = d;
        this->left = l;
        this->right = r;
    }
};