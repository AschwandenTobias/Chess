#include <gtest/gtest.h>
#include "chessboard.h"
#include "pieces/rook.h"
#include "pieces/pawn.h"
#include "game.h"

TEST(RookTest, AllDirectionWhiteRookMoves) {
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

TEST(RookTest, AllDirectionBlackRookMoves) {
    Chessboard board;
    Rook::moveBlackRook(board, 63, 62);
    Rook::moveBlackRook(board, 63, 64);
    Pawn::moveBlackPawn(board, 55, 39);
    EXPECT_EQ(board.blackRooks, 0x8100000000000000);
    Rook::moveBlackRook(board, 63, 47);
    Rook::moveBlackRook(board, 47, 46);
    Rook::moveBlackRook(board, 46, 14);
    Rook::moveBlackRook(board, 14, 13);
    Rook::moveBlackRook(board, 13, 12);
    Rook::moveBlackRook(board, 12, 15);
    Rook::moveBlackRook(board, 15, 39);
    Rook::moveBlackRook(board, 15, 7);
    Rook::moveBlackRook(board, 7, 6);
    Rook::moveBlackRook(board, 6, 5);    
    EXPECT_EQ(board.blackRooks, 0x0100000000000020);
}

TEST(RookTest, getAllPossibleRookMoves) {
    Game game;
    game.board.setAllPiecesToZero();
    game.board.whiteRooks = 0x0000000010000000;
    game.board.blackRooks = 0x0000001000000000;
    game.board.printBoard();
    std::vector<std::pair<int, int>> areMovesWhite = Rook::getAllPossibleRookMoves(game.board, true);
    std::vector<std::pair<int, int>> shouldMovesWhite = {{28, 36}, {28, 20}, {28, 12}, {28, 4}, {28, 29}, {28, 30}, {28, 31}, {28, 27}, {28, 26}, {28, 25}, {28, 24}};
    ASSERT_EQ(areMovesWhite, shouldMovesWhite);
    std::vector<std::pair<int, int>> areMovesBlack = Rook::getAllPossibleRookMoves(game.board, false);
    std::vector<std::pair<int, int>> shouldMovesBlack = {{36, 44}, {36, 52}, {36, 60}, {36, 28}, {36, 37}, {36, 38}, {36, 39}, {36, 35}, {36, 34}, {36, 33}, {36, 32}};
    ASSERT_EQ(areMovesBlack, shouldMovesBlack);
}