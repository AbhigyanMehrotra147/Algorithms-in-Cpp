#include <iostream>
#include <vector>
#include <string>
#include "Wordle_box"
using namespace std;
class Board
{
    int coloumns;
    int row;

public:
    box **board;

    Board(int rows, int coloumns)
    {
        board = new box *[rows];
        for (int i = 0; i < rows; i += 1)
        {
            box[i] = new box[coloumns];
        }
        this->coloumns = coloumns;
        this->rows = rows;
    }
    void assign_empty()
    {
        for (int i = 0; i < rows; i += 1)
        {
            for (int j = 0; j < coloumns; j += 1)
            {
                box[i][j].letter = ' ';
            }
        }
    }
    void assign_word(string word, int row)
    {
        for (int i = 0; i < coloumns; i += 1)
        {
            board[row][i] = word[i];
        }
    }
    void print_board()
    {
        for (int i = 0; i < row; i += 1)
        {
            for (int j = 0; j < coloumns; j += 1)
            {
                if (board[i][j].letter == ' ')
                {
                    cout << "|     |";
                    continue;
                }
                cout << "| " << board[i][j].letter << "," << board[i][j].color << " |"
            }
            cout << endl;
        }
    }
}