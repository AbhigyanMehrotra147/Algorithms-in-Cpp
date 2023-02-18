#include <iostream>
#include "Binary_Tree_Node.h"
using namespaces std;
class Check_if_SubTree
{
public:
    // Function to check if S is a subtree of tree T.
    bool equal_trees(Node *&T, Node *S)
    {
        if (!T && !S)
            return true;
        if (!S && T != nullptr)
            return false;
        if (!T && S != nullptr)
            return false;
        if (T->data != S->data)
        {
            return false;
        }
        return true && equal_trees(T->left, S->left) && equal_trees(T->right, S->right);
    }
    bool isSubTree(Node *T, Node *S)
    {
        if (!T && !S)
            return true;
        if (!T && S != nullptr)
            return false;
        if (T != nullptr && !S)
            return false;
        if (T->data == S->data)
        {
            return equal_trees(T, S) || isSubTree(T->left, S) || isSubTree(T->right, S);
        }
        return false || isSubTree(T->left, S) || isSubTree(T->right, S);
    }
};