#include <iostream>
using namespace std;
template <class Type>
class Node
{
public:
    Type data;
    Node<Type> *next;
    Node(Type dat, Node *nex = nullptr)
    {
        data = dat;
        next = nex;
    }
    bool detectLoop(Node *head)
    {
        struct Node *first = head;
        struct Node *second = head;
        while (second && second->next)
        {
            first = first->next;
            second = second->next->next;
            if (first == second)
            {
                return true;
            }
        }
        return false;
    }
};