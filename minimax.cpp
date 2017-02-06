#include "minimax.h"

// Returns true if currScore is greater than prevScore if it's maximizing or if
// currScore is lower than prevScore if it's minimizing.
bool switchMove(bool minimax, short currScore, short prevScore)
{
    return (minimax && currScore > prevScore) || (!minimax && currScore < prevScore);
}

// Returns the position of the next best move along with the score of said move.
aiMove nextMove(const board &currentBoard, short length, bool minimax)
{
    aiMove result;
    bool first = true;
    
    for (short i = 0; i < 3; ++i)
    {
        for (short j = 0; j < 3; ++j)
        {
            if (currentBoard.isEmpty(i, j))
            {
                board newBoard = currentBoard;
                bool win = newBoard.makeMove(i, j);
                
                short scoreAtTile;
                if (win)
                {
                    scoreAtTile = minimax ? 10 - (length + 1) : -10 + (length + 1);
                }
                else if (length == 8)
                {
                    scoreAtTile = 0;
                }
                else
                {
                    scoreAtTile = nextMove(newBoard, length + 1, !minimax)[0];
                }
                
                if (first || switchMove(minimax, scoreAtTile, result[0]))
                {
                    result = { scoreAtTile, i, j };
                    first = false;
                }
            }
        }
    }
    
    return result;
}