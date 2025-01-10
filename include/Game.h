#ifndef GAME_H
#define GAME_H

#include "Board.h"
#include "AI.h"
#include "Player.h"   // ✅ Include full definition
#include "Network.h"  // ✅ Include full definition

class Game {
public:
    Game();
    ~Game();

    void startPvP();
    void startPvAI();
    void startOnline();

private:
    Board board;
    Player* player1;
    Player* player2;
    AI ai;
    Network* network;
};

#endif  // GAME_H