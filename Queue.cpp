#include <iostream>
#include "Linked_list_node.h"
using namespace std;
template <class Type>
class Queue
{
    Node<Type> *front = nullptr;
    Node<Type> *rear = nullptr;

public:
    bool isEmpty()
    {
        if (front == nullptr || rear == nullptr)
        {
            return true;
        }
        return false;
    }
    Type peek()
    {
        return front->data;
    }
    void ins(Type x)
    {
        if (rear == nullptr)
        {
            rear = new Node<Type>(x);
            front = rear;
            return;
        }
        rear->next = new Node<Type>(x);
        rear = rear->next;
    }
    Type del()
    {
        if (isEmpty() == true)
        {
            cout << "Please push before popping" << endl;
            return -1;
        }
        struct Node<Type> *temp = front;
        Type ans = front->data;
        front = front->next;
        temp = nullptr;
        delete temp;
        if (front == nullptr)
        {
            rear = nullptr;
        }
        return ans;
    }
};
int main()
{
    Queue<int> q;
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
            q.ins(val);
        }
        if (decision == 2)
        {
            int val = q.del();
            cout << val << endl;
        }
        cout << "Enter 0 for exiting, 1 for pushing, 2 for popping" << endl;
        cin >> decision;
    }
}
