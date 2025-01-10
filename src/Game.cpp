#include "Game.h"
#include <iostream>

Game::Game() {
    player1 = new Player();  // ✅ Correctly allocated memory
    player2 = new Player();
    network = new Network();
}

Game::~Game() {
    delete player1;
    delete player2;
    delete network;
}

void Game::startPvP() {
    board.reset();
    int turn = 1;
    while (!board.isGameOver()) {
        board.display();
        if (turn % 2 == 1)
            player1->makeMove(board);
        else
            player2->makeMove(board);
        turn++;
    }
    board.display();
    std::cout << "Game Over! Winner: " << board.getWinner() << "\n";
}

void Game::startPvAI() {
    board.reset();
    int turn = 1;
    while (!board.isGameOver()) {
        board.display();
        if (turn % 2 == 1)
            player1->makeMove(board);
        else
            ai.makeMove(board);
        turn++;
    }
    board.display();
    std::cout << "Game Over! Winner: " << board.getWinner() << "\n";
}

void Game::startOnline() {
    network->connect();
    board.reset();
}