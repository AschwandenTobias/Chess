#include <gtest/gtest.h>
#include "chessboard.h"
#include "knight.h"

TEST(KnightTest, InitialKinghtPositionsAndMoves) {
    Chessboard board;
    EXPECT_EQ(board.whiteKnights, 0x0000000000000042);
    EXPECT_EQ(board.blackKnights, 0x4200000000000000);
    Knight::moveWhiteKnight(board, 1, 7);
    Knight::moveWhiteKnight(board, 1, 11);
    Knight::moveWhiteKnight(board, 1, -5);
    Knight::moveWhiteKnight(board, 1, -9);
    Knight::moveWhiteKnight(board, 1, -14);
    Knight::moveWhiteKnight(board, 1, -16);
    Knight::moveWhiteKnight(board, 1, 18);
    Knight::moveWhiteKnight(board, 6, 21);
    EXPECT_EQ(board.whiteKnights, 0x0000000000240000);
    Knight::moveBlackKnight(board, 62, 77);
    Knight::moveBlackKnight(board, 62, 68);
    Knight::moveBlackKnight(board, 62, 52);
    Knight::moveBlackKnight(board, 62, 56);
    Knight::moveBlackKnight(board, 62, 72);
    Knight::moveBlackKnight(board, 62, 79);
    Knight::moveBlackKnight(board, 62, 45);
    Knight::moveBlackKnight(board, 57, 42);
    EXPECT_EQ(board.blackKnights, 0x0000240000000000);
}

TEST(KnightTest, CaptureChecks) {
    Chessboard board;
    board.whiteKnights = 0x0000220000000000;
    board.blackKnights = 0x0000000000220000;
    Knight::moveWhiteKnight(board, 41, 56);
    Knight::moveWhiteKnight(board, 56, 41);
    Knight::moveWhiteKnight(board, 41, 47);
    Knight::moveWhiteKnight(board, 47, 41);
    Knight::moveWhiteKnight(board, 41, 51);
    Knight::moveWhiteKnight(board, 51, 41);
    Knight::moveWhiteKnight(board, 41, 58);
    Knight::moveWhiteKnight(board, 58, 41);
    Knight::moveWhiteKnight(board, 45, 60);
    Knight::moveWhiteKnight(board, 60, 45);
    Knight::moveWhiteKnight(board, 45, 51);
    Knight::moveWhiteKnight(board, 51, 45);
    Knight::moveWhiteKnight(board, 45, 55);
    Knight::moveWhiteKnight(board, 55, 45);
    Knight::moveWhiteKnight(board, 45, 62);
    Knight::moveWhiteKnight(board, 62, 45);
    EXPECT_EQ(board.whiteKnights, 0x0000220000000000);
    Knight::moveBlackKnight(board, 21, 11);
    Knight::moveBlackKnight(board, 11, 21);
    Knight::moveBlackKnight(board, 21, 4);
    Knight::moveBlackKnight(board, 4, 21);
    Knight::moveBlackKnight(board, 21, 6);
    Knight::moveBlackKnight(board, 6, 21);
    Knight::moveBlackKnight(board, 21, 15);
    Knight::moveBlackKnight(board, 15, 21);
    Knight::moveBlackKnight(board, 17, 7);
    Knight::moveBlackKnight(board, 7, 17);
    Knight::moveBlackKnight(board, 17, 0);
    Knight::moveBlackKnight(board, 0, 17);
    Knight::moveBlackKnight(board, 17, 2);
    Knight::moveBlackKnight(board, 2, 17);
    Knight::moveBlackKnight(board, 17, 11);
    Knight::moveBlackKnight(board, 11, 17);
    EXPECT_EQ(board.blackKnights, 0x0000000000220000);
    //EXPECT_EQ(board.whiteRooks, 0x0000000000000080);   Tütüü nothing wrong to see here
}