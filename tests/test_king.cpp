#include <gtest/gtest.h>
#include "chessboard.h"
#include "pieces/King.h"
#include "pieces/Pawn.h"
#include "game.h"
#include "pieces/Queen.h"
#include "pieces/Bishop.h"
#include "pieces/Knight.h"
#include "pieces/Rook.h"
#include <utility> 
#include <algorithm> 

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
    //board.printBoard();
}

TEST(KingTest, TestKingBordersLimits) {
    Game game;
    Pawn::moveWhitePawn(game.board, 11, 19);
    King::moveWhiteKing(game.board, 3, 11);
    King::moveWhiteKing(game.board, 11, 18);
    King::moveWhiteKing(game.board, 18, 17);
    King::moveWhiteKing(game.board, 17, 16);
    King::moveWhiteKing(game.board, 16, 23);
    EXPECT_EQ(game.board.whiteKing, 0x0000000000010000);
    //game.board.printBoard();
}

TEST(KingTest, ManuallyTestKingBorderMovement) {
    Game game;
    game.board.whiteKing = 0x0000000001000000;
    EXPECT_EQ(King::isWhiteKingMoveLegal(game.board, 24, 15), false);
    EXPECT_EQ(King::isWhiteKingMoveLegal(game.board, 24, 23), false);
    EXPECT_EQ(King::isWhiteKingMoveLegal(game.board, 24, 31), false);
    EXPECT_EQ(King::isWhiteKingMoveLegal(game.board, 24, 16), true);
    EXPECT_EQ(King::isWhiteKingMoveLegal(game.board, 24, 17), true);
    EXPECT_EQ(King::isWhiteKingMoveLegal(game.board, 24, 25), true);
    EXPECT_EQ(King::isWhiteKingMoveLegal(game.board, 24, 33), true);
    EXPECT_EQ(King::isWhiteKingMoveLegal(game.board, 24, 32), true);
    game.board.printBoard();
}

TEST(KingTest, TestNumberOfAttackingPieces_NoPiece) {
    Game game;
    ASSERT_EQ(King::numberOfAttackingPieces(game.board, 3, true), 0); //Just checks if enemy pieces can attack the King in the starting Squares (shouldnt)
    ASSERT_EQ(King::numberOfAttackingPieces(game.board, 59, false), 0);
}

TEST(KingTest, TestNumberOfAttackingPieces_OnePiece) {
    Game game;
    Pawn::moveWhitePawn(game.board, 11, 19);
    Pawn::moveBlackPawn(game.board, 50, 42);
    Queen::moveWhiteQueen(game.board, 4, 32);
    //game.board.printBoard();
    ASSERT_EQ(King::checkWhiteQueenMovesForCheck(game.board, 59), true); //Check if Queen can check the King
    ASSERT_EQ(King::numberOfAttackingPieces(game.board, 59, false), 1); //Move the whiteQueen to check the black King.
}

TEST(KingTest, TestNumberOfAttackingPieces_TwoPieces) {
    Game game;
    Pawn::moveWhitePawn(game.board, 11, 19);
    Knight::moveBlackKnight(game.board, 57, 42);
    Knight::moveBlackKnight(game.board, 42, 25);
    Knight::moveBlackKnight(game.board, 25, 19);
    Pawn::moveBlackPawn(game.board, 48, 32);
    Rook::moveBlackRook(game.board, 56, 40);
    Rook::moveBlackRook(game.board, 40, 43);
    Knight::moveBlackKnight(game.board, 19, 9);
    //game.board.printBoard();
    ASSERT_EQ(King::numberOfAttackingPieces(game.board, 3, true), 2);
}

TEST(KingTest, TestGetAttackingSquaresQueen) {
    Game game;
    Pawn::moveWhitePawn(game.board, 11, 19);
    Pawn::moveBlackPawn(game.board, 50, 42);
    Queen::moveWhiteQueen(game.board, 4, 32);
    //game.board.printBoard();
    std::vector<int> shouldSquares = {32, 41, 50};
    std::vector<int> attackingSquares = Queen::getAttackingSquares(game.board, 32, 59);
    //std::cout << "Number of attacking Squares: " << attackingSquares.size() << "\n";
    EXPECT_EQ(shouldSquares.size(), attackingSquares.size());
    EXPECT_EQ(shouldSquares, attackingSquares);
}

