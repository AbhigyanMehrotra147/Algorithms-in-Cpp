#include <iostream>
#include <queue>
using namespace std;
// The structure of the class is
class QueueStack
{
private:
    queue<int> q1;
    queue<int> q2;

public:
    void push(int);
    int pop();
};

// Function to push an element into stack using two queues.
void QueueStack ::push(int x)
{
    q1.push(x);
}

// Function to pop an element from stack using two queues.
int QueueStack ::pop()
{
    if (q1.empty())
    {
        // cout << -1 << endl;
        return -1;
    }
    int ans;
    while (!q1.empty())
    {
        ans = q1.front();
        q1.pop();
        if (q1.empty())
            break;
        q2.push(ans);
    }
    while (!q2.empty())
    {
        q1.push(q2.front());
        q2.pop();
    }
    return ans;
}