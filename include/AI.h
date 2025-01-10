#ifndef AI_H
#define AI_H

#include "Board.h"

class AI {
public:
    void makeMove(Board& board);
private:
    int minimax(Board& board, bool isMaximizing);
};

#endif