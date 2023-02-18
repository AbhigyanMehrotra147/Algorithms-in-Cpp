#include <iostream>
#include "DLL_Node.h"
using namespace std;
void addNode(struct Node<int> *head, int pos, int data)
{
    if (!head && pos != 0)
        return;
    if (pos == -1)
    {
        struct Node<int> *temp = new struct Node<int>(data);
        temp->next = head;
        head->prev = temp;
        head = temp;
        return;
    }
    struct Node<int> *temp1 = head;
    struct Node<int> *temp2 = head->next;
    int count = 0;
    while (count != pos && temp2)
    {
        count += 1;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    if (!temp2 && pos != count)
        abort();
    if (!temp2)
    {
        struct Node<int> *temp = new struct Node<int>(data);
        temp1->next = temp;
        temp->prev = temp1;
        return;
    }
    struct Node<int> *temp = new struct Node<int>(data);
    temp1->next = temp;
    temp2->prev = temp;
    temp->prev = temp1;
    temp->next = temp2;
}
int mainI()
{
    return 0;
}