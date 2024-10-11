#include "pawn.h"
#include <iostream>


void Pawn::moveBlackPawn(Chessboard &board, int startSquare, int endSquare) {
    Bitboard from = (1ULL << startSquare); // sets the bit to the correct from square
    Bitboard to = (1ULL << endSquare); // sets the bit to the correct to square
    if (isBlackPawnMoveLegal(board, startSquare, endSquare)) {
        if (board.blackPawns & from) { // checks if a white pawn is on the from square
            from = ~from; // reverses from in order to remove the bit after
            board.blackPawns &= from; // AND operation to remove the bit from the from square
            board.blackPawns |= to; // OR operation to add the bit to the to square

            board.updateLastMove(startSquare, endSquare);

            if(board.checkIfBlackPieceIsOnSquare(endSquare)) {
                board.deletePiece(endSquare);
            } else if (startSquare - endSquare == 7) {
                board.deletePiece(startSquare - 1);
            } else if (startSquare - endSquare == 9) {
                board.deletePiece(startSquare + 1);
            }

            board.lastMoveWasTwoSquarePawnMove = (startSquare - endSquare == 16);

        } else {
            std::cout << "No black pawn found!\n";
        }
    } else {
        std::cout << "This move is unfortunately not legal :(\n";
    }
}


bool Pawn::isBlackPawnMoveLegal(Chessboard &board, int startSquare, int endSquare) {
    Bitboard tmp = (1ULL << (startSquare - 8)); // Square ahead
    Bitboard captureLeft = (1ULL << (startSquare - 9)); // Capture left
    Bitboard captureRight = (1ULL << (startSquare - 7)); // Capture right
    int distance = startSquare - endSquare;
    //std::cout << distance <<"\n";
    if (distance == 8) {
        if (!board.checkIfPieceIsOnSquare(tmp)) {
            return true; // Single square move
        }
        return false;
    } else if (distance == 16) {
        if (!board.checkIfPieceIsOnSquare(tmp) && !board.checkIfPieceIsOnSquare(tmp >> 8)) {
            return true; // Double square move
        }
        return false;
    } else if (distance == 7) {
        // Capture moves
        if (board.checkIfWhitePieceIsOnSquare(captureRight)) {
            return true; // Capture
        } else if(checkForBlackEnPassant(board, startSquare, endSquare)){
            return true;
        }
    } else if (distance == 9) {
        if (board.checkIfWhitePieceIsOnSquare(captureLeft)) {
            return true; // Capture
        } else if(checkForBlackEnPassant(board, startSquare, endSquare)) { //TODO: Delete enemy pawn
            return true; // En Passant
        }
    }    
    return false; // Invalid move
}

bool Pawn::checkForBlackEnPassant(Chessboard &board, int startSquare, int endSquare) {
    //std::cout << "Landed in the checkForBlackEnPassant\n" << "startSquare: " << startSquare << ", endSquare: " << endSquare <<"\n";
    if(board.lastMoveWasTwoSquarePawnMove) {
        Bitboard enPassantLeft = (1ULL << (startSquare - 1));
        Bitboard enPassantRight = (1ULL << (startSquare + 1));
        if(board.checkIfWhitePawnIsOnSquare(enPassantLeft) || board.checkIfWhitePawnIsOnSquare(enPassantRight)) {
            std::cout << "EnPassant possible and White Pawn is there\n";
            return true;
        } else {
            return false;
        }
    }
    return false;
}

void Pawn::moveWhitePawn(Chessboard &board, int startSquare, int endSquare) {
    Bitboard from = (1ULL << startSquare); // sets the bit to the correct from square
    Bitboard to = (1ULL << endSquare); // sets the bit to the correct to square
    if (isWhitePawnMoveLegal(board, startSquare, endSquare)) {
        if (board.whitePawns & from) { // checks if a white pawn is on the from square
            from = ~from; // reverses from in order to remove the bit after
            board.whitePawns &= from; // AND operation to remove the bit from the from square
            board.whitePawns |= to; // OR operation to add the bit to the to square

            board.updateLastMove(startSquare, endSquare);

            if(board.checkIfBlackPieceIsOnSquare(endSquare)) {
                board.deletePiece(endSquare);
            } else if (endSquare - startSquare == 7) {
                board.deletePiece(startSquare - 1);
            } else if (endSquare - startSquare == 9) {
                board.deletePiece(startSquare + 1);
            }

            board.lastMoveWasTwoSquarePawnMove = (endSquare - startSquare == 16);

        } else {
            std::cout << "No white pawn found!\n";
        }
    } else {
        std::cout << "This move is unfortunately not legal :(\n";
    }
}

//TODO: Delete enemy pieces
bool Pawn::isWhitePawnMoveLegal(Chessboard &board, int startSquare, int endSquare) {
    Bitboard tmp = (1ULL << (startSquare + 8)); // Square ahead
    Bitboard captureLeft = (1ULL << (startSquare + 9)); // Capture left
    Bitboard captureRight = (1ULL << (startSquare + 7)); // Capture right
    int distance = endSquare - startSquare;
    std::cout << distance <<"\n";
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
    } else if (distance == 7) {
        // Capture moves
        if (board.checkIfBlackPieceIsOnSquare(captureRight)) {
            return true; // Capture
        } else if(checkForWhiteEnPassant(board, startSquare, endSquare)){
            return true;
        }
    } else if (distance == 9) {
        if (board.checkIfBlackPieceIsOnSquare(captureLeft)) {
            return true; // Capture
        } else if(checkForWhiteEnPassant(board, startSquare, endSquare)) { //TODO: Delete enemy pawn
            return true; // En Passant
        }
    }    
    return false; // Invalid move
}

//TODO test if it works
bool Pawn::checkForWhiteEnPassant(Chessboard &board, int startSquare, int endSquare) {
    //std::cout << "Landed in the checkForWhiteEnPassant\n" << "startSquare: " << startSquare << ", endSquare: " << endSquare <<"\n";
    if(board.lastMoveWasTwoSquarePawnMove) {
        Bitboard enPassantLeft = (1ULL << (startSquare + 1));
        Bitboard enPassantRight = (1ULL << (startSquare - 1));
        if(board.checkIfBlackPawnIsOnSquare(enPassantLeft) || board.checkIfBlackPawnIsOnSquare(enPassantRight)) {
            //std::cout << "EnPassant possible and Black Pawn is there\n";
            return true;
        } else {
            return false;
        }
    }
    return false;
}