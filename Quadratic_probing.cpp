#include <iostream>
#include <utility>
using namespace std;
class Quad_probing
{
public:
    pair<int, bool> *hash_table;
    int size_table;
    Quad_probing(int Size)
    {
        size_table = Size;
        hash_table = new pair<int, bool>[size_table];

        for (int i = 0; i < size_table; i += 1)
        {
            pair<int, bool> p(-INT_MIN, false);
            hash_table[i] = p;
        }
    }
    int hash_function(int x)
    {
        return x % size_table;
    }
    void insert(int x)
    {
        int key = hash_function(x);
        int index;
        int i = 0;
        while (i < size_table)
        {
            index = hash_function(key + i * i);
            if (!hash_table[index].second)
                break;
            i += 1;
        }
        if (i >= size_table)
        {
            // cout << "table full for these elements" << endl;
            // cout << "so many such type of numbers indicates that linear probing might have been better" << endl;
            return;
        }

        hash_table[index].first = x;
        hash_table[index].second = true;
    }
    int search(int x)
    {
        int i = 0;
        int index = hash_function(x);
        while (i < size_table)
        {
            index = hash_function(index + i * i);
            if (hash_table[index].first == x)
                return index;
            i += 1;
        }
        return INT_MAX;
    }
    void delete_key(int x)
    {
        int index = search(x);
        if (index == INT_MAX)
            return;

        hash_table[index].first = INT_MIN;
        hash_table[index].second = false;
    }
    void print()
    {
        for (int i = 0; i < size_table; i += 1)
        {
            cout << hash_table[i].first << " ";
        }
    }
};
int main()
{
    Quad_probing Qp(13);
    bool contynue = 1;
    while (contynue)
    {
        bool choice;
        cin >> choice;
        fflush(stdin);
        int ele;
        cin >> ele;
        fflush(stdin);
        if (choice == 1)
        {
            Qp.insert(ele);
        }
        if (choice == 2)
        {
            Qp.delete_key(ele);
        }
        Qp.print();
        fflush(stdin);
        cin >> contynue;
        fflush(stdin);
    }
}