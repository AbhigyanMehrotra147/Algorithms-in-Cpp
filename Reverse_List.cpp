#include <iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class Solution
{
    struct Node *return_node;

public:
    // Function to reverse a linked list.
    struct Node *reverseList(struct Node *head)
    {
        struct Node *f = head;
        if (!(*head).next)
        {
            return head;
        }
        struct Node *prev = head;
        head = (*head).next;
        struct Node *temp = (*head).next;
        while (temp)
        {
            head->next = prev;
            prev = head;
            head = temp;
            temp = temp->next;
        }
        head->next = prev;
        prev = head;
        head = temp;
        (*f).next = NULL;
        return prev;
    }
    void reverse(struct Node *prev, struct Node *head)
    {
        if (head->next == NULL)
        {
            head->next = prev;
            prev->next = NULL;
            return_node = head;
            return;
        }
        reverse(prev->next, head->next);
        head->next = prev;
        prev->next = NULL;
    }
    struct Node *reverseList2(struct Node *head)
    {
        reverse(head, head->next);
        return return_node;
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
    struct Node *head1 = s1.reverseList2(head);
    while (head1)
    {
        cout << head1->data << endl;
        head1 = head1->next;
    }
}