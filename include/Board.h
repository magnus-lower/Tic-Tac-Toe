#ifndef BOARD_H
#define BOARD_H

class Board {
public:
    Board();
    void display() const;
    bool makeMove(int row, int col, char symbol);
    bool isGameOver() const;
    char getWinner() const;
    void reset();

private:
    char grid[3][3];  // ✅ Define grid properly
};

#endif  // BOARD_H