#include <gtest/gtest.h>
#include "chessboard.h" 
#include "pieces/pawn.h"
#include "pieces/knight.h"
#include "pieces/rook.h"
#include "pieces/bishop.h"
#include "pieces/queen.h"
#include "pieces/king.h"
#include "game.h"

TEST(FullGameTest, Tobi_Dobenah) {
    Game game;
        std::vector<std::string> moves = {
        "e2e4", "e7e5", "f1c4", "g8f6", "d1f3", "f8c5", "b1c3", "CBKS"
    };
    game.start(moves);
    ASSERT_EQ(game.board.whiteKing , 0x0000000000000008);
    ASSERT_EQ(game.board.whitePawns , 0x000000000800F700);
    ASSERT_EQ(game.board.whiteRooks , 0x0000000000000081);
    ASSERT_EQ(game.board.whiteBishops , 0x0000000020000020);
    ASSERT_EQ(game.board.whiteKnights , 0x0000000000200002);
    ASSERT_EQ(game.board.whiteQueen , 0x0000000000040000);
    ASSERT_EQ(game.board.blackKing , 0x0200000000000000);
    ASSERT_EQ(game.board.blackPawns , 0x00F7000800000000);
    ASSERT_EQ(game.board.blackRooks , 0x8400000000000000);
    //ASSERT_EQ(game.board.blackBishops , 0x0000000000000000);
    //ASSERT_EQ(game.board.blackKnights , 0x0000000000000000);
    //ASSERT_EQ(game.board.blackQueen , 0x0000000000000000);
}

TEST(FullGameTest, Ian_Carlsen_2021_Game1) {
    Game game;
        std::vector<std::string> moves = {
        "e2e4", "e7e5", "g1f3", "b8c6", "f1b5", "a7a6", "b5a4", "g8f6", "CWKS", "f8e7", 
        "f1e1", "b7b5", "a4b3", "CBKS", "h2h3", "c6a5", "f3e5", "a5b3", "a2b3", "c8b7",
        "d2d3", "d7d5", "e4d5", "d8d5", "d1f3", "e7d6", "g1f1", "f8b8", "f3d5", "f6d5",
        "c1d2", "c7c5", "e5f3", "b8d8", "b1c3", "d5b4", "e1c1", "a8c8", "c3e2", "b4c6",
        "d2e3", "c6e7", "e3f4", "b7f3", "g2f3", "d6f4", "e2f4", "c8c6", "c1e1", "e7f5",
        "c2c3", "f5h4", "e1e3", "g8f8", "f4g2", "h4f5", "e3e5", "g7g6", "g2e1", "f5g7",
        "e5e4", "f7f5", "e4e3", "g7e6", "e1g2", "b5b4", "f1e2", "d8b8", "e2d2", "b4c3",
        "b2c3", "b8b3", "d2c2", "b3b7", "h3h4", "f8f7", "e3e1", "f7f6", "g2e3", "b7d7",
        "e3c4", "d7e7", "c4e5", "c6d6", "e5c4", "d6c6", "c4e5", "c6d6", "e5c4"
    };
    game.start(moves);
    ASSERT_EQ(game.board.whiteKing , 0x0000000000002000);
    ASSERT_EQ(game.board.whitePawns , 0x0000000001340400);
    ASSERT_EQ(game.board.whiteRooks , 0x0000000000000088);
    ASSERT_EQ(game.board.whiteBishops , 0x0000000000000000);
    ASSERT_EQ(game.board.whiteKnights , 0x0000000020000000);
    ASSERT_EQ(game.board.whiteQueen , 0x0000000000000000);
    ASSERT_EQ(game.board.blackKing , 0x0000040000000000);
    ASSERT_EQ(game.board.blackPawns , 0x0001822400000000);
    ASSERT_EQ(game.board.blackRooks , 0x0008100000000000);
    ASSERT_EQ(game.board.blackBishops , 0x0000000000000000);
    ASSERT_EQ(game.board.blackKnights , 0x0000080000000000);
    ASSERT_EQ(game.board.blackQueen , 0x0000000000000000);
}

TEST(FullGameTest, FoolsMate) {
    Game game;
        std::vector<std::string> moves = {
        "f2f3", "e7e5", "g2g4", "d8h4"
    };
    game.start(moves);
    std::vector<std::pair<int, int>> kingMoves = King::generateAllPossibleKingMoves(game.board, true);
    std::cout << "kingMoves: ";
    for (const auto &move : kingMoves) {
        std::cout << "(" << move.first << ", " << move.second << ") ";
    }
    std::cout << "\n";
    ASSERT_EQ(game.IsCheckmate, true);
}