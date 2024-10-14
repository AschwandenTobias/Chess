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
    int distance = std::abs(endSquare - startSquare);
    Bitboard to = (1ULL << endSquare);
    std::cout << "movement distance: " << distance << "\n";
    return((distance == 6 || distance == 10 || distance == 15 || distance == 17) && !board.checkIfWhitePieceIsOnSquare(to));
}