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
    std::cout << "Welcome to the Chess Game!\n";
    std::cout << "Please select an option:\n";
    std::cout << "1. Play a normal game\n";
    std::cout << "2. Play against the engine\n";
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
    } else {
        std::cout << "Invalid choice. Exiting.\n";
        return 1;
    }
    
    return 0;
}