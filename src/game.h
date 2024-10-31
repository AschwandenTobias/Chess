#ifndef GAME_H
#define GAME_H
#include <cstdint>
#include "chessboard.h"
#include <string>


typedef uint64_t Bitboard;

class Game {
public:
    Game();
    void start();
    bool IsCheckmate;
    bool whiteTurn;
    bool isDraw;
    bool kingIsInCheck;

    bool isMoveValid(int startSquare, int endSquare);
    void makeMove(int startSquare, int endSquare);
    void checkGameOver();
    int translateMove(std::string);
    bool checkIfWhitePawnPromotes(int endSquare);
    bool checkIfBlackPawnPromotes(int endSquare);
    void promoteWhitePawn(int endSquare);
    void promoteBlackPawn(int endSquare);

    Chessboard board;
};

#endif