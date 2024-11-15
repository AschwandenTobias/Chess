#include <gtest/gtest.h>
#include "chessboard.h"
#include "pieces/bishop.h"
#include "pieces/pawn.h"
#include "game.h"

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
    Bishop::moveBlackBishop(board, 61, 68);
    Bishop::moveBlackBishop(board, 61, 70);
    Pawn::moveBlackPawn(board, 54, 46);
    Bishop::moveBlackBishop(board, 61, 54);
    Bishop::moveBlackBishop(board, 54, 9);
    Bishop::moveBlackBishop(board, 9, 0);
    Bishop::moveBlackBishop(board, 0, 9);
    Bishop::moveBlackBishop(board, 9, 2);
    Bishop::moveBlackBishop(board, 2, 11);
    Bishop::moveBlackBishop(board, 11, 4);
    Bishop::moveBlackBishop(board, 4, -3);
    Bishop::moveBlackBishop(board, 4, -5);
    Bishop::moveBlackBishop(board, 4, 13);
    Bishop::moveBlackBishop(board, 13, 6);
    Bishop::moveBlackBishop(board, 6, 15);
    Bishop::moveBlackBishop(board, 15, 50);
    EXPECT_EQ(board.blackBishops, 0x0400000000008000);
}

TEST(BishopTest, TestBoardBoundaries) {
    Chessboard board;
    Pawn::moveBlackPawn(board, 54, 46);
    Bishop::moveBlackBishop(board, 61, 54);
    Bishop::moveBlackBishop(board, 54, 47);
    Bishop::moveBlackBishop(board, 47, 40);
    EXPECT_EQ(board.blackBishops, 0x0400800000000000);
}

TEST(BishopTest, getAllPossibleBishopMoves) {
    Game game;
    game.board.setAllPiecesToZero();
    game.board.whiteBishops = 0x0000001000000000;
    game.board.blackBishops = 0x0000000020000000;
    game.board.printBoard();
    std::vector<std::pair<int, int>> areMovesWhite = Bishop::getAllPossibleBishopMoves(game.board, true);
    std::vector<std::pair<int, int>> shouldMovesWhite = {{36, 43}, {36, 50}, {36, 57}, {36, 29}, {36, 45}, {36, 54}, {36, 63}, {36, 27}, {36, 18}, {36, 9}, {36, 0}};
    ASSERT_EQ(areMovesWhite, shouldMovesWhite);
}