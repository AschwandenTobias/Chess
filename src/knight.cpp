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
    Bitboard from = (1ULL << startSquare);
    Bitboard to = (1ULL << endSquare);
    if(endSquare < 0 || endSquare > 63) return false;
    if(!board.checkIfWhiteKnightIsOnSquare(from)) return false;
    int startRow = startSquare / 8;
    int endRow = endSquare / 8;
    int startCol = startSquare % 8;
    int endCol =  endSquare % 8;
    if(((std::abs(endRow - startRow) == 2) && (std::abs(endCol - startCol) == 1)) || ((std::abs(endRow - startRow) == 1) && (std::abs(endCol - startCol) == 2))) {
        if(board.checkIfWhitePieceIsOnSquare(to)) {
            std::cout << "Illegal move\n";
            return false;
        } else {
            return true;
        }
    } else {    
        std::cout << "Not a L-shape move\n";
        return false;
    }
    return true;
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
    Bitboard from = (1ULL << startSquare);
    Bitboard to = (1ULL << endSquare);
    if(endSquare < 0 || endSquare > 63) return false;
    if(!board.checkIfBlackKnightIsOnSquare(from)) return false;
    int startRow = startSquare / 8;
    int endRow = endSquare / 8;
    int startCol = startSquare % 8;
    int endCol =  endSquare % 8;
    if(((std::abs(endRow - startRow) == 2) && (std::abs(endCol - startCol) == 1)) || ((std::abs(endRow - startRow) == 1) && (std::abs(endCol - startCol) == 2))) {
        if(board.checkIfBlackPieceIsOnSquare(to)) {
            std::cout << "Illegal move\n";
            return false;
        } else {
            return true;
        }
    } else {    
        std::cout << "Not a L-shape move\n";
        return false;
    }
    return true;
}