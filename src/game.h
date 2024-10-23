#ifndef GAME_H
#define GAME_H
#include <cstdint>
#include "chessboard.h"


typedef uint64_t Bitboard;

class Game {
public:
    Game();
    void start();
    bool IsCheckmate;
    bool whiteTurn;
    bool isDraw;

    bool isMoveValid(int startSquare, int endSquare);
    void makeMove(int startSquare, int endSquare);
    void checkGameOver();
    void translateMove();
    Chessboard board;
};

#endif