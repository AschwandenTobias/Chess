#include <gtest/gtest.h>
#include "chessboard.h"
#include "pawn.h"

TEST(ChessBoardTest, InitialPawnPositions) {
    Chessboard chessboard;
    EXPECT_EQ(chessboard.whitePawns, 0x000000000000FF00);
    EXPECT_EQ(chessboard.blackPawns, 0x00FF000000000000);
}

TEST(ChessBoardTest, InitialMovements) {
    Chessboard board;
    Pawn::moveWhitePawn(board, 8, 16);
    EXPECT_EQ(board.whitePawns, 0x000000000001FE00);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}