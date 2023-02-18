class Solution
{
    struct Node *return_node;

public:
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
        /*if(i==len)
        {
            prev->next = NULL
        }*/
    }
    struct Node *reverseList(struct Node *head)
    {
        reverse(head, head->next);
        return return_node;
    }
    Node *addOne(Node *head)
    {
        if (head->next == NULL)
        {
            if (head->data == 9)
            {
                head->data = 1;
                head->next = new Node(0);
                return head;
            }
            head->data += 1;
            return head;
        }
        struct Node *rev_head;
        rev_head = reverseList(head);
        struct Node *temp = rev_head;
        while (temp->data == 9)
        {
            temp->data = 0;
            temp = temp->next;
        }
        temp->data += 1;
        head = reverseList(rev_head);
        return head;
    }
};