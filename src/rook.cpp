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
        if((std::abs(endSquare - startSquare) % 8) == 0) {
            if(checkVerticalMoves(board, startSquare, endSquare)) {
                if(board.checkIfWhitePieceIsOnSquare(to)) {
                    std::cout << "White Piece on endSquare detected. Cant move :(\n";
                    return false;
                } else if(board.checkIfBlackPieceIsOnSquare(to)) {
                    std::cout << "Black Piece to capture on endSquare detected. Capture it!\n";
                    return true;
                }
            } else {
                return false;
            }
        } else {
            return checkHorizontalMoves(board, startSquare, endSquare);
        }
    }
    return true;
}

bool Rook::checkHorizontalMoves(Chessboard &board, int startSquare, int endSquare) {
    std::cout << "Horizontal move detected\n";
    //int distance = std::abs(endSquare - startSquare);
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
    if(endSquare > startSquare) {
        std::cout << "Rook moves up the board.\n";
        Bitboard tmp = 1ULL << (startSquare + 8);
        for(int i = 0; i < distance/8 - 1; i++) {
            if(board.checkIfPieceIsOnSquare(tmp)) {
                std::cout << "Piece detected\n";
                return false;
            }
            tmp = tmp << 8;
        }
    }
    if(endSquare < startSquare) {
        std::cout << "Rook moves down the board.\n";
        Bitboard tmp = 1ULL << (startSquare - 8);
        for(int i = 0; i < distance/8 - 1; i++) {
            if(board.checkIfPieceIsOnSquare(tmp)) {
                std::cout << "Piece detected\n";
                return false;
            }
            tmp = tmp >> 8;
        }
    }

    return true;
}