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
    Bitboard to = 1ULL << endSquare;
    if(endSquare < 0 || endSquare > 63) return false;
    if(!(board.checkIfWhiteRookIsOnSquare(from))) {
        std::cout << "there was no rook on the startSquare\n";
        return false;
    } else {
        int distance = std::abs(endSquare - startSquare);
        std::cout << "Distance: " << distance << "\n";
        if (distance == 0) return false;
        if(distance < 8) {
            if(endSquare - startSquare < 0) {
                std::cout << "Rook move to the right detected\n";
                Bitboard tmp = 1ULL >> (startSquare - 1);
                for(int i = 0; i < distance; i++) {
                    if(board.checkIfPieceIsOnSquare(tmp)) return false;
                    tmp = tmp >> 1;
                }
            } else {
                std::cout << "Rook move to the left detected\n";
                Bitboard tmp = 1ULL << (startSquare + 1);
                for(int i = 0; i < distance; i++) {
                    if(board.checkIfPieceIsOnSquare(tmp)) return false;
                    tmp = tmp << 1;
                }
            }
        } else {
            if(endSquare - startSquare < 0) {
                std::cout << "Rook move down detected\n";
                Bitboard tmp = 1ULL >> (startSquare - 8);
                for(int i = 0; i < (distance/8) - 1; i++) {
                    if(board.checkIfPieceIsOnSquare(tmp)) return false;
                    tmp = tmp >> 8;
                }
            } else {
                std::cout << "Rook move up detected\n";
                Bitboard tmp = 1ULL << (startSquare + 8);
                for(int i = 0; i < (distance/8) - 1; i++) {
                    if(board.checkIfPieceIsOnSquare(tmp)) return false;
                    tmp = tmp << 8;
                }
            }
            
        }
        
    }
    return true;
}