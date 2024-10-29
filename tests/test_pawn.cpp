#include <gtest/gtest.h>
#include "chessboard.h"
#include "pieces/pawn.h"

TEST(PawnTest, InitialPawnPositions) {
    Chessboard chessboard;
    EXPECT_EQ(chessboard.whitePawns, 0x000000000000FF00);
    EXPECT_EQ(chessboard.blackPawns, 0x00FF000000000000);
}

TEST(PawnTest, InitialWhiteMovements) {
    Chessboard board;
    Pawn::moveWhitePawn(board, 8, 16);
    EXPECT_EQ(board.whitePawns, 0x000000000001FE00);
    board.whitePawns = 0x000000000000FF00;
    Pawn::moveWhitePawn(board, 9, 25);
    EXPECT_EQ(board.whitePawns, 0x000000000200FD00);
}

TEST(PawnTest, WhiteOutOfBoundPawnMovements) {
    Chessboard board;
    Pawn::moveWhitePawn(board, -1, 7); //Negative move, shouldnt move anything
    Pawn::moveWhitePawn(board, 8, 64); //Movement out of chessboard bounds, shouldnt move anything
    EXPECT_EQ(board.whitePawns, 0x000000000000FF00);
}

TEST(PawnTest, WhitePawnBackwardMovement) {
    Chessboard board;
    Pawn::moveWhitePawn(board, 15, 7);
    EXPECT_EQ(board.whitePawns, 0x000000000000FF00);
    board.whitePawns = 0x0000000000FF0000; //Move pawns to third row
    Pawn::moveWhitePawn(board, 16, 8); //Try to move pawn backwards
    EXPECT_EQ(board.whitePawns, 0x0000000000FF0000);
}

TEST(PawnTest, WhiteTryTwoSquareMoveNotOnOriginalRow) {
    Chessboard board;
    board.whitePawns = 0x0000000000FF0000; //Move pawns to third row
    Pawn::moveWhitePawn(board, 20, 36);
    EXPECT_EQ(board.whitePawns, 0x0000000000FF0000);
}

TEST(PawnTest, WhiteTryMovingPawnsIntoOverPieces) {
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

TEST(PawnTest, TryWhitePawnCaptures) { 
    Chessboard board;
    board.whitePawns = 0x0000000000010000;
    board.blackPawns = 0x0000000002000000; 
    Pawn::moveWhitePawn(board, 16, 25);
    EXPECT_EQ(board.whitePawns, 0x0000000002000000); 
    EXPECT_EQ(board.blackPawns, 0x0000000000000000); 
}

TEST(PawnTest, TryAllCapturesWhitePawns) { 
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

TEST(PawnTest, TryCaptureOwnPieces) {
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

TEST(PawnTest, BlackPawnMovements) {
    Chessboard board;
    Pawn::moveBlackPawn(board, 55, 47);
    EXPECT_EQ(board.blackPawns, 0x007F800000000000);
    board.blackPawns = 0x00FF000000000000;
    Pawn::moveBlackPawn(board, 48, 32);
    EXPECT_EQ(board.blackPawns, 0x00FE000100000000);
    Pawn::moveBlackPawn(board, 32, 16); //Try double move not on starting square
    EXPECT_EQ(board.blackPawns, 0x00FE000100000000);
    Pawn::moveBlackPawn(board, 32, 40); //Test if blackPawns can move backwards
    EXPECT_EQ(board.blackPawns, 0x00FE000100000000);
    board.blackBishops = 0x0000808000000000; //BlackBishops in the way, pawn shouldnt move/jump over.
    Pawn::moveBlackPawn(board, 55, 47);
    Pawn::moveBlackPawn(board, 55, 39);
    EXPECT_EQ(board.blackPawns, 0x00FE000100000000); 
    EXPECT_EQ(board.blackBishops, 0x0000808000000000);
}

TEST(PawnTest, TryAllCapturesBlackPawns) { 
    Chessboard board;
    board.blackPawns = 0x000000FF00000000; 
    board.whitePawns = 0x0000000021000000;
    board.whiteBishops = 0x0000000042000000;
    board.whiteKnights = 0x0000000084000000;
    board.whiteQueen = 0x0000000008000000,
    board.whiteRooks = 0x0000000010000000;
    Pawn::moveBlackPawn(board, 32, 25);
    Pawn::moveBlackPawn(board, 33, 24);
    Pawn::moveBlackPawn(board, 34, 27);
    Pawn::moveBlackPawn(board, 35, 26);
    Pawn::moveBlackPawn(board, 36, 29);
    Pawn::moveBlackPawn(board, 37, 28);
    Pawn::moveBlackPawn(board, 38, 31);
    Pawn::moveBlackPawn(board, 39, 30);
    EXPECT_EQ(board.blackPawns, 0x00000000FF000000); 
    EXPECT_EQ(board.whitePawns, 0x0000000000000000); 
    EXPECT_EQ(board.whiteBishops, 0x0000000000000000); 
    EXPECT_EQ(board.whiteKnights, 0x0000000000000000); 
    EXPECT_EQ(board.whiteRooks, 0x0000000000000000); 
    EXPECT_EQ(board.whiteQueen, 0x0000000000000000); 
}

TEST(PawnTest, TryWhiteEnPassant) { 
    Chessboard board;
    Pawn::moveWhitePawn(board, 8, 24);
    Pawn::moveWhitePawn(board, 24, 32);
    Pawn::moveBlackPawn(board, 49, 33);
    Pawn::moveWhitePawn(board, 32, 41);
    EXPECT_EQ(board.whitePawns, 0x000002000000FE00); 
    EXPECT_EQ(board.blackPawns, 0x00FD000000000000); 
}

TEST(PawnTest, TryWBlackEnPassant) { 
    Chessboard board;
    Pawn::moveBlackPawn(board, 48, 32);
    Pawn::moveBlackPawn(board, 32, 24);
    Pawn::moveWhitePawn(board, 9, 25);
    Pawn::moveBlackPawn(board, 24, 17);
    EXPECT_EQ(board.blackPawns, 0x00FE000000020000); 
    EXPECT_EQ(board.whitePawns, 0x000000000000FD00); 
}

TEST(PawnTest, EnPassantNotDoubleMoveBefore) {
    Chessboard board;
    Pawn::moveWhitePawn(board, 8, 24);
    Pawn::moveWhitePawn(board, 24, 32);
    Pawn::moveWhitePawn(board, 15, 31);
    Pawn::moveBlackPawn(board, 49, 33);
    Pawn::moveBlackPawn(board, 54, 38);
    Pawn::moveBlackPawn(board, 38, 30);

    Pawn::moveWhitePawn(board, 32, 41); //Should be illegal
    Pawn::moveBlackPawn(board, 30, 21); //Should be illegal

    EXPECT_EQ(board.blackPawns, 0x00BD000240000000); 
    EXPECT_EQ(board.whitePawns, 0x0000000180007E00); 
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

/*
TODO: 
-Try en passant
*/