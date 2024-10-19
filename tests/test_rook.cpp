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

}