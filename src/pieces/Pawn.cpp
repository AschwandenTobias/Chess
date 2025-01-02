#include "pawn.h"
#include <iostream>
#include "../game.h"
#include "King.h"
#include "../move.h"
#include "../piece.h"


//Function that checks if a pawn move is legal
//Doesnt take promotions into account (check that on the game level). Doesnt check (for now) for en passant.
bool Pawn::isPawnMoveLegal(Chessboard &board, Move move, bool white) {
    Bitboard emptySquares = ~(board.whitePieces | board.blackPieces);
    //board.printBitboard(emptySquares);
    //board.printBitboard(board.whitePieces);
    Bitboard startSquare = (1ULL << move.startSquare);
    Bitboard endBitboard = (1ULL << move.endSquare);
    Bitboard enemySquares = white ? board.blackPieces : board.whitePieces;
    int direction = white ? 1 : -1;
    int startRow = move.startSquare / 8;
    int startCol = move.startSquare % 8;
    int endCol = move.endSquare % 8;
    //std::cout << "StartSquare: " << move.startSquare << " , endSquare: " << move.endSquare << "\n";
    //std::cout << "Direction: " << direction << "\n";
    //std::cout << "StartCol: " << startCol << ", endCol: " << endCol << "\n";
    //board.printBitboard(endBitboard);
    //board.printBitboard(enemySquares);
    if(move.startSquare < 0 || move.startSquare > 63 || move.endSquare < 0 || move.endSquare > 63) return false;
    if(!board.checkIfWhitePawnIsOnSquare(startSquare)) return false;
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
        //std::cout << "Move is either a normal capture or en passant \n";
        if(enemySquares & endBitboard) { //normal Capture
            //std::cout << "Capture detected\n";
            if(King::doesTmpMovePutMeInCheck(board, move.startSquare, move.endSquare, white)) return false;
            return true;
        }
        if (board.lastMoveWasTwoSquarePawnMove && (move.startSquare / 8 == (white ? 4 : 5)) &&
            std::abs(endCol - startCol) == 1) { 
            //std::cout << "enPassant detected\n";
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


    for (int i = 0; i < numberOfPawns; i++) {
        int pawnSquare = __builtin_ffsll(pawns) - 1;
        for (int j = 0; j < 4; j++) {
            int targetSquare = pawnSquare + possiblePawnMoves[j];
            if(white) {
                Move pawnMove(pawnSquare, targetSquare, Piece::WHITE_PAWN);
                if (isPawnMoveLegal(board, pawnMove, white)) {
                possibleMoves.emplace_back(pawnSquare, targetSquare);
                }
            } else {
                Move pawnMove(pawnSquare, targetSquare, Piece::BLACK_PAWN);
                if (isPawnMoveLegal(board, pawnMove, white)) {
                possibleMoves.emplace_back(pawnSquare, targetSquare);
                }
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
