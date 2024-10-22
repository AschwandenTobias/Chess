#include <iostream>
#include "king.h"

void King::moveWhiteKing(Chessboard &board, int startSquare, int endSquare) {
    Bitboard from = 1ULL << startSquare;
    Bitboard to = 1ULL << endSquare;
    if(isWhiteKingMoveLegal(board, startSquare, endSquare)) {
        board.updateLastMove(startSquare, endSquare);
        if(board.checkIfBlackPieceIsOnSquare(endSquare)) {
            board.deletePiece(to);
        }
        from = ~from;
        board.whiteKing &= from;
        board.whiteKing |= to;
    }
}

bool King::isWhiteKingMoveLegal(Chessboard &board, int startSquare, int endSquare) {
    Bitboard from = 1ULL << startSquare;
    Bitboard to = 1ULL << endSquare;
    if(endSquare < 0 || endSquare > 63) return false;
    if(!board.checkIfWhiteKingIsOnSquare(from)) return false;
    if(board.checkIfWhitePieceIsOnSquare(to)) return false;
    int distance = std::abs(endSquare - startSquare);
    int startRow = startSquare / 8;
    int endRow = endSquare / 8;
    if (std::abs(endRow - startRow) > 1) return false;
    if(distance == 1 || distance == 7 || distance == 8 || distance == 9) {
        return true;
    }
    return false;
}

void King::moveBlackKing(Chessboard &board, int startSquare, int endSquare) {
    Bitboard from = 1ULL << startSquare;
    Bitboard to = 1ULL << endSquare;
    if(isBlackKingMoveLegal(board, startSquare, endSquare)) {
        board.updateLastMove(startSquare, endSquare);
        if(board.checkIfWhitePieceIsOnSquare(endSquare)) {
            board.deletePiece(to);
        }
        from = ~from;
        board.blackKing &= from;
        board.blackKing |= to;
    }
}

bool King::isBlackKingMoveLegal(Chessboard &board, int startSquare, int endSquare) {
    Bitboard from = 1ULL << startSquare;
    Bitboard to = 1ULL << endSquare;
    if(endSquare < 0 || endSquare > 63) return false;
    if(!board.checkIfBlackKingIsOnSquare(from)) return false;
    if(board.checkIfBlackPieceIsOnSquare(to)) return false;
    int distance = std::abs(endSquare - startSquare);
    int startRow = startSquare / 8;
    int endRow = endSquare / 8;
    if (std::abs(endRow - startRow) > 1) return false;
    if(distance == 1 || distance == 7 || distance == 8 || distance == 9) {
        return true;
    }
    return false;
}