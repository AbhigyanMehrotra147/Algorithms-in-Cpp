#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int arr[3] = {1, 2, 3};
    for (auto x : arr)
    {
        cout << x << endl;
    }
    vector<int> v;
    if (v.empty())
    {
        cout << "empty" << endl;
    }
    cout << v.empty() << endl;
    return 0;
}