#ifndef ROOK_H
#define ROOK_H

#include "../chessboard.h"
#include <vector>

typedef uint64_t Bitboard;

class Rook {
public:    
    static void moveWhiteRook(Chessboard &board, int startSquare, int endSquare);
    static void moveBlackRook(Chessboard &board, int startSquare, int endSquare);
    static bool isWhiteRookMoveLegal(Chessboard &board, int startSquare, int endSquare);
    static bool isBlackRookMoveLegal(Chessboard &board, int startSquare, int endSquare);
    static bool checkHorizontalMoves(Chessboard &board, int startSquare, int endSquare);
    static bool checkVerticalMoves(Chessboard &board, int startSquare, int endSquare);
    static std::vector<int> getAttackingSquares(Chessboard &board, int startSquare, int  endSquare);
    static std::vector<std::pair<int, int>> getAllPossibleRookMoves(Chessboard &board, bool white);

};

#endif