#include <iostream>
#include "king.h"
#include "Bishop.h"
#include "Knight.h"

bool King::isSquareInWhiteCheck(Chessboard &board, int square) {
    if(checkBlackBishopMovesForCheck(board, square)) {
        return true;
    } else if (checkBlackKnightMovesForCheck(board, square)) {
        return true;
    }
    return false;
}

bool King::checkBlackBishopMovesForCheck(Chessboard &board, int startSquare) {
    //std::cout << "We check now enemy Bishop moves for checks\n";
    Bitboard blackBishops = board.blackBishops;
    int numberOfBlackBishops = __builtin_popcountll(blackBishops);
    //std::cout << "Number of Black Bishops: " << numberOfBlackBishops << "\n";
    for(int i = 0; i < numberOfBlackBishops; i++) {
        int bishopSquare = __builtin_ffsll(blackBishops) - 1;
        if(Bishop::checkDiagonalMoves(board, bishopSquare, startSquare)) {
            std::cout << "Black Bishop can attack the white King!\n";
            return true;
        }
        blackBishops &= blackBishops - 1;
    }
    //std::cout << "No black Bishop checks detected\n";
    return false; 
}

bool King::checkBlackKnightMovesForCheck(Chessboard &board, int startSquare) {
    std::cout << "We check now enemy Knight moves for checks\n";
    Bitboard blackKnights = board.blackKnights;
    int numberOfBlackKnights = __builtin_popcountll(blackKnights);
    std::cout << "Number of Black Knights: " << numberOfBlackKnights << "\n";
    for(int i = 0; i < numberOfBlackKnights; i++) {
        int bishopSquare = __builtin_ffsll(blackKnights) - 1;
        if(Knight::isBlackKnightMoveLegal(board, bishopSquare, startSquare)) {
            std::cout << "Black Knight can attack the white King!\n";
            return true;
        }
        blackKnights &= blackKnights - 1;
    }
    std::cout << "No black Knight checks detected\n";
    return false; 
}

bool King::isWhiteKingInCheck(Chessboard &board) {
    int kingSquare = __builtin_ffsll(board.whiteKing) - 1;
    std::cout << "KingSquare: " << kingSquare << "\n";
    return isSquareInWhiteCheck(board, kingSquare);
}

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
    if(isSquareInWhiteCheck(board, endSquare)) return false;
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