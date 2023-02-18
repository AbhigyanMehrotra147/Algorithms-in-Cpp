#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = nullptr;
    }
    Node(int x, Node *y)
    {
        data = x;
        next = y;
    }
};
class Stack
{
    struct Node *Top;

public:
    void push(int x)
    {
        if (Top == NULL)
        {
            Top = new Node(x);
            Top->next = nullptr;
            return;
        }
        struct Node *temp = new Node(x);
        temp->next = Top;
        Top = temp;
        return;
    }
    int pop()
    {
        if (Top == nullptr || Top->data == 33063752)
        {
            cout << "Push before popping" << endl;
            return -1;
        }
        struct Node *temp = Top;
        int ans = Top->data;
        Top = Top->next;
        delete temp;
        temp = nullptr;

        return ans;
    }
};
class Queues
{
    struct Node *front = nullptr;
    struct Node *rear = nullptr;

public:
    void push(int x)
    {

        if (rear == nullptr)
        {
            rear = new Node(x);
            front = rear;
            return;
        }
        rear->next = new Node(x);
        rear = rear->next;
    }
    int pop()
    {
        if (front == nullptr)
        {
            cout << "Please push before popping" << endl;
            return -1;
        }
        struct Node *temp = front;
        int ans = front->data;
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
    Queues q;
    Stack s;
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
            q.push(val);
        }
        if (decision == 2)
        {
            int val = q.pop();
            cout << val << endl;
        }
        cout << "Enter 0 for exiting, 1 for pushing, 2 for popping" << endl;
        cin >> decision;
    }
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
