#include <iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
    Node(int x, struct Node *nex = nullptr)
    {
        next = nex;
        data = x;
    }
};
class Solution
{
    struct Node *repeat = nullptr;

public:
    // Function to remove a loop in the linked list.
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
                repeat = first;
                return true;
            }
        }
        return false;
    }
    void removeLoop(Node *head)
    {
        bool flag = detectLoop(head);
        if (flag == false)
        {
            return;
        }
        int count_in_loop = 1;
        struct Node *temp = repeat->next;
        while (temp != repeat)
        {
            temp = temp->next;
            count_in_loop = count_in_loop + 1;
        }
        int count_from_start = 0;
        temp = head;
        while (temp != repeat)
        {
            temp = temp->next;
            count_from_start += 1;
        }
        temp = head;
        for (int i = 1; i <= (count_from_start - count_in_loop); i += 1)
        {
            temp = temp->next;
        }
        struct Node *pot_repeat = temp;
        temp = temp->next;
        int i = 1;
        while (pot_repeat != temp)
        {
            if (i == count_in_loop)
            {
                pot_repeat = pot_repeat->next;
                temp = pot_repeat->next;
                i = 1;
                continue;
            }
            temp = temp->next;
            i += 1;
        }
        for (int i = 1; i < count_in_loop; i += 1)
        {
            pot_repeat = pot_repeat->next;
        }
        // cout << pot_repeat->data<< endl;
        delete pot_repeat->next;
        pot_repeat->next = nullptr;
        return;
    }
};
int main()
{
    struct Node *fifth = new Node(5);
    struct Node *fourth = new Node(4, fifth);
    struct Node *third = new Node(3, fourth);
    struct Node *second = new Node(2, third);
    struct Node *first = new Node(1, second);
    Solution s1;
    s1.removeLoop(first);
    struct Node *temp = first;
    while (temp)
    {
        cout << temp->data << endl;
    }
    return 0;
}