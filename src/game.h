#ifndef GAME_H
#define GAME_H
#include "chessboard.h"
#include "move.h"
#include "pieces/pawn.h"
#include "pieces/king.h"

class Game {
public:
    Game(int difficultyLevel = 1);
    bool isCheckmate;
    bool isDraw;
    bool whiteTurn;
    int moveNumber;
    Chessboard board;

    void startGame();
    Move parseMove(std::string move);
    bool isMoveValid(const Move& move);
    void makeMove(const Move& move);
    void makeTurn();
    PieceType promotePiece();
};

#endif