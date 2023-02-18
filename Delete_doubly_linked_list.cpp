#include <iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;

    Node(int x)
    {
        data = x;
        next = NULL;
        prev = NULL;
    }
};
class Solution
{
public:
    struct Node *deleteNode(struct Node *head_ref, int x)
    {
        if (head_ref->next == NULL)
        {
            delete head_ref;
            return NULL;
        }
        struct Node *temp = head_ref;
        for (int i = 1; i < x; i += 1)
        {
            temp = temp->next;
        }
        if (temp->next == NULL)
        {
            delete temp;
            return head_ref;
        }
        struct Node *pre = temp->prev;
        struct Node *Ahead = temp->next;
        pre->next = Ahead;
        Ahead->prev = pre;
        delete temp;
        return head_ref;
    }
    int count(struct Node *head_ref)
    {
        int count = 0;
        struct Node *temp = head_ref;
        while (temp)
        {
            count += 1;
            temp = temp->next;
        }
        return count;
    }
};
int main()
{
    struct Node *head = new Node(1);
    struct Node *first = new Node(2);
    struct Node *second = new Node(3);
    struct Node *third = new Node(4);
    head->next = first;
    first->next = second;
    second->next = third;
    Solution s1;
    head = s1.deleteNode(head, 3);
    while (head)
    {
        cout << head->data << " ";
        head = (*head).next;
    }
}