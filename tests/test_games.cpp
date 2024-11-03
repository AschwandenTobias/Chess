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
}