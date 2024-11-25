#include "pawn.h"
#include <iostream>
#include "../game.h"
#include "King.h"


//Function that checks if a pawn move is legal
//Doesnt take promotions into account (check that on the game level). Doesnt check (for now) for en passant.
bool Pawn::isPawnMoveLegal(Chessboard &board, Move move, bool white) {
    Bitboard emptySquares = ~(board.whitePieces | board.blackPieces);
    //board.printBitboard(emptySquares);
    //board.printBitboard(board.whitePieces);
    Bitboard endBitboard = (1ULL << move.endSquare);
    board.printBitboard(endBitboard);
    Bitboard enemySquares = white ? board.blackPieces : board.whitePieces;
    int direction = white ? 1 : -1;
    int startRow = move.startSquare / 8;
    int startCol = move.startSquare % 8;
    int endCol = move.endSquare % 8;
    std::cout << "StartSquare: " << move.startSquare << " , endSquare: " << move.endSquare << "\n";
    std::cout << "Direction: " << direction << "\n";
    if(move.startSquare < 0 || move.startSquare > 63 || move.endSquare < 0 || move.endSquare > 63) return false;
    if(move.endSquare == move.startSquare + (8 * direction) && (emptySquares & endBitboard)) {
        //std::cout << "Standart Pawn move detected\n";
        if(King::doesTmpMovePutMeInCheck(board, move.startSquare, move.endSquare, white)) return false;
        //std::cout << "Move doesnt put me in check\n";
        return true;
    }
    if(white ? startRow == 1 : startRow == 6) {
        if (move.endSquare == move.startSquare + (16 * direction)) {
            //std::cout << "Double Pawn move detected\n";
            Bitboard pushMask = (1ULL << (move.startSquare + 8 * direction)) | endBitboard;
            //board.printBitboard(pushMask);
            if ((emptySquares & pushMask) == pushMask) { //Both squares must be empty for a double move
                //std::cout << "Both squares in front are empty\n";
                if (King::doesTmpMovePutMeInCheck(board, move.startSquare, move.endSquare, white)) return false;
                return true;
            }
        }   
    }
    if((move.endSquare == move.startSquare + (7 * direction) && std::abs(endCol - startCol) == 1)  || (move.endSquare == move.startSquare + (9 * direction) && std::abs(endCol - startCol) == 1)) {
        if(enemySquares & endBitboard) { //normal Capture
            if(King::doesTmpMovePutMeInCheck(board, move.startSquare, move.endSquare, white)) return false;
            return true;
        }
        if (board.lastMoveWasTwoSquarePawnMove && (move.startSquare / 8 == (white ? 3 : 4)) &&
            std::abs(endCol - startCol) == 1) {
            int targetSquare = move.endSquare - (8 * direction); //Targeted pawn square
            Bitboard targetPawn = 1ULL << targetSquare;
            Bitboard enemyPawnBitboard = white ? board.blackPieces : board.whitePieces;

            if (enemyPawnBitboard & targetPawn) { //Check if there's an opponent's pawn on the target square
                if (King::doesTmpMovePutMeInCheck(board, move.startSquare, move.endSquare, white)) return false;
                return true;
            }
        }
    }
    return false;
}

//Refactor this. Its probably fine actually
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


//Refactor this. Might be fine too
std::vector<int> Pawn::getAttackingSquares(Chessboard &board, int startSquare, int  endSquare) {
    std::vector<int> attackingSquares;
    attackingSquares.emplace_back(startSquare);
    return attackingSquares;
}

//Refactor this. Might be fine too
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

//Refactor this. Might be fine too
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
    if(King::doesTmpMovePutMeInCheck(board, startSquare, endSquare, false)) return false;
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
    //std::cout << "Before the check if this white pawn move would put me in check\n";
    if(King::doesTmpMovePutMeInCheck(board, startSquare, endSquare, true)) {
        //std::cout << "This white pawn move would put me in check\n";
        return false;
    } 
    //std::cout << "Tmp white move from: " << startSquare << ", to: " << endSquare << " doesnt put me into check\n";
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