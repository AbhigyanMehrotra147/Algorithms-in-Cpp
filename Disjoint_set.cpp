#include <iostream>
using namespace std;
int print_arr(int n, int par[])
{
    for (int i = 0; i < n; i += 1)
    {
        cout << par[i] << " ";
        cout << endl;
    }
}
int compress(int x, int(par)[])
{
    if (par[x] == x)
        return x;
    par[x] = compress(par[x], par);
}
int find(int x, int par[])
{
    return compress(x, par);
}
int main()
{
    int par[7] = {0,
                  0,
                  1,
                  2,
                  3,
                  5,
                  5};
    int parent = find(4, par);
    print_arr(7, par);
}