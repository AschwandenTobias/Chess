#ifndef GAME_H
#define GAME_H
#include "chessboard.h"


class Game {
public:
    Game(int difficultyLevel = 1);
    bool isCheckmate;
    Chessboard board;
    
};

#endif