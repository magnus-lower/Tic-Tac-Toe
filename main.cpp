#include <iostream>
#include "Game.h"

int main() {
    std::cout << "Welcome to Tic-Tac-Toe!\n";
    std::cout << "1. Player vs Player\n";
    std::cout << "2. Player vs AI\n";
    std::cout << "3. Online Multiplayer (Optional)\n";
    std::cout << "Choose a mode: ";

    int choice;
    std::cin >> choice;

    Game game;
    if (choice == 1) {
        game.startPvP();
    } else if (choice == 2) {
        game.startPvAI();
    } else if (choice == 3) {
        game.startOnline();
    } else {
        std::cout << "Invalid choice. Exiting.\n";
    }

    return 0;
}