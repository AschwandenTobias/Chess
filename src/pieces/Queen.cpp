#include "queen.h"
#include "bishop.h"
#include "rook.h"
#include <iostream>

std::vector<std::pair<int, int>> Queen::getAllPossibleQueenMoves(Chessboard &board, bool white) {
    std::vector<std::pair<int, int>> possibleMoves;
    int queenDirections[8] = {8, -8, 1, -1, 7, -7, 9, -9};
    Bitboard queens = white ? board.whiteQueen : board.blackQueen;
    int numberOfQueens = __builtin_popcountll(queens);
    auto isQueenMoveLegal = white ? &isWhiteQueenMoveLegal : &isBlackQueenMoveLegal;
    for(int i = 0; i < numberOfQueens; i++) {
        int queenSquare = __builtin_ffsll(queens) - 1;
        for(int dir = 0; dir < 8; dir++) {
            for(int j = 0; j < 7; j++) {
                int targetSquare = queenSquare + queenDirections[dir] * (j + 1);
                if(isQueenMoveLegal(board, queenSquare, targetSquare)) {
                    possibleMoves.emplace_back(queenSquare, targetSquare);
                } else {
                    break;
                }
            }
        }
        queens &= queens - 1;
    }
    return possibleMoves;   
}


//this doesnt check if the move is legal, it just returns all attacking squares
std::vector<int> Queen::getAttackingSquares(Chessboard &board, int startSquare, int  endSquare) {
    std::vector<int> attackingSquares;
    int distance = std::abs(endSquare - startSquare);
    int direction = 0;
    int tmpSquare = startSquare;
    if(distance % 7 == 0) {
        direction = (endSquare > startSquare) ? 7 : -7;
    } else if(distance % 9 == 0) {
        direction = (endSquare > startSquare) ? 9 : -9;
    } else if(distance % 8 == 0) {
        direction = (endSquare > startSquare) ? 8 : -8;
    } else {
        direction = (endSquare > startSquare) ? 1 : -1;
    }
    while(tmpSquare != endSquare) {
        attackingSquares.emplace_back(tmpSquare);
        tmpSquare += direction;
    }
    return attackingSquares;
}

bool Queen::canQueenAttackSquare(Chessboard &board, int square, bool white) {
    if(white) {
        Bitboard tmp = board.whiteQueen;
        int numberOfQueens = __builtin_popcountll(tmp);
        for(int i = 0; i < numberOfQueens; i++) {
            int queenSquare = __builtin_ffsll(tmp) - 1;
            if(isWhiteQueenMoveLegal(board, queenSquare, square)) {
                return true;
            }
            tmp &= tmp - 1;
        }
    } else {
        Bitboard tmp = board.blackQueen;
        int numberOfQueens = __builtin_popcountll(tmp);
        for(int i = 0; i < numberOfQueens; i++) {
            int queenSquare = __builtin_ffsll(tmp) - 1;
            if(isBlackQueenMoveLegal(board, queenSquare, square)) {
                return true;
            }
            tmp &= tmp - 1;
        }
    }
    return false;
}

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
    //std::cout << "We detected a black Queen on the from square\n";
    if (board.checkIfBlackPieceIsOnSquare(to)) {
        std::cout << "Detected black Piece on endSquare\n";
        return false;
    }
    int distance = std::abs(endSquare - startSquare);
    //std::cout << "Tmp print for debug\n";
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