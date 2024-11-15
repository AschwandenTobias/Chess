#include <gtest/gtest.h>
#include "chessboard.h"
#include "pieces/queen.h"
#include "pieces/pawn.h"
#include "game.h"

//If fails it might be because of a check
TEST(QueenTest, WhiteQueenCaptures) { 
    Chessboard board;
    Queen::moveWhiteQueen(board, 4, 18);
    Pawn::moveWhitePawn(board, 11, 19);
    Queen::moveWhiteQueen(board, 4, 18);
    Queen::moveWhiteQueen(board, 18, 26);
    Queen::moveWhiteQueen(board, 26, 27);
    Queen::moveWhiteQueen(board, 27, 24);
    Queen::moveWhiteQueen(board, 24, 48);
    Queen::moveWhiteQueen(board, 48, 8);
    Queen::moveWhiteQueen(board, 48, 56);
    Queen::moveWhiteQueen(board, 56, 49);
    Queen::moveWhiteQueen(board, 49, 57);
    Queen::moveWhiteQueen(board, 57, 50);
    Queen::moveWhiteQueen(board, 50, 29);
    Queen::moveWhiteQueen(board, 29, 53);
    Queen::moveWhiteQueen(board, 53, 62);
    Queen::moveWhiteQueen(board, 62, 61);
    Queen::moveWhiteQueen(board, 61, 54);
    Queen::moveWhiteQueen(board, 54, 63);
    Queen::moveWhiteQueen(board, 63, 55);
    EXPECT_EQ(board.whiteQueen, 0x0080000000000000);
}

TEST(QueenTest, BlackQueenCaptures) { 
    Chessboard board;
   Queen::moveBlackQueen(board, 60, 68);
    Pawn::moveBlackPawn(board, 51, 43);
    Queen::moveBlackQueen(board, 60, 61);
    Queen::moveBlackQueen(board, 60, 24);
    Queen::moveBlackQueen(board, 24, 48);
    Queen::moveBlackQueen(board, 24, 8);
    Queen::moveBlackQueen(board, 8, 0);
    Queen::moveBlackQueen(board, 0, 9);

    EXPECT_EQ(board.blackQueen, 0x0000000000000200);
}

TEST(QueenTest, getAllPossibleQueenMoves) {
    Game game;
    Pawn::moveWhitePawn(game.board, 11, 27);
    Pawn::moveWhitePawn(game.board, 12, 28);
    std::vector<std::pair<int, int>> areMovesWhite = Queen::getAllPossibleQueenMoves(game.board, true);
    std::vector<std::pair<int, int>> shouldMovesWhite = {{4, 12}, {4, 20}, {4, 11}, {4, 18}, {4, 25}, {4, 32}};
    game.board.printBoard();
    ASSERT_EQ(areMovesWhite, shouldMovesWhite);
}