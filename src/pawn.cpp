#include "Pawn.h"
#include <iostream>

void Pawn::moveWhitePawn(Chessboard &board, int startSquare, int endSquare) {
    Bitboard from = (1ULL << startSquare); // sets the bit to the correct from square
    Bitboard to = (1ULL << endSquare); // sets the bit to the correct to square
    if (isWhitePawnMoveLegal(board, startSquare, endSquare)) {
        if (board.whitePawns & from) { // checks if a white pawn is on the from square
            from = ~from; // reverses from in order to remove the bit after
            board.whitePawns &= from; // AND operation to remove the bit from the from square
            board.whitePawns |= to; // OR operation to add the bit to the to square
        } else {
            std::cout << "No white pawn found!\n";
        }
    } else {
        std::cout << "This move is unfortunately not legal :(\n";
    }
}

bool Pawn::isWhitePawnMoveLegal(Chessboard &board, int startSquare, int endSquare) {
    Bitboard tmp = (1ULL << (startSquare + 8)); // Square ahead
    Bitboard captureLeft = (1ULL << (startSquare + 9)); // Capture left
    Bitboard captureRight = (1ULL << (startSquare + 7)); // Capture right
    int distance = endSquare - startSquare;

    if (distance == 8) {
        if (!board.checkIfPieceIsOnSquare(tmp)) {
            return true; // Single square move
        }
        return false;
    } else if (distance == 16) {
        if (!board.checkIfPieceIsOnSquare(tmp) && !board.checkIfPieceIsOnSquare(tmp << 8)) {
            return true; // Double square move
        }
        return false;
    } else if (distance == 7 || distance == 9) {
        // Capture moves
        if (board.checkIfBlackPieceIsOnSquare(captureLeft) || board.checkIfBlackPieceIsOnSquare(captureRight)) {
            return true; // Capture
        }
    }
    
    return false; // Invalid move
}

bool Pawn::checkForWhiteEnPassant(Chessboard &board, int startSquare, int endSquare) {
    if(startSquare > 7 && startSquare < 16) {
        Bitboard enPassantLeft = (1ULL << (endSquare + 1));
        Bitboard enPassantRight = (1ULL << (endSquare - 1));
        if(board.checkIfBlackPawnIsOnSquare(enPassantLeft) || board.checkIfBlackPawnIsOnSquare(enPassantRight)) {
            return true;
        }
    } else {
        return false;
    }
    return false;
}
