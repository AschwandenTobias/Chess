#ifndef GAME_H
#define GAME_H
#include <cstdint>
#include "chessboard.h"
#include <string>
#include <vector>


typedef uint64_t Bitboard;

class Game {
public:
    Game();
    void start(const std::vector<std::string>& moves = {});
    bool IsCheckmate;
    bool whiteTurn;
    bool isDraw;
    bool kingIsInCheck;

    bool isWhiteCheckmate();
    bool isMoveValid(int startSquare, int endSquare);
    void makeMove(int startSquare, int endSquare);
    bool checkGameOver();
    int translateMove(std::string);
    bool checkIfWhitePawnPromotes(int endSquare);
    bool checkIfBlackPawnPromotes(int endSquare);
    void promoteWhitePawn(int endSquare);
    void promoteBlackPawn(int endSquare);
    std::vector<std::string> notationTranslator(std::string moves);
    void removeChessComDollarSigns(std::string& moves);
    void removeXandPlus(std::string& moves);
    void removeMoveNumbersAndResult(std::string& moves);
    Chessboard board;
};

#endif