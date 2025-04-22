#ifndef GAME_H
#define GAME_H
#include "chessboard.h"
#include "move.h"

class Game {
public:
    Game(int difficultyLevel = 1);
    bool isCheckmate;
    bool isDraw;
    bool whiteTurn;
    int moveNumber;
    Chessboard board;

    void startGame();
    void parseMove(std::string move);
    bool isMoveValid(Move move);
    
};

#endif