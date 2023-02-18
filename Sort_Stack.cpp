#include <iostream>
#include <stack>
using namespace std;
// The structure of the class is class SortedStack
{
public:
    stack<int> s;
    void sort();
};

void push_element_in_order(stack<int> &s, int x)
{
    stack<int> temp;
    while (!s.empty())
    {
        // cout << s.top() << " ";
        if (x > s.top())
        {
            s.push(x);
            break;
        }
        temp.push(s.top());
        s.pop();
    }
    if (s.empty())
        s.push(x);
    while (!temp.empty())
    {
        s.push(temp.top());
        temp.pop();
    }
    // cout << endl;
}
void SortedStack ::sort()
{
    if (s.empty())
        return;
    int data = s.top();
    s.pop();
    //   cout << data << " ";
    SortedStack ::sort();
    push_element_in_order(s, data);
}