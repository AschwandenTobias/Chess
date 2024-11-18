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
    /*std::vector<std::pair<int, int>> allMoves = game.board.generateAllPossibleMoves(true);

    for (const auto& move : allMoves) {
        std::cout << "Start: " << move.first << ", End: " << move.second << std::endl;
    }
   std::vector<std::string> tmpMoves = {
        "e2e4", "c7c5", "f1c4", "e7e6", "d2d4", "h7h6", "d4d5", "d8f6", "d5e6", "f6g5", "e6f7", "e8e7", "c1g5", "h6g5", "b1c3" ,"b7b5", "d1g4", "h8h3","g4g5", "g8f6", "e4e5" ,"h3e3", "e5f6"
    };
    game.start(tmpMoves);*/
    
    std::vector<std::string> moves;
    std::cout << "Welcome to the Chess Game!\n";
    std::cout << "Please select an option:\n";
    std::cout << "1. Play a normal game\n";
    std::cout << "2. Play against the engine\n";
    std::cout << "3. Let the engine play itself\n";
    std::cout << "Enter your choice: ";
    
    int choice;
    std::cin >> choice;
    
    if (choice == 1) {
        std::cout << "Starting a normal game...\n";
        game.start(moves);  
    } else if (choice == 2) {
        std::cout << "Starting a game against the engine...\n";
        bool userIsWhite;
        std::cout << "Do you want to play as white? (1 for Yes, 0 for No): ";
        std::cin >> userIsWhite;
        
        game.startRandomEngine(userIsWhite); 
    } else if(choice == 3) {
        std::cout << "Engine plays itself\n";
        game.startRandomEnginePlayingItself();
    } else {
        std::cout << "Invalid choice. Exiting.\n";
        return 1;
    }
    
    return 0;
}