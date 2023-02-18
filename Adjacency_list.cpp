#include <vector>
#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = nullptr;
    }
};
class Graph
{
    vector<Node *> Nvec;
    Graph()
    {
        int i = 1;
        int j;
        int data;
        int k = 0;
        while (i == 1)
        {
            Nvec[k] = new Node(-9999);
            struct Node *temp = Nvec[k];
            j = 1;
            while (j == 1)
            {

                cout << "Enter Node" << endl;
                cin >> data;
                temp->next = new Node(data);
                temp = temp->next;
                cout << "Press 1 to enter more nodes in the same path else enter any integer" << endl;
                cin >> j;
            }
            k += 1;
            cout << "Press 1 to enter more paths else enter anything" << endl;
            cin >> i;
        }
    }
};
