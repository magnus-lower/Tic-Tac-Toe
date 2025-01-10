#include "Board.h"
#include <iostream>
#include <algorithm>

Board::Board() {
    reset();
}

void Board::reset() {
    for (auto &row : grid)
        for (char &cell : row)
            cell = ' ';
}

void Board::display() const {
    std::cout << "  0 1 2\n";
    for (int i = 0; i < 3; ++i) {
        std::cout << i << " ";
        for (int j = 0; j < 3; ++j) {
            std::cout << grid[i][j] << " ";
        }
        std::cout << "\n";
    }
}

bool Board::makeMove(int row, int col, char symbol) {
    if (grid[row][col] == ' ') {
        grid[row][col] = symbol;
        return true;
    }
    return false;
}

bool Board::isGameOver() const {
    return getWinner() != ' ' ||
           std::all_of(&grid[0][0], &grid[0][0] + 9, [](char c) { return c != ' '; });
}

char Board::getWinner() const {
    for (int i = 0; i < 3; ++i) {
        if (grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2] && grid[i][0] != ' ')
            return grid[i][0];
        if (grid[0][i] == grid[1][i] && grid[1][i] == grid[2][i] && grid[0][i] != ' ')
            return grid[0][i];
    }
    if (grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2] && grid[0][0] != ' ')
        return grid[0][0];
    if (grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0] && grid[0][2] != ' ')
        return grid[0][2];
    return ' ';
}