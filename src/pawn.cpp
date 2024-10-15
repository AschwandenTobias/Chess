#include "pawn.h"
#include <iostream>


void Pawn::moveBlackPawn(Chessboard &board, int startSquare, int endSquare) {
    Bitboard from = (1ULL << startSquare); // sets the bit to the correct from square
    Bitboard to = (1ULL << endSquare); // sets the bit to the correct to square
    if (isBlackPawnMoveLegal(board, startSquare, endSquare)) {
        //std::cout << "Move was legal, startSquare: " << startSquare << ", endSquare: " << endSquare <<"\n";
        if (board.blackPawns & from) { // checks if a black pawn is on the from square
            //std::cout << "BlackPawn is on startSquare\n";

            board.updateLastMove(startSquare, endSquare);
            if(board.checkIfWhitePieceIsOnSquare(endSquare)) {
                board.deletePiece(to);
            } else if (startSquare - endSquare == 7) {
                //::cout << "left Capture detected\n";
                int leftCaptureSquare = startSquare + 1;
                Bitboard leftCaptureBitboard = (1ULL << leftCaptureSquare);
                board.deletePiece(leftCaptureBitboard);
            } else if (startSquare - endSquare == 9) {
                //std::cout << "right Capture detected\n";
                int rightCaptureSquare = startSquare - 1;
                Bitboard rightCaptureBitboard = (1ULL << rightCaptureSquare);
                board.deletePiece(rightCaptureBitboard);
            }
            //std::cout << "blackPawns before move: " << board.blackPawns << "\n";
            from = ~from; // reverses from in order to remove the bit after
            board.blackPawns &= from; // AND operation to remove the bit from the from square
            board.blackPawns |= to; // OR operation to add the bit to the to square
            //std::cout << "blackPawns after move: " << board.blackPawns << "\n";
            board.lastMoveWasTwoSquarePawnMove = (startSquare - endSquare == 16);

        } else {
            //std::cout << "No black pawn found!\n";
        }
    } else {
        //std::cout << "This move is unfortunately not legal :(\n";
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
            //std::cout << "No piece on square detected\n";
            return true; // Single square move
        }
        return false;
    } else if (distance == 16) {
        if(startSquare > 47 && startSquare < 56 )
        if (!board.checkIfPieceIsOnSquare(tmp) && !board.checkIfPieceIsOnSquare(tmp >> 8)) {
            return true; // Double square move
        }
        return false;
    } else if (distance == 7) {
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
            //std::cout << "EnPassant possible and White Pawn is there\n";
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
        //std::cout << "Legal move returned true\n";
        if (board.whitePawns & from) { // checks if a white pawn is on the from square
            //std::cout << "White pawn on startSquare detected\n";
            
            board.updateLastMove(startSquare, endSquare);

            if(board.checkIfBlackPieceIsOnSquare(endSquare)) { //13.10 gave the method an int and not a bitboard
                //std::cout << "blackPiece on endSquare detected\n";
                board.deletePiece(to);
            } else if (endSquare - startSquare == 7) {
                int leftCaptureSquare = startSquare - 1;
                Bitboard leftCaptureBitboard = (1ULL << leftCaptureSquare);
                board.deletePiece(leftCaptureBitboard);
            } else if (endSquare - startSquare == 9) {
                int rightCaptureSquare = startSquare + 1;
                Bitboard rightCaptureBitboard = (1ULL << rightCaptureSquare);
                board.deletePiece(rightCaptureBitboard);
            }

            from = ~from; // reverses from in order to remove the bit after
            board.whitePawns &= from; // AND operation to remove the bit from the from square
            board.whitePawns |= to; // OR operation to add the bit to the to square


            board.lastMoveWasTwoSquarePawnMove = (endSquare - startSquare == 16);

        } else {
            //std::cout << "No white pawn found!\n";
        }
    } else {
        //std::cout << "This move is unfortunately not legal :(\n";
    }
}

//TODO: Delete enemy pieces
bool Pawn::isWhitePawnMoveLegal(Chessboard &board, int startSquare, int endSquare) {
    Bitboard tmp = (1ULL << (startSquare + 8)); // Square ahead
    Bitboard captureLeft = (1ULL << (startSquare + 9)); // Capture left
    Bitboard captureRight = (1ULL << (startSquare + 7)); // Capture right
    int distance = endSquare - startSquare;
    //std::cout << distance <<"\n";
    if (distance == 8) {
        if (!board.checkIfPieceIsOnSquare(tmp)) {
            return true; // Single square move
        }
        return false;
    } else if (distance == 16) {
        if(startSquare > 7 && startSquare < 16) {
            if (!board.checkIfPieceIsOnSquare(tmp) && !board.checkIfPieceIsOnSquare(tmp << 8)) {
                return true; // Double square move
            }
        }
        return false;
    } else if (distance == 7) {
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