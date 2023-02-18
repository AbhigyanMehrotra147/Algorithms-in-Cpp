#include <iostream>
using namespace std;
int *array()
{
    int arr[5] = {1, 3, 4, 2, 1};
    return arr;
}
int main()
{
    int *arr = array();
    cout << *(arr + 3);
}