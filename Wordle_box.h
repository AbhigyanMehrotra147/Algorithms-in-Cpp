#include <iostream>
using namespace std;
class box
{
public:
    char letter;
    // 1 for green, -1 for yellow, and 0 for grey and 9 for empty
    int color;
    box() {}
    box(char letter)
    {
        this->letter - letter;
    }
    void change_color(int x)
    {
        this->color = x;
    }
};