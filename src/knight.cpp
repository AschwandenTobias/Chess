#include "knight.h"
#include <iostream>

void Knight::moveWhiteKnight(Chessboard &board, int startSquare, int endSquare) {
    Bitboard from = (1ULL << startSquare);
    Bitboard to = (1ULL << endSquare);
    if(isWhiteKnightMoveLegal(board, startSquare, endSquare)) {
        if(board.checkIfBlackPieceIsOnSquare(endSquare)) {
            board.deletePiece(to);
        }
        from = ~from;
        board.whiteKnights &= from;
        board.whiteKnights |= to;
    }
}

bool Knight::isWhiteKnightMoveLegal(Chessboard &board, int startSquare, int endSquare) {
    return true;
}