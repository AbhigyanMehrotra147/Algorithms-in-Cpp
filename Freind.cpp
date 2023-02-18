#include <iostream>
using namespace std;
class Node
{
    int data;
    Node *next;
    Node(int x, Node *temp = nullptr)
    {
        data = x;
        next = temp;
    }
    friend class Linked_list;
};
class Linked_list
{
public:
    Node *head;
    void add_node(int x)
    {
        if (!head)
        {
            head = new Node(x);
        }
        else
        {
            Node *temp = head;
            while (temp->next)
            {
                temp = temp->next;
            }
            temp->next = new Node(x);
        }
    }
    void display()
    {
        Node *temp = head;
        while (temp)
        {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }
};
int main()
{
    Linked_list l;
    int x = 0;
    while (x <= 9)
    {
        l.add_node(x);
        x += 1;
    }
    l.display();
}