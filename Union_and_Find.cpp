#include <iostream>
using namespace std;
class Disjoint_Set
{
public:
    // Function to merge two nodes a and b.
    int compress(int x, int par[])
    {
        if (par[x] == x)
        {
            return x;
        }
        par[x] = compress(par[x], par);
    }
    void join(int p1, int p2, int par[], int rank[])
    {
        par[p2] = p1;
        rank[p1] += rank[p2];
    }
    void union_(int a, int b, int par[], int rank1[])
    {
        int pa = compress(a, par);
        int pb = compress(b, par);
        if (pa == pb)
            return;
        if (rank1[pa] > rank1[pb])
        {
            join(pa, pb, par, rank1);
            return;
        }
        join(pb, pa, par, rank1);
    }

    // Function to check whether 2 nodes are connected or not.
    bool isConnected(int x, int y, int par[], int rank1[])
    {
        int p1 = compress(x, par);
        int p2 = compress(y, par);
        return p1 == p2;
    }
};