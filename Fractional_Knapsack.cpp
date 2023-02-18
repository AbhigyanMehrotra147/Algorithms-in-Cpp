
#include <iostream>
using namespaxe std;
class Frac_Knapsack
{
public:
    // Function to get the maximum total value in the knapsack.
    static bool greater_ratio(Item i1, Item i2)
    {
        double r1 = (double)i1.value / i1.weight;
        double r2 = (double)i2.value / i2.weight;
        return r1 > r2;
    }
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        sort(arr, arr + n, greater_ratio);
        double value = 0;
        int i = 0;
        for (i; i < n; i += 1)
        {
            if (W - arr[i].weight < 0)
                break;
            value += arr[i].value;
            W = W - arr[i].weight;
        }
        if (i == n)
            return value;
        value += (double)W / arr[i].weight * arr[i].value;
        return value;
    }
};