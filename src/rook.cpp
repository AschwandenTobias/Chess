#include "rook.h"
#include <iostream>

void Rook::moveWhiteRook(Chessboard &board, int startSquare, int endSquare) {
    Bitboard from = 1ULL << startSquare;
    Bitboard to = 1ULL << endSquare;
    if(isWhiteRookMoveLegal(board, startSquare, endSquare)) {
        board.updateLastMove(startSquare, endSquare);
        if(board.checkIfBlackPieceIsOnSquare(endSquare)) {
            board.deletePiece(to);
        }
    from = ~from;
    board.whiteRooks &= from;
    board.whiteRooks |= to;
    }
}

bool Rook::isWhiteRookMoveLegal(Chessboard &board, int startSquare, int endSquare) {
    Bitboard from = 1ULL << startSquare;
    Bitboard to = (1ULL << endSquare);
    if(!(board.checkIfWhiteRookIsOnSquare(from))) {
        return false;
    }
    return true;
}