#include <gtest/gtest.h>
#include "chessboard.h"
#include "pieces/King.h"
#include "pieces/Pawn.h"
#include "game.h"

TEST(KingTest, TestWhiteKingMovements) {
    Chessboard board;
    King::moveWhiteKing(board, 3, 2);
    King::moveWhiteKing(board, 3, -5);
    King::moveWhiteKing(board, 3, 4);
    King::moveWhiteKing(board, 3, 11);
    King::moveWhiteKing(board, 3, 12);
    King::moveWhiteKing(board, 3, 10);
    ASSERT_EQ(board.whiteKing, 0x0000000000000008);
    Pawn::moveWhitePawn(board, 11, 19);
    King::moveWhiteKing(board, 3, 11);
    King::moveWhiteKing(board, 11, 18);
    King::moveWhiteKing(board, 18, 26);
    Pawn::moveBlackPawn(board, 50, 34);
    King::moveWhiteKing(board, 26, 34);
    ASSERT_EQ(board.whiteKing, 0x0000000400000000);
    King::moveWhiteKing(board, 34, 42);
    ASSERT_EQ(board.whiteKing, 0x0000000400000000);
}

/*TEST(KingTest, FoolsMate) {
    Game game;
        std::vector<std::string> moves = {
        "f2f3", "e7e5", "g2g4", "d8h4"
    };
    game.start(moves);

}*/