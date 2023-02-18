#include "Linked_list_node.h"
using namespace std;
template <class Type>
class Stack
{
    Node<Type> *Top = nullptr;

public:
    bool isEmpty()
    {
        if (Top != nullptr)
        {
            return false;
        }
        return true;
    }
    Type peek()
    {
        return Top->data;
    }
    void push(Type x)
    {
        if (Top == NULL)
        {
            Top = new Node<Type>(x);
            return;
        }
        Node<Type> *temp = new Node<Type>(x);
        temp->next = Top;
        Top = temp;
        return;
    }
    Type pop()
    {
        if (Top == nullptr)
        {
            cout << "Push before popping" << endl;
            return -1;
        }
        Node<Type> *temp = Top;
        Type ans = Top->data;
        Top = Top->next;
        delete temp;
        temp = nullptr;
        return ans;
    }
};
int main()
{
    Stack<char> s;
    int decision;
    cout << "Enter 0 for exiting, 1 for pushing, 2 for popping" << endl;
    cin >> decision;
    while (decision != 0)
    {
        if (decision != 1 && decision != 2)
        {
            cout << "worng decision" << endl;
        }
        if (decision == 1)
        {
            int val;
            cout << "Enter value" << endl;
            cin >> val;
            s.push(val);
        }
        if (decision == 2)
        {
            int val = s.pop();
            cout << val << endl;
        }
        cout << "Enter 0 for exiting, 1 for pushing, 2 for popping" << endl;
        cin >> decision;
    }
}
