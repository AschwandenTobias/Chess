#include <gtest/gtest.h>
#include "chessboard.h"
#include "rook.h"
#include "pawn.h"

TEST(RookTest, AllDirectionRookMoves) {
    Chessboard board;
    Rook::moveWhiteRook(board, 0, 1);
    Rook::moveWhiteRook(board, 0, 8);
    Pawn::moveWhitePawn(board, 8, 24);
    EXPECT_EQ(board.whiteRooks, 0x0000000000000081);
    Rook::moveWhiteRook(board, 0, 16);
    EXPECT_EQ(board.whiteRooks, 0x0000000000010080);
    Rook::moveWhiteRook(board, 16, 17);
    Rook::moveWhiteRook(board, 17, 49);
    EXPECT_EQ(board.whiteRooks, 0x0002000000000080);
    Rook::moveWhiteRook(board, 49, 50);
    Rook::moveWhiteRook(board, 50, 48);
    Rook::moveWhiteRook(board, 48, 24);
    Rook::moveWhiteRook(board, 48, 56);
    Rook::moveWhiteRook(board, 56, 57);
    Rook::moveWhiteRook(board, 57, 9);
    EXPECT_EQ(board.whiteRooks, 0x0200000000000080);
    Rook::moveWhiteRook(board, 57, 25);
    Rook::moveWhiteRook(board, 25, 24);
    Rook::moveWhiteRook(board, 25, 28);
    Rook::moveWhiteRook(board, 28, 52);
    Rook::moveWhiteRook(board, 52, 53);
    Rook::moveWhiteRook(board, 53, 54);
    Rook::moveWhiteRook(board, 54, 55);
    Rook::moveWhiteRook(board, 55, 63);
    Rook::moveWhiteRook(board, 63, 62);
    Rook::moveWhiteRook(board, 62, 61);
    EXPECT_EQ(board.whiteRooks, 0x2000000000000080);

}