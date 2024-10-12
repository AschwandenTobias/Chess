#include <gtest/gtest.h>
#include "chessboard.h"
#include "pawn.h"

TEST(ChessBoardTest, InitialPawnPositions) {
    Chessboard chessboard;
    EXPECT_EQ(chessboard.whitePawns, 0x000000000000FF00);
    EXPECT_EQ(chessboard.blackPawns, 0x00FF000000000000);
}

TEST(ChessBoardTest, InitialWhiteMovements) {
    Chessboard board;
    Pawn::moveWhitePawn(board, 8, 16);
    EXPECT_EQ(board.whitePawns, 0x000000000001FE00);
    board.whitePawns = 0x000000000000FF00;
    Pawn::moveWhitePawn(board, 9, 25);
    EXPECT_EQ(board.whitePawns, 0x000000000200FD00);
}

TEST(ChessBoardTest, OutOfBoundPawnMovements) {
    Chessboard board;
    Pawn::moveWhitePawn(board, -1, 7); //Negative move, shouldnt move anything
    Pawn::moveWhitePawn(board, 8, 64); //Movement out of chessboard bounds, shouldnt move anything
    EXPECT_EQ(board.whitePawns, 0x000000000000FF00);
}

TEST(ChessboardTest, BackwardMovement) {
    Chessboard board;
    Pawn::moveWhitePawn(board, 15, 7);
    EXPECT_EQ(board.whitePawns, 0x000000000000FF00);
    board.whitePawns = 0x0000000000FF0000; //Move pawns to third row
    Pawn::moveWhitePawn(board, 16, 8); //Try to move pawn backwards
    EXPECT_EQ(board.whitePawns, 0x0000000000FF0000);
}

TEST(ChessboardTest, TryTwoSquareMoveNotOnOriginalRow) {
    Chessboard board;
    board.whitePawns = 0x0000000000FF0000; //Move pawns to third row
    Pawn::moveWhitePawn(board, 20, 36);
    EXPECT_EQ(board.whitePawns, 0x0000000000FF0000);
}

TEST(ChessboardTest, TryMovingPawnsIntoOverPieces) {
    Chessboard board;
    board.whitePawns = 0x0000000000FF0000;
    board.whiteBishops = 0x0000000003000000;
    board.blackQueen = 0x0000000004000000;
    board.blackRooks = 0x0000000018000000;
    Pawn::moveWhitePawn(board, 16, 24);
    Pawn::moveWhitePawn(board, 17, 33);
    Pawn::moveWhitePawn(board, 18, 26);
    Pawn::moveWhitePawn(board, 18, 34);
    Pawn::moveWhitePawn(board, 19, 27);
    Pawn::moveWhitePawn(board, 19, 35);
    EXPECT_EQ(board.whitePawns, 0x0000000000FF0000);
}

TEST(ChessboardTest, TryCaptures) { //TODO:fix capture of pieces
    Chessboard board;
    board.whitePawns = 0x0000000000FF0000; //Move pawns to third row
    board.blackPawns = 0x00000000FF000000; //blackPawns on fourth row
    Pawn::moveWhitePawn(board, 16, 25);
    EXPECT_EQ(board.whitePawns, 0x0000000002FE0000);
    //EXPECT_EQ(board.blackPawns, 0x00000000FD000000);
}



int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

/*
TODO: 
-Try to capture own pieces
-Try en passant
*/