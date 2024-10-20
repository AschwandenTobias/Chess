#include "queen.h"
#include "bishop.h"
#include "rook.h"
#include <iostream>

void Queen::moveWhiteQueen(Chessboard &board, int startSquare, int endSquare) {
    Bitboard from = 1ULL << startSquare;
    Bitboard to = 1ULL << endSquare;
    if(isWhiteQueenMoveLegal(board, startSquare, endSquare)) {
        board.updateLastMove(startSquare, endSquare);
        if(board.checkIfBlackPieceIsOnSquare(endSquare)) {
            board.deletePiece(to);
        }
        from = ~from;
        board.whiteQueen &= from;
        board.whiteQueen |= to;
    }
}

bool Queen::isWhiteQueenMoveLegal(Chessboard &board, int startSquare, int endSquare) {
    if (endSquare < 0 || endSquare > 63) return false;
    Bitboard from = 1ULL << startSquare;
    Bitboard to = 1ULL << endSquare;
    if (!(board.checkIfWhiteQueenIsOnSquare(from))) return false;
    if (board.checkIfWhitePieceIsOnSquare(to)) {
        return false;
    }
    int distance = std::abs(endSquare - startSquare);
    if (distance % 7 == 0 || distance % 9 == 0) {
        if (Bishop::checkDiagonalMoves(board, startSquare, endSquare)) {
            return true;  
        }
    }
    if (distance % 8 == 0) {
        if (Rook::checkVerticalMoves(board, startSquare, endSquare)) {
            return true;  
        }
    } else {
        if (Rook::checkHorizontalMoves(board, startSquare, endSquare)) {
            return true;  
        }
    }
    return false;
}