#include <gtest/gtest.h>
#include "chessboard.h"
#include "bishop.h"
#include "pawn.h"

TEST(BishopTest, WhiteCaptureChecks) {
    Chessboard board;
    EXPECT_EQ(board.whiteBishops, 0x0000000000000024);
    Bishop::moveWhiteBishop(board, 2, 16);
    Pawn::moveWhitePawn(board, 9, 17);
    Bishop::moveWhiteBishop(board, 2, 16);
    Bishop::moveWhiteBishop(board, 16, 9);
    Bishop::moveWhiteBishop(board, 9, 54);
    Bishop::moveWhiteBishop(board, 54, 63);
    Bishop::moveWhiteBishop(board, 63, 0);
    Bishop::moveWhiteBishop(board, 63, 54);
    Bishop::moveWhiteBishop(board, 54, 61);
    Pawn::moveWhitePawn(board, 14, 22);
    Bishop::moveWhiteBishop(board, 5, 14);
    Bishop::moveWhiteBishop(board, 14, 49);
    Bishop::moveWhiteBishop(board, 49, 56);
    Bishop::moveWhiteBishop(board, 56, 49);
    Bishop::moveWhiteBishop(board, 49, 58);
    Bishop::moveWhiteBishop(board, 58, 51);
    Bishop::moveWhiteBishop(board, 51, 60);
    Bishop::moveWhiteBishop(board, 60, 53);
    Bishop::moveWhiteBishop(board, 53, 62);
    Bishop::moveWhiteBishop(board, 62, 69);
    Bishop::moveWhiteBishop(board, 62, 61);
    Bishop::moveWhiteBishop(board, 62, 54);
    EXPECT_EQ(board.whiteBishops, 0x6000000000000000);

}

TEST(BishopTest, BlackCaptureChecks) {
    Chessboard board;
    EXPECT_EQ(board.blackBishops, 0x2400000000000000);

}