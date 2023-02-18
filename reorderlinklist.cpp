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
struct Node *reverse(Node *head)
{
    struct Node *a = head;
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
    a->next = NULL;
    return prev;
}
int length(struct Node *head)
{
    struct Node *temp = head;

    int len = 0;
    while (temp)
    {
        len++;
        temp = temp->next;
    }
    return len;
}
void reorderList(Node *head)
{
    int len = length(head);
    int half = len / 2;
    struct Node *first_half = head;
    struct Node *sec_half = head;
    struct Node *ans = first_half;
    first_half = first_half->next;
    for (int i = 1; i <= half; i += 1)
    {
        sec_half = sec_half->next;
    }
    if (len % 2 != 0)
    {
        Node *temp = sec_half;
        sec_half = sec_half->next;
        temp->next = NULL'
    }
    struct Node *rev = reverse(sec_half);
    for (int i = 2; i <= len; i += 1)
    {
        if (i % 2 == 0)
        {
            ans->next = rev;
            rev = rev->next;
            ans = ans->next;
        }
        else
        {
            ans->next = first_half;
            first_half = first_half->next;
            ans = ans->next;
        }
    }
}
int main()
{
    struct Node *head = new Node(1);
    struct Node *first = new Node(2);
    struct Node *second = new Node(3);
    struct Node *third = new Node(4);
    struct Node *fourth = new Node(5);
    struct Node *fifth = new Node(6);
    head->next = first;
    first->next = second;
    second->next = third;
    third->next = fourth;
    // fourth->next = fifth;
    reorderList(head);
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
}