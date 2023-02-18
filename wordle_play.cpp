#include <iostream>
#include <vector>
#include <string>
#include "Wordle_board.h"
using namespace board;
class play
{
    Board *B;
    play(int rows, int coloumns)
    {
        B = new Board(rows, coloumns);
        B->assign_empty();
        B->print_board();
    }
}