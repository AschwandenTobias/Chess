#include <iostream>
#include "chessboard.h" 
#include "pieces/pawn.h"
#include "pieces/knight.h"
#include "pieces/rook.h"
#include "pieces/bishop.h"
#include "pieces/queen.h"
#include "pieces/king.h"
#include "game.h"


int main() {
    Game game;
    std::vector<std::string> moves;
    game.start(moves);
    
    return 0; 
}