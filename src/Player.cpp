#include "Player.h"
#include <iostream>

void Player::makeMove(Board& board) {
    int row, col;
    std::cout << "Enter row and column (0-2): ";
    std::cin >> row >> col;
    while (!board.makeMove(row, col, 'X')) {  // Assuming 'X' for Player 1
        std::cout << "Invalid move. Try again: ";
        std::cin >> row >> col;
    }
}