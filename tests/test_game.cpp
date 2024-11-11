#include <gtest/gtest.h>
#include "chessboard.h" 
#include "pieces/pawn.h"
#include "pieces/knight.h"
#include "pieces/rook.h"
#include "pieces/bishop.h"
#include "pieces/queen.h"
#include "pieces/king.h"
#include "game.h"

TEST(gameTest, TestRemovelOfNotationSymbols) {
    Game game;
    std::string moves = "1. e4 e5 2. Nc3 Nf6 3. Nf3 Nc6 4. d4 exd4 5. Nxd4 d5 $2 6. Bg5 $6 dxe4 $6 7. Nxc6 $6 Qxd1+ 8. Rxd1 bxc6 $1 9. Bc4 Bf5 10. O-O Be7 11. h3 O-O 12. Rfe1 Rfe8 13. Bxf6 Bxf6 14. a4 $2 Rab8 15. Rb1 $2 e3 16. Bd3 exf2+ 17. Kxf2 Rxe1 18. Kxe1 $2 Bxd3 19. cxd3 Bxc3+ 20. Ke2 Rxb2+ 21. Rxb2 Bxb2 22. Ke3 Kf8 23. Ke4 Ke7 24. d4 Kd6 25. g4 c5 26. dxc5+ Kxc5 27. Kf5 Kd5 28. h4 $6 c5 29. g5 c4 30. g6 $6 hxg6+ $6 0-1";
    //std::cout << "Moves before: " << moves << "\n";
    game.removeXandPlus(moves);
    game.removeChessComDollarSigns(moves);
    game.removeMoveNumbersAndResult(moves);
    //std::cout << "Moves after : " << moves << "\n";
}