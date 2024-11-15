#include "pawn.h"
#include <iostream>
#include "../game.h"

std::vector<std::pair<int, int>> Pawn::getAllPossiblePawnMoves(Chessboard &board, bool white) {
    std::vector<std::pair<int, int>> possibleMoves;
    Bitboard pawns = white ? board.whitePawns : board.blackPawns;
    int numberOfPawns = __builtin_popcountll(pawns);

    const int possiblePawnMovesWhite[4] = {8, 16, 7, 9};
    const int possiblePawnMovesBlack[4] = {-8, -16, -7, -9};
    const int* possiblePawnMoves = white ? possiblePawnMovesWhite : possiblePawnMovesBlack;

    auto isPawnMoveLegal = white ? &isWhitePawnMoveLegal : &isBlackPawnMoveLegal;

    for (int i = 0; i < numberOfPawns; i++) {
        int pawnSquare = __builtin_ffsll(pawns) - 1;
        for (int j = 0; j < 4; j++) {
            int targetSquare = pawnSquare + possiblePawnMoves[j];
            if (isPawnMoveLegal(board, pawnSquare, targetSquare)) {
                possibleMoves.emplace_back(pawnSquare, targetSquare);
            }
        }
        pawns &= pawns - 1;
    }

    return possibleMoves;
}


//Doesnt check for move legality.
std::vector<int> Pawn::getAttackingSquares(Chessboard &board, int startSquare, int  endSquare) {
    std::vector<int> attackingSquares;
    attackingSquares.emplace_back(startSquare);
    return attackingSquares;
}

bool Pawn::canAPawnMoveToSquare(Chessboard &board, int endSquare, bool white) {
    if(white) {
        Bitboard whitePawns = board.whitePawns;
        int numberOfWhitePawns = __builtin_popcountll(whitePawns);
        for(int i = 0; i < numberOfWhitePawns; i++) {
            int pawnSquare = __builtin_ffsll(whitePawns) - 1;
            if((pawnSquare < 16 && pawnSquare > 7 && pawnSquare + 16 == endSquare) || pawnSquare + 8 == endSquare) {
                if(board.checkIfPieceIsOnSquare(pawnSquare + 8)) return false;
                return true;
            }
            whitePawns &= whitePawns - 1;
        }  
    } else {
        Bitboard blackPawns = board.blackPawns;
        int numberOfBlackPawns = __builtin_popcountll(blackPawns);
        for(int i = 0; i < numberOfBlackPawns; i++) {
            int pawnSquare = __builtin_ffsll(blackPawns) - 1;
            if((pawnSquare < 56 && pawnSquare > 47 && pawnSquare - 16 == endSquare) || pawnSquare - 8 == endSquare) {
                if(board.checkIfPieceIsOnSquare(pawnSquare - 8)) return false;
                return true;
            }
            blackPawns &= blackPawns - 1;
        }  
    }
    return false;
}

bool Pawn::canPawnAttackSquare(Chessboard &board, int endSquare, bool white) {
    if(white) {
        Bitboard whitePawns = board.whitePawns;
        int numberOfWhitePawns = __builtin_popcountll(whitePawns);
        for(int i = 0; i < numberOfWhitePawns; i++) {
            int pawnSquare = __builtin_ffsll(whitePawns) - 1;
            if((endSquare - pawnSquare == 7 && pawnSquare % 8 != 0) || (endSquare - pawnSquare == 9 && pawnSquare % 8 != 7)) {
                std::cout << "Pawn at square: " << pawnSquare << " can attack piece at square: " << endSquare << "\n";
                return true;
            }
            whitePawns &= whitePawns - 1;
        }  
    } else {
        Bitboard blackPawns = board.blackPawns;
        int numberOfBlackPawns = __builtin_popcountll(blackPawns);
        for(int i = 0; i < numberOfBlackPawns; i++) {
            int pawnSquare = __builtin_ffsll(blackPawns) - 1;
            if((pawnSquare - endSquare == 7 && pawnSquare % 8 != 0) || (pawnSquare - endSquare == 9  && pawnSquare % 8 != 7)) {
                return true;
            }
            blackPawns &= blackPawns - 1;
        }  
    }
    return false;
}

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