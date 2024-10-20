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

void Queen::moveBlackQueen(Chessboard &board, int startSquare, int endSquare) {
    Bitboard from = 1ULL << startSquare;
    Bitboard to = 1ULL << endSquare;
    if(isBlackQueenMoveLegal(board, startSquare, endSquare)) {
        board.updateLastMove(startSquare, endSquare);
        if(board.checkIfWhitePieceIsOnSquare(endSquare)) {
            board.deletePiece(to);
        }
        from = ~from;
        board.blackQueen &= from;
        board.blackQueen |= to;
    }
}

bool Queen::isBlackQueenMoveLegal(Chessboard &board, int startSquare, int endSquare) {
    //std::cout << "Beginning of isBlackQueenMoveLegal\n";
    if (endSquare < 0 || endSquare > 63) return false;
    Bitboard from = 1ULL << startSquare;
    Bitboard to = 1ULL << endSquare;
    if (!(board.checkIfBlackQueenIsOnSquare(from))) return false;
    if (board.checkIfBlackPieceIsOnSquare(to)) {
        //std::cout << "Detected black Piece on endSquare\n";
        return false;
    }
    int distance = std::abs(endSquare - startSquare);
    //std::cout << "Distance: " << distance << "\n";
    if (distance % 7 == 0 || distance % 9 == 0) {
        //std::cout << "Vertical queen move detected\n";
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