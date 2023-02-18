#include <iostream>
using namespace std;
template <class Type>
class Node
{
public:
    Type data;
    Node *next;
    Node(Type x)
    {
        data = x;
        next = nullptr;
    }
};