#ifndef QUEEN_H
#define QUEEN_H

#include "../chessboard.h"
#include <vector>

typedef uint64_t Bitboard;

class Queen {
public:    
    static void moveWhiteQueen(Chessboard &board, int startSquare, int endSquare);
    static bool isWhiteQueenMoveLegal(Chessboard &board, int startSquare, int endSquare);
    static void moveBlackQueen(Chessboard &board, int startSquare, int endSquare);
    static bool isBlackQueenMoveLegal(Chessboard &board, int startSquare, int endSquare);
    static bool canQueenAttackSquare(Chessboard &board, int square, bool white);
    static std::vector<int> getAttackingSquares(Chessboard &board, int startSquare, int  endSquare);
    static std::vector<std::pair<int, int>> getAllPossibleQueenMoves(Chessboard &board, bool white);
};

#endif