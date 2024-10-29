#include <iostream>
#include "king.h"
#include "Bishop.h"
#include "Knight.h"
#include "Rook.h"
#include "Queen.h"
#include "Pawn.h"

bool King::isSquareInWhiteCheck(Chessboard &board, int square) {
    if(checkBlackBishopMovesForCheck(board, square)) {
        return true;
    } else if (checkBlackKnightMovesForCheck(board, square)) {
        return true;
    } else if (checkBlackRookMovesForCheck(board, square)) {
        return true;
    } else if(checkBlackQueenMovesForCheck(board, square)) {
        return true;
    } else if (checkBlackPawnMovesForCheck(board, square)) {
        return true;
    }
    return false;
}

bool King::checkBlackPawnMovesForCheck(Chessboard &board, int startSquare) {
    Bitboard blackPawns = board.blackPawns;
    int numberOfBlackPawns = __builtin_popcountll(blackPawns);
    for(int i = 0; i < numberOfBlackPawns; i++) {
        int pawnSquare = __builtin_ffsll(blackPawns) - 1;
        if(Pawn::isBlackPawnMoveLegal(board, pawnSquare, startSquare)) {
            return true;
        }
        blackPawns &= blackPawns - 1;
    }
    return false; 
}

bool King::checkBlackQueenMovesForCheck(Chessboard &board, int startSquare) {
    Bitboard blackQueen = board.blackQueen;
    int numberOfBlackQueens = __builtin_popcountll(blackQueen);
    for(int i = 0; i < numberOfBlackQueens; i++) {
        int queenSquare = __builtin_ffsll(blackQueen) - 1;
        if(Queen::isBlackQueenMoveLegal(board, queenSquare, startSquare)) {
            return true;
        }
        blackQueen &= blackQueen - 1;
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
    Bitboard blackKnights = board.blackKnights;
    int numberOfBlackKnights = __builtin_popcountll(blackKnights);
    for(int i = 0; i < numberOfBlackKnights; i++) {
        int knightSquare = __builtin_ffsll(blackKnights) - 1;
        if(Knight::isBlackKnightMoveLegal(board, knightSquare, startSquare)) {
            return true;
        }
        blackKnights &= blackKnights - 1;
    }
    return false; 
}

bool King::checkBlackRookMovesForCheck(Chessboard &board, int startSquare) {
    Bitboard blackRooks = board.blackRooks;
    int numberOfBlackRooks = __builtin_popcountll(blackRooks);
    for(int i = 0; i < numberOfBlackRooks; i++) {
        int rookSquare = __builtin_ffsll(blackRooks) - 1;
        if(Rook::isBlackRookMoveLegal(board, rookSquare, startSquare)) {
            return true;
        }
        blackRooks &= blackRooks - 1;
    }
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