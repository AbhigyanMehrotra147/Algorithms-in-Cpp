#include <iostream>
using namespace std;
template <class Type>
struct Node
{
    Type data;
    struct Node *prev;
    struct Node *next;
    Node(Type data, struct Node *prev = nullptr, struct Node *next = nullptr)
    {
        this->data = data;
    }
};