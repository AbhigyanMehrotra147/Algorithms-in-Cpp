#include <iostream>
#include <math.h>
using namespace std;
int *crossover_max(int a[], int low, int mid, int high)
{
    int *ans = new int[3];
    int l_max = int(-pow(2, 31));
    int sum = 0;
    for (int i = mid; i > -1; i -= 1)
    {
        sum = sum + a[i];
        if (l_max < sum)
        {
            l_max = sum;
            ans[1] = i;
        }
    }
    int r_max = int(-pow(2, 31));
    sum = 0;
    for (int i = mid + 1; i <= high; i += 1)
    {
        sum = sum + a[i];
        if (r_max < sum)
        {
            r_max = sum;
            ans[2] = i;
        }
    }
    ans[0] = l_max + r_max;
    return ans;
}
int *max_subarr(int a[], int low, int high)
{
    int *ans = new int[3];
    int *left = new int[3];
    int *right = new int[3];
    int *cross = new int[3];
    if (low == high)
    {
        ans[1] = low;
        ans[2] = high;
        ans[0] = a[low];
        return ans;
    }
    int mid = (low + high) / 2;
    left = max_subarr(a, low, mid);
    right = max_subarr(a, mid + 1, high);
    cross = crossover_max(a, low, mid, high);
    if (left[0] > right[0] && left[0] > cross[0])
    {
        return left;
    }
    if (right[0] > left[0] && right[0] > cross[0])
    {
        return right;
    }
    else
    {
        return cross;
    }
}
int main()
{
    int a[] = {-2, 2, 3, -4, 6, -1, 7, 12 - 8};
    int *ans = new int[3];
    ans = max_subarr(a, 0, 7);
    cout << ans[0] << endl;
    cout << ans[1] << " " << ans[2] << endl;
    return 0;
}