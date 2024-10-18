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
    //Bitboard to = 1ULL << endSquare;
    if(endSquare < 0 || endSquare > 63) return false;
    if(!(board.checkIfWhiteRookIsOnSquare(from))) {
        std::cout << "there was no rook on the startSquare\n";
        return false;
    } else { 
        if((std::abs(endSquare - startSquare) % 8) == 0) {
            return checkVerticalMoves(board, startSquare, endSquare);
        } else {
            return checkHorizontalMoves(board, startSquare, endSquare);
        }
    }
    return true;
}

bool Rook::checkHorizontalMoves(Chessboard &board, int startSquare, int endSquare) {
    std::cout << "Horizontal move detected\n";
    int distance = std::abs(endSquare - startSquare);
    int startRow = startSquare / 8;
    int endRow = endSquare / 8;
    if (startRow != endRow) return false;
    std::cout << "startRow: " << startRow << "\n";
    return true;
}

bool Rook::checkVerticalMoves(Chessboard &board, int startSquare, int endSquare) {
    std::cout << "Vertical move detected\n";
    int distance = std::abs(endSquare - startSquare);
    if(distance % 8 != 0) return false;
    return true;
}