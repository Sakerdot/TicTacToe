#pragma once

#include <array>
#include <iostream>

using namespace std;

class board
{
public:
    // Creates new board, with starter as first mover on the board.
    board(short starter);
    
    // Displays the TicTacToe board.
    void displayBoard() const;
    
    // Makes a move for whomever turn it is and returns true if he has won.
    bool makeMove(short row, short column);
    
    // Returns true if position is empty.
    bool isEmpty(short row, short column) const;
    
    // Returns whose turns it is.
    short currentPlayer() const;
    
private:
    // Checks if whomever turn it is has won yet, changes turn and returns true if match is won.
    bool checkWin();
    
private:
    // 0 will represent empty space, 1 will be X's and 2 will be O's.
    typedef std::array<std::array<short, 3>, 3> Board;
    
    short m_turn;
    Board m_board;
};

