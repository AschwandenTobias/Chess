#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <cstdint>

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

    int lastMoveStartSquare;  
    int lastMoveEndSquare;    
    bool lastMoveWasTwoSquarePawnMove;

    bool whiteQueenRookMoved;
    bool whiteKingRookMoved;
    bool blackQueenRookMoved;
    bool blackKingRookMoved;
    bool whiteKingMoved;
    bool blackKingMoved;
    enum Piece {
        EMPTY,
        WHITE_PAWN, WHITE_KNIGHT, WHITE_BISHOP, WHITE_ROOK, WHITE_QUEEN, WHITE_KING,
        BLACK_PAWN, BLACK_KNIGHT, BLACK_BISHOP, BLACK_ROOK, BLACK_QUEEN, BLACK_KING
    };

    Chessboard();
    void printBoard();
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
    Piece getPieceAtSquare(int square);
};

#endif 
