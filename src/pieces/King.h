#ifndef KING_H
#define KING_H
#include "../chessboard.h"
#include <vector>

typedef uint64_t Bitboard;
class King {
public:
    static std::vector<std::pair<int, int>> generateAllPossibleKingMoves(Chessboard &board, bool white);
    static void moveWhiteKing(Chessboard &board, int startSquare, int endSquare);
    static bool isWhiteKingMoveLegal(Chessboard &board, int startSquare, int endSquare);
    static void moveBlackKing(Chessboard &board, int startSquare, int endSquare);
    static bool isBlackKingMoveLegal(Chessboard &board, int startSquare, int endSquare);
    static bool isSquareInWhiteCheck(Chessboard & board, int square);
    static bool isWhiteKingInCheck(Chessboard &board);
    static bool checkBlackBishopMovesForCheck(Chessboard &board, int startSquare);
    static bool checkBlackKnightMovesForCheck(Chessboard &board, int startSquare);
    static bool checkBlackRookMovesForCheck(Chessboard &board, int startSquare);
    static bool checkBlackQueenMovesForCheck(Chessboard &board, int startSquare);
    static bool checkBlackPawnMovesForCheck(Chessboard &board, int startSquare);
    static bool isSquareInBlackCheck(Chessboard & board, int square);
    static bool isBlackKingInCheck(Chessboard &board);
    static bool checkWhiteBishopMovesForCheck(Chessboard &board, int startSquare);
    static bool checkWhiteKnightMovesForCheck(Chessboard &board, int startSquare);
    static bool checkWhiteRookMovesForCheck(Chessboard &board, int startSquare);
    static bool checkWhiteQueenMovesForCheck(Chessboard &board, int startSquare);
    static bool checkWhitePawnMovesForCheck(Chessboard &board, int startSquare);
    static void castleWhiteKing(Chessboard &board, int startSquare, int endSquare);
    static bool isWhiteKingCastlingLegal(Chessboard &board);
    static bool isWhiteQueenCastlingLegal(Chessboard &board);
    static void castleBlackKing(Chessboard &board, int startSquare, int endSquare);
    static bool isBlackKingCastlingLegal(Chessboard &board);
    static bool isBlackQueenCastlingLegal(Chessboard &board);
    static bool isWhiteKingMoveNextToEnemyKing(Chessboard &board, int startSquare, int endSquare);
    static bool isBlackKingMoveNextToEnemyKing(Chessboard &board, int startSquare, int endSquare);
    static std::vector<int> getAttackingSquares(Chessboard &board, int kingSquare, bool white);
    static int numberOfAttackingPieces(Chessboard &board, int square, bool white);
    static bool canPieceInterfereCheck(Chessboard &board, bool white);
    static bool doesTmpMovePutMeInCheck(Chessboard &board, int startSquare, int endSquare, bool white);
    static std::vector<std::pair<int, int>> getAllPossibleKingMoves(Chessboard &board, bool white);

};

#endif