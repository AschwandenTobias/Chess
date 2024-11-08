#include <gtest/gtest.h>
#include "chessboard.h"
#include "pieces/King.h"
#include "pieces/Pawn.h"
#include "game.h"
#include "pieces/Queen.h"
#include "pieces/Knight.h"
#include "pieces/Rook.h"
#include <utility> // For std::pair

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

TEST(KingTest, TestGetAttackingSquares) {
    Game game;
    Pawn::moveWhitePawn(game.board, 11, 19);
    Pawn::moveBlackPawn(game.board, 50, 42);
    Queen::moveWhiteQueen(game.board, 4, 32);
    game.board.printBoard();
    std::vector<int> shouldSquares = {32, 41, 50};
    std::vector<int> attackingSquares = Queen::getAttackingSquares(game.board, 32, 59);
    //std::cout << "Number of attacking Squares: " << attackingSquares.size() << "\n";
    EXPECT_EQ(shouldSquares.size(), attackingSquares.size());
    EXPECT_EQ(shouldSquares, attackingSquares);
}

TEST(KingTest, TestCanPieceInterfere_WhiteQueenOnBorder) {
    Game game;
    Pawn::moveWhitePawn(game.board, 11, 19);
    Pawn::moveBlackPawn(game.board, 50, 42);
    Queen::moveWhiteQueen(game.board, 4, 32);
    game.board.printBoard();
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

TEST(KingTest, GeneratedPossibleKingMoves_OneBoardBorder) {
    Game game;
    game.board.whiteKing = 0x0000000001000000;
    std::vector<std::pair<int, int>> shouldSquares = {{24, 31}, {24, 17}, {24, 16}, {24, 25}, {24, 33}};
    EXPECT_EQ(King::generateAllPossibleKingMoves(game.board, true), shouldSquares);
}