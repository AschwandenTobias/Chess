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

TEST(FullGameTest, Ian_Carlsen_Game1) {
    Game game;
        std::vector<std::string> moves = {
        "e2e4", "e7e5", "g1f3", "b8c6", "f1b5", "a7a6", "b5a4", "g8f6", "CWKS"
    };
    game.start(moves);
    //ASSERT_EQ(game.board.whiteKing , 0x0000000000000008);
    //ASSERT_EQ(game.board.whitePawns , 0x000000000800F700);
    //ASSERT_EQ(game.board.whiteRooks , 0x0000000000000081);
    //ASSERT_EQ(game.board.whiteBishops , 0x0000000020000020);
    //ASSERT_EQ(game.board.whiteKnights , 0x0000000000200002);
    //ASSERT_EQ(game.board.whiteQueen , 0x0000000000040000);
    //ASSERT_EQ(game.board.blackKing , 0x0200000000000000);
    //ASSERT_EQ(game.board.blackPawns , 0x00F7000800000000);
    //ASSERT_EQ(game.board.blackRooks , 0x8400000000000000);
    //ASSERT_EQ(game.board.blackBishops , 0x0000000000000000);
    //ASSERT_EQ(game.board.blackKnights , 0x0000000000000000);
    //ASSERT_EQ(game.board.blackQueen , 0x0000000000000000);
}