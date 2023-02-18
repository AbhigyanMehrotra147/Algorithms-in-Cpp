#include<iostream>
#include"p_queue_node.h"
using namespace std;

// Ascending priority queue
class A_priority_queue
{
    private:

    struct p_node* head = nullptr;

    public:

    A_priority_queue(int data, int priority)
    {
        this->head = new struct p_node(data,priority);
        head->next = nullptr;
    }


    
};

int main()
{
    A_priority_queue P_Q(5,4);
    P_Q.enqueue(5,3);
}