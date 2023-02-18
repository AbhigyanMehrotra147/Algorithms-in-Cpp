#include <iostream>
using namespace std;
class box
{
public:
    string letter;
    // 1 for green, -1 for yellow, and 0 for grey and -9999 for empty
    int color;
    box(string letter)
    {
        this->letter - letter;
    }
    void change_color(int x)
    {
        thhis->color = x;
    }
}