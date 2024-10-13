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

TEST(ChessBoardTest, WhiteOutOfBoundPawnMovements) {
    Chessboard board;
    Pawn::moveWhitePawn(board, -1, 7); //Negative move, shouldnt move anything
    Pawn::moveWhitePawn(board, 8, 64); //Movement out of chessboard bounds, shouldnt move anything
    EXPECT_EQ(board.whitePawns, 0x000000000000FF00);
}

TEST(ChessboardTest, WhitePawnBackwardMovement) {
    Chessboard board;
    Pawn::moveWhitePawn(board, 15, 7);
    EXPECT_EQ(board.whitePawns, 0x000000000000FF00);
    board.whitePawns = 0x0000000000FF0000; //Move pawns to third row
    Pawn::moveWhitePawn(board, 16, 8); //Try to move pawn backwards
    EXPECT_EQ(board.whitePawns, 0x0000000000FF0000);
}

TEST(ChessboardTest, WhiteTryTwoSquareMoveNotOnOriginalRow) {
    Chessboard board;
    board.whitePawns = 0x0000000000FF0000; //Move pawns to third row
    Pawn::moveWhitePawn(board, 20, 36);
    EXPECT_EQ(board.whitePawns, 0x0000000000FF0000);
}

TEST(ChessboardTest, WhiteTryMovingPawnsIntoOverPieces) {
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

TEST(ChessboardTest, TryWhitePawnCaptures) { 
    Chessboard board;
    board.whitePawns = 0x0000000000010000;
    board.blackPawns = 0x0000000002000000; 
    Pawn::moveWhitePawn(board, 16, 25);
    EXPECT_EQ(board.whitePawns, 0x0000000002000000); 
    EXPECT_EQ(board.blackPawns, 0x0000000000000000); 
}

TEST(ChessboardTest, TryAllCapturesWhitePawns) { 
    Chessboard board;
    board.whitePawns = 0x0000000000FF0000; 
    board.blackPawns = 0x0000000021000000;
    board.blackBishops = 0x0000000042000000;
    board.blackKnights = 0x0000000084000000;
    board.blackQueen = 0x0000000008000000,
    board.blackRooks = 0x0000000010000000;
    Pawn::moveWhitePawn(board, 16, 25);
    Pawn::moveWhitePawn(board, 17, 24);
    Pawn::moveWhitePawn(board, 18, 27);
    Pawn::moveWhitePawn(board, 19, 26);
    Pawn::moveWhitePawn(board, 20, 29);
    Pawn::moveWhitePawn(board, 21, 28);
    Pawn::moveWhitePawn(board, 22, 31);
    Pawn::moveWhitePawn(board, 23, 30);
    EXPECT_EQ(board.whitePawns, 0x00000000FF000000); 
    EXPECT_EQ(board.blackPawns, 0x0000000000000000); 
    EXPECT_EQ(board.blackBishops, 0x0000000000000000); 
    EXPECT_EQ(board.blackKnights, 0x0000000000000000); 
    EXPECT_EQ(board.blackRooks, 0x0000000000000000); 
    EXPECT_EQ(board.blackQueen, 0x0000000000000000); 
}

TEST(ChessboardTest, TryCaptureOwnPieces) {
    Chessboard board;
    board.whitePawns = 0x0000000000FF0000; 
    board.whiteBishops = 0x0000000042000000;
    board.whiteKnights = 0x0000000084000000;
    board.whiteQueen = 0x0000000008000000,
    board.whiteRooks = 0x0000000010000000;
    Pawn::moveWhitePawn(board, 16, 25);
    Pawn::moveWhitePawn(board, 18, 27);
    Pawn::moveWhitePawn(board, 19, 26);
    Pawn::moveWhitePawn(board, 21, 28);
    Pawn::moveWhitePawn(board, 22, 31);
    Pawn::moveWhitePawn(board, 23, 30);
    EXPECT_EQ(board.whitePawns, 0x0000000000FF0000); 
    EXPECT_EQ(board.whiteBishops, 0x0000000042000000); 
    EXPECT_EQ(board.whiteKnights, 0x0000000084000000); 
    EXPECT_EQ(board.whiteRooks, 0x0000000010000000); 
    EXPECT_EQ(board.whiteQueen, 0x0000000008000000); 
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