#include "bishop.h"
#include <iostream>
#include <vector>

//this doesnt check if the move is legal, it just returns all attacking squares
std::vector<int> Bishop::getAttackingSquares(Chessboard &board, int startSquare, int  endSquare) {
    std::vector<int> attackingSquares;
    int distance = std::abs(endSquare - startSquare);
    int direction = 0;
    int tmpSquare = startSquare;
        if(distance % 7 == 0) {
            direction = (endSquare > startSquare) ? 7 : -7;
        } else if(distance % 9 == 0) {
            direction = (endSquare > startSquare) ? 9 : -9;
        } else {
            return attackingSquares;
        }
        while(tmpSquare != endSquare) {
            attackingSquares.emplace_back(tmpSquare);
            tmpSquare += direction;
        }
    return attackingSquares;
}


void Bishop::moveWhiteBishop(Chessboard &board, int startSquare, int endSquare) {
    Bitboard from = 1ULL << startSquare;
    Bitboard to = 1ULL << endSquare;
    if(isWhiteBishopMoveLegal(board, startSquare, endSquare)) {
        board.updateLastMove(startSquare, endSquare);
        if(board.checkIfBlackPieceIsOnSquare(endSquare)) {
            board.deletePiece(to);
        }
        from = ~from;
        board.whiteBishops &= from;
        board.whiteBishops |= to;
    }
}

bool Bishop::isWhiteBishopMoveLegal(Chessboard &board, int startSquare, int endSquare) {
    if(endSquare < 0 || endSquare > 63) return false;
    Bitboard from = 1ULL << startSquare;
    Bitboard to = 1ULL << endSquare;
    if(!(board.checkIfWhiteBishopIsOnSquare(from))) return false;
    int distance = std::abs(endSquare - startSquare);
    //std::cout << "Distance: " << distance << "\n";
    if((distance % 7 != 0) && (distance % 9 != 0)) return false;
    if(distance % 7 == 0 || distance % 9 == 0) {
        if(checkDiagonalMoves(board, startSquare, endSquare)) {
            if(board.checkIfWhitePieceIsOnSquare(to)) {
                return false;
            } else if(board.checkIfBlackPieceIsOnSquare(to)) {
                return true;
            }
        } else {
            std::cout << "Piece in the way detected \n";
            return false;
        }
    }
    return true;
}

void Bishop::moveBlackBishop(Chessboard &board, int startSquare, int endSquare) {
    Bitboard from = 1ULL << startSquare;
    Bitboard to = 1ULL << endSquare;
    if(isBlackBishopMoveLegal(board, startSquare, endSquare)) {
        board.updateLastMove(startSquare, endSquare);
        if(board.checkIfWhitePieceIsOnSquare(endSquare)) {
            board.deletePiece(to);
        }
        from = ~from;
        board.blackBishops &= from;
        board.blackBishops |= to;
    }
}

bool Bishop::isBlackBishopMoveLegal(Chessboard &board, int startSquare, int endSquare) {
    if(endSquare < 0 || endSquare > 63) return false;
    Bitboard from = 1ULL << startSquare;
    Bitboard to = 1ULL << endSquare;
    if(!(board.checkIfBlackBishopIsOnSquare(from))) return false;
    int distance = std::abs(endSquare - startSquare);
    //std::cout << "Distance: " << distance << "\n";
    if((distance % 7 != 0) && (distance % 9 != 0)) return false;
    if(distance % 7 == 0 || distance % 9 == 0) {
        if(checkDiagonalMoves(board, startSquare, endSquare)) {
            if(board.checkIfBlackPieceIsOnSquare(to)) {
                return false;
            } else if(board.checkIfWhitePieceIsOnSquare(to)) {
                return true;
            }
        } else {
            //std::cout << "Piece in the way detected \n";
            return false;
        }
    }
    return true;
}

bool Bishop::checkDiagonalMoves(Chessboard &board, int startSquare, int endSquare) {
    int direction = 0;
    if(std::abs(endSquare - startSquare) % 7 == 0) {
        direction = (endSquare > startSquare) ? 7 : -7;
    } else {
        direction = (endSquare > startSquare) ? 9 : -9;
    }
    if(std::abs(endSquare - startSquare) == 7 || std::abs(endSquare - startSquare) == 9) {
        int startRow = startSquare % 8;
        int endRow = endSquare % 8;
        if(std::abs(endRow - startRow) != 1) return false;
    }
    
    //std::cout << "Direction: " << direction << "\n";
    Bitboard tmp = 1ULL << (startSquare + direction);
    for(int i = startSquare + direction; i != endSquare; i += direction) {
        //std::cout << "Bishop::Check following square: i: " << i << "\n";
        int currentRow = i % 8;
        int nextRow = (i + direction) % 8;
        //std::cout << "Bishop::CurrentRow: " << currentRow << ", nextRow: " << nextRow << "\n";
        if (std::abs(nextRow - currentRow) != 1) {
            //std::cout << "Stepping over board boundaries detected\n";
            return false; 
        }
        if(board.checkIfPieceIsOnSquare(tmp)) return false;
        tmp = (direction > 0) ? tmp << std::abs(direction) : tmp >> std::abs(direction);
    }
    return true;
}
