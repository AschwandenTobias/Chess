#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <cstdint>
#include <vector>
#include <bitset>
#include "move.h"

typedef uint64_t Bitboard;


class Chessboard {
public:

    
    
    Bitboard whitePawns;
    Bitboard whiteRooks;
    Bitboard whiteKnights;
    Bitboard whiteBishops;
    Bitboard whiteQueen;
    Bitboard whiteKing;
    Bitboard blackPawns;
    Bitboard blackRooks;
    Bitboard blackKnights;
    Bitboard blackBishops;
    Bitboard blackQueen;
    Bitboard blackKing;

    Bitboard occupiedSquares;
    Bitboard whitePieces;
    Bitboard blackPieces;
    Bitboard blackAttackingSquares;
    Bitboard whiteAttackingSquares;

    int lastMoveStartSquare;  
    int lastMoveEndSquare;    
    bool lastMoveWasTwoSquarePawnMove;

    int attackingPieceSquare;

    bool whiteQueenRookMoved;
    bool whiteKingRookMoved;
    bool blackQueenRookMoved;
    bool blackKingRookMoved;
    bool whiteKingMoved;
    bool blackKingMoved;


    Chessboard();
    void printBoard();
    void printBitboard(Bitboard board);
    //void makeMove(Move move);
    bool checkIfPieceIsOnSquare(Bitboard square);
    bool checkIfPieceIsOnSquare(int Square);
    bool checkIfWhitePieceIsOnSquare(Bitboard square);
    bool checkIfBlackPieceIsOnSquare(Bitboard square);
    bool checkIfBlackPawnIsOnSquare(Bitboard square);
    bool checkIfWhitePawnIsOnSquare(Bitboard square);
    void deletePiece(Bitboard square);
    void updateLastMove(int startsquare, int endsquare);
    bool checkIfBlackPieceIsOnSquare(int square);
    void deletePiece(int squareToDelete);
    bool checkIfWhitePieceIsOnSquare(int squareToDelete);
    bool checkIfWhiteRookIsOnSquare(Bitboard square);
    bool checkIfBlackRookIsOnSquare(Bitboard square);
    bool checkIfWhiteBishopIsOnSquare(Bitboard square);
    bool checkIfBlackBishopIsOnSquare(Bitboard square);
    bool checkIfWhiteQueenIsOnSquare(Bitboard square);
    bool checkIfBlackQueenIsOnSquare(Bitboard square);
    bool checkIfWhiteKnightIsOnSquare(Bitboard square);
    bool checkIfBlackKnightIsOnSquare(Bitboard square);
    bool checkIfWhiteKingIsOnSquare(Bitboard square);
    bool checkIfBlackKingIsOnSquare(Bitboard square);
    int getSquareOfKing(bool white);
    Piece getPieceAtSquare(int square);
    void reverseMove(int startSquare, int endSquare);
    void setPiece(int square, Piece piece);
    void setAllPiecesToZero();
    std::vector<std::pair<int, int>> generateAllPossibleMoves(bool white);
    void deleteWhitePiece(Bitboard square);
    void deleteBlackPiece(Bitboard square);
};

#endif 
