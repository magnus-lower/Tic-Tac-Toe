#include "AI.h"
#include <limits>
#include <algorithm>  // ✅ Include this to fix std::max and std::min errors

void AI::makeMove(Board& board) {
    int bestScore = std::numeric_limits<int>::min();
    int bestRow = -1, bestCol = -1;

    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            if (board.makeMove(row, col, 'O')) {
                int score = minimax(board, false);  // ✅ Call the now-defined function
                board.makeMove(row, col, ' ');  // Undo move
                if (score > bestScore) {
                    bestScore = score;
                    bestRow = row;
                    bestCol = col;
                }
            }
        }
    }
    board.makeMove(bestRow, bestCol, 'O');
}

int AI::minimax(Board& board, bool isMaximizing) {
    char winner = board.getWinner();
    if (winner == 'O') return 10;
    if (winner == 'X') return -10;
    if (board.isGameOver()) return 0;

    int bestScore = isMaximizing ? std::numeric_limits<int>::min() : std::numeric_limits<int>::max();
    char symbol = isMaximizing ? 'O' : 'X';

    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            if (board.makeMove(row, col, symbol)) {
                int score = minimax(board, !isMaximizing);
                board.makeMove(row, col, ' ');  // Undo move
                bestScore = isMaximizing ? std::max(bestScore, score) : std::min(bestScore, score);
            }
        }
    }
    return bestScore;
}