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
    if(endSquare < 0 || endSquare > 63) {
        return false;
    }
    int distance = std::abs(endSquare - startSquare);
    Bitboard to = (1ULL << endSquare);
    std::cout << "movement distance: " << distance << "\n";
    return((distance == 6 || distance == 10 || distance == 15 || distance == 17) && !board.checkIfWhitePieceIsOnSquare(to));
}

void Knight::moveBlackKnight(Chessboard &board, int startSquare, int endSquare) {
    Bitboard from = (1ULL << startSquare);
    Bitboard to = (1ULL << endSquare);
    if(isBlackKnightMoveLegal(board, startSquare, endSquare)) {
        if(board.checkIfWhitePieceIsOnSquare(endSquare)) {
            board.deletePiece(to);
        }
        from = ~from;
        board.blackKnights &= from;
        board.blackKnights |= to;
    }
}

bool Knight::isBlackKnightMoveLegal(Chessboard &board, int startSquare, int endSquare) {
    if(endSquare < 0 || endSquare > 63) {
        return false;
    }
    int distance = std::abs(endSquare - startSquare);
    Bitboard to = (1ULL << endSquare);
    std::cout << "movement distance: " << distance << "\n";
    return((distance == 6 || distance == 10 || distance == 15 || distance == 17) && !board.checkIfBlackPieceIsOnSquare(to));
}