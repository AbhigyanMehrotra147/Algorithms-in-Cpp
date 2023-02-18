#include<iostream>

template<typename T> struct p_q_node
{
    int data;
    int priority;

    struct p_q_node * next;
};



struct v_node
{
    int data;
    int priority;

    struct v_node* next;

    v_node(int data, int priority)
    {
        this->data = data;
        this->priority = priority;
    }
};
