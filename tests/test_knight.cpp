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
    EXPECT_EQ(board.whiteKnights, 0x0000000000040040);

    


}

