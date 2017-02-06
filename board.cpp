#include "board.h"

// Creates new board, with starter as first mover on the board.
board::board(short starter)
{
    for (auto &row : m_board)
    {
        row.fill(0);
    }
    
    m_turn = starter;
}

// Displays the TicTacToe board.
void board::displayBoard() const
{
    for (const auto &row : m_board)
    {
        for (const auto &tile : row)
        {
            cout << "|";
            switch (tile)
            {
                case 0:
                    cout << "   ";
                    break;
                case 1:
                    cout << " X ";
                    break;
                case 2:
                    cout << " O ";
                    break;
                default:
                    cout << endl;
                    cerr << "Error, unknown value on tile" << endl;
                    break;
            }
        }
        
        cout << "|" << endl;
    }
}

// Makes a move for whomever turn it is and returns true if he has won.
bool board::makeMove(short row, short column)
{
    m_board[row][column] = m_turn;
    
    return checkWin();
}

// Returns true if position is empty.
bool board::isEmpty(short row, short column) const
{
    return m_board[row][column] == 0;
}

// Returns whose turns it is.
short board::currentPlayer() const
{
    return m_turn;
}

// Checks if whomever turn it is has won yet, changes turn and returns true if match is won.
bool board::checkWin()
{
    bool win = false;
    
    // Checks for row win condition
    for (const auto &row : m_board)
    {
        if (row[0] == row[1] && row[1] == row[2] && row[0] != 0)
        {
            win = true;
        }
    }
    
    // Checks for column win condition
    for (short j = 0; j < 2; ++j)
    {
        if (m_board[0][j] == m_board[1][j] && m_board[1][j] == m_board[2][j] && m_board[0][j] != 0)
        {
            win = true;
        }
    }
    
    // Checks for diagonal win condition
    if (m_board[0][0] == m_board[1][1] && m_board[1][1] == m_board[2][2] && m_board[0][0] != 0)
    {
        win = true;
    }
    else if (m_board[0][2] == m_board[1][1] && m_board[1][1] == m_board[2][0] && m_board[0][2] != 0)
    {
        win = true;
    }
    
    if (m_turn == 1)
    {
        m_turn = 2;
    }
    else if (m_turn == 2)
    {
        m_turn = 1;
    }
    else
    {
        cerr << "Error, unknown value for turn" << endl;
    }
    
    return win;
}
