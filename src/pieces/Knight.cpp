#include "knight.h"
#include <iostream>

std::vector<std::pair<int, int>> Knight::getAllPossibleKnightMoves(Chessboard &board, bool white) {
    std::vector<std::pair<int, int>> possibleMoves;
    int possibleKnightMoves[8] = {10, 17, 15, 6, -6, -15, -17, -10};
    Bitboard knights = white ? board.whiteKnights : board.blackKnights;
    int numberOfKnights = __builtin_popcountll(knights);
    auto isKnightMoveLegal = white ? &isWhiteKnightMoveLegal : &isBlackKnightMoveLegal;
    for(int i = 0; i < numberOfKnights; i++) {
        int knightSquare = __builtin_ffsll(knights) - 1;
        for(int j = 0; j < 8; j++) {
            int targetSquare = knightSquare + possibleKnightMoves[j];
            if(isKnightMoveLegal(board, knightSquare, targetSquare)) {
                possibleMoves.emplace_back(knightSquare, targetSquare);
            }
        }
        knights &= knights - 1;
    }
    return possibleMoves;
}

//this doesnt check if the move is legal, it just returns all attacking squares
std::vector<int> Knight::getAttackingSquares(Chessboard &board, int startSquare, int  endSquare) {
    std::vector<int> attackingSquares;
    attackingSquares.emplace_back(startSquare);
    return attackingSquares;
}

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
            //std::cout << "Illegal move\n";
            return false;
        } else {
            return true;
        }
    } else {    
        //std::cout << "Not a L-shape move\n";
        return false;
    }
}

void Knight::moveBlackKnight(Chessboard &board, int startSquare, int endSquare) {
    Bitboard from = (1ULL << startSquare);
    Bitboard to = (1ULL << endSquare);
    
    if(isBlackKnightMoveLegal(board, startSquare, endSquare)) {
        //std::cout << "Black Knight move was legal\n";
        if(board.checkIfWhitePieceIsOnSquare(endSquare)) {
            //std::cout << "White piece on endSquare. Capture it!\n";
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
    if(!board.checkIfBlackKnightIsOnSquare(from)) {
        //std::cout << "No Black Knight was on starting square\n";
        return false;
    }
    int startRow = startSquare / 8;
    int endRow = endSquare / 8;
    int startCol = startSquare % 8;
    int endCol =  endSquare % 8;
    //std::cout << "StartRow: " << startRow << ", EndRow: " << endRow << "\n";
    if(((std::abs(endRow - startRow) == 2) && (std::abs(endCol - startCol) == 1)) || ((std::abs(endRow - startRow) == 1) && (std::abs(endCol - startCol) == 2))) {
        if(board.checkIfBlackPieceIsOnSquare(to)) {
            //std::cout << "Illegal move\n";
            return false;
        } else {
            //std::cout << "Move is legal\n";
            return true;
        }
    } else {    
        //std::cout << "Not a L-shape move\n";
        return false;
    }
}