#ifndef PAWN_H
#define PAWN_H

#include "../chessboard.h"
#include <vector>
#include "../move.h"


typedef uint64_t Bitboard;

class Pawn {
public:
    static void moveWhitePawn(Chessboard &board, int startSquare, int endSquare);
    static bool isWhitePawnMoveLegal(Chessboard &board, int startSquare, int endSquare);
    static bool checkForWhiteEnPassant(Chessboard &board, int startSquare, int endSquare);
    static void moveBlackPawn(Chessboard &board, int startSquare, int endSquare);
    static bool isBlackPawnMoveLegal(Chessboard &board, int startSquare, int endSquare);
    static bool checkForBlackEnPassant(Chessboard &board, int startSquare, int endSquare);
    static std::vector<int> getAttackingSquares(Chessboard &board, int startSquare, int  endSquare);
    static bool canAPawnMoveToSquare(Chessboard &board, int endSquare, bool white);
    static bool canPawnAttackSquare(Chessboard &board, int endSquare, bool white);
    static std::vector<std::pair<int, int>> getAllPossiblePawnMoves(Chessboard &board, bool white);


    static bool isPawnMoveLegal(Chessboard &board, Move move, bool white);
};

#endif