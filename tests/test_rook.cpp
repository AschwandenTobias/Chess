#include <gtest/gtest.h>
#include "chessboard.h"
#include "rook.h"

TEST(RookTest, AllDirectionRookMoves) {
    Chessboard board;
    board.whiteRooks = 0x0000000008000000;
    Rook::moveWhiteRook(board, 27, 26);
    EXPECT_EQ(board.whiteRooks, 0x0000000010000000);
}