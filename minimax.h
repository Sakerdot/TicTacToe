#pragma once

#include <array>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "board.h"

// @0 score, @1 row, @2 column
typedef std::array<short, 3> aiMove;

// Returns true if currScore is greater than prevScore if it's maximizing or if
// currScore is lower than prevScore if it's minimizing.
bool switchMove(bool minimax, short currScore, short prevScore);

// Returns the position of the next best move along with the score of said move.
aiMove nextMove(const board &currentBoard, short length, bool minimax);