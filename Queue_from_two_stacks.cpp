#include <stack>
#include <iostream>
using namespace std;

// The structure of the class is
class StackQueue
{
private:
    // These are STL stacks ( http://goo.gl/LxlRZQ )
    stack<int> s1;
    stack<int> s2;

public:
    void push(int);
    int pop();
};

void StackQueue ::push(int x)
{
    s1.push(x);
    // cout << s1.top() << endl;
}

// Function to pop an element from queue by using 2 stacks.
int StackQueue ::pop()
{
    if (s1.empty())
        return -1;
    while (!s1.empty())
    {
        s2.push(s1.top());
        s1.pop();
        // cout << s2.top() << endl;
    }
    int ans = s2.top();
    s2.pop();
    while (!s2.empty())
    {
        s1.push(s2.top());
        s2.pop();
    }

    return ans;
}