TEST(KingTest, TestGetAttackingSquaresBishop) {
    Game game;
    Pawn::moveWhitePawn(game.board, 11, 19);
    Pawn::moveBlackPawn(game.board, 50, 42);
    King::moveBlackKing(game.board, 59, 50);
    Bishop::moveWhiteBishop(game.board, 2, 29);
    game.board.printBoard();
    std::vector<int> shouldSquares = {29, 36, 43, 50};
    std::vector<int> areSquares = King::getAttackingSquares(game.board, 50, false);
    EXPECT_EQ(areSquares, shouldSquares);
}

TEST(KingTest, TestCanPieceInterfere_WhiteQueenOnBorder) {
    Game game;
    Pawn::moveWhitePawn(game.board, 11, 19);
    Pawn::moveBlackPawn(game.board, 50, 42);
    Queen::moveWhiteQueen(game.board, 4, 32);
    //game.board.printBoard();
    EXPECT_EQ(King::canPieceInterfereCheck(game.board, true), false); //no piece should be able to interfere
}

TEST(KingTest, GeneratedPossibleKingMoves_OnStartSquare) {
    Game game;
    std::vector<std::pair<int, int>> shouldSquares = {};
    EXPECT_EQ(King::generateAllPossibleKingMoves(game.board, true), shouldSquares);
}


TEST(KingTest, GeneratedPossibleKingMoves_OneSquareForward) {
    Game game;
    Pawn::moveWhitePawn(game.board, 11, 19);
    std::vector<std::pair<int, int>> shouldSquares = {{3, 11}};
    EXPECT_EQ(King::generateAllPossibleKingMoves(game.board, true), shouldSquares);
}

TEST(KingTest, GeneratedPossibleKingMoves_KingOnBoardBorder) {
    Game game;
    game.board.whiteKing = 0x0000000001000000;
    std::vector<std::pair<int, int>> shouldSquares = {{24, 32}, {24, 17}, {24, 16}, {24, 25}, {24, 33}};
    std::vector<std::pair<int, int>> areSquares = King::generateAllPossibleKingMoves(game.board, true);
    std::sort(shouldSquares.begin(), shouldSquares.end());
    std::sort(areSquares.begin(), areSquares.end());
    EXPECT_EQ(areSquares, shouldSquares);
}

TEST(KingTest, GeneratedPossibleKingMoves_blackKingInMate) {
    Game game;
    Pawn::moveWhitePawn(game.board, 11, 19);
    Queen::moveWhiteQueen(game.board, 4, 32);
    Bishop::moveWhiteBishop(game.board, 2, 29);
    Queen::moveWhiteQueen(game.board, 32, 50);
    game.board.printBoard();
    std::vector<std::pair<int, int>> shouldSquares = {};
    std::vector<std::pair<int, int>> areSquares = King::generateAllPossibleKingMoves(game.board, false);
    std::sort(shouldSquares.begin(), shouldSquares.end());
    std::sort(areSquares.begin(), areSquares.end());
    EXPECT_EQ(areSquares, shouldSquares);
}

TEST(KingTest, getAllPossibleKingMoves_startingPosition) {
    Game game;
    Pawn::moveWhitePawn(game.board, 9, 17);
    Bishop::moveWhiteBishop(game.board, 2, 9);
    Knight::moveWhiteKnight(game.board, 1, 18);
    Pawn::moveBlackPawn(game.board, 52, 36);
    Bishop::moveBlackBishop(game.board, 61, 43);
    Queen::moveBlackQueen(game.board, 60, 44);
    Knight::moveBlackKnight(game.board, 62, 47);
    std::vector<std::pair<int, int>> areSquaresWhite = King::getAllPossibleKingMoves(game.board, true);
    std::vector<std::pair<int, int>> shouldSquaresWhite = {{3, 2}, {3, 1}};
    std::vector<std::pair<int, int>> areSquaresBlack = King::getAllPossibleKingMoves(game.board, false);
    std::vector<std::pair<int, int>> shouldSquaresBlack = {{59, 60}, {59, 52}, {59, 61}};
    //game.board.printBoard();
    ASSERT_EQ(areSquaresWhite, shouldSquaresWhite);
    ASSERT_EQ(areSquaresBlack, shouldSquaresBlack);
}