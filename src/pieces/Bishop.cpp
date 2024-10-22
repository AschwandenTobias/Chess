#include "bishop.h"
#include <iostream>

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
    std::cout << "Distance: " << distance << "\n";
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
    //std::cout << "Direction: " << direction << "\n";
    Bitboard tmp = 1ULL << (startSquare + direction);
    for(int i = startSquare + direction; i != endSquare; i += direction) {
        //std::cout << "i: " << i << "\n";
        if(board.checkIfPieceIsOnSquare(tmp)) return false;
        tmp = (direction > 0) ? tmp << std::abs(direction) : tmp >> std::abs(direction);
    }
    return true;
}
