#include <iostream>
#include "game.h"

int main() {
    std::cout << "Hello there! Welcome to my chess game!\n";
    std::cout << "Type 1 if you wanna play a new game\n";
    int x = 0;
    std::cin >> x;
    if(x == 1) {
        std::cout << "A new game will now be started\n";
        Game game;
        game.startGame();
    } else {
        std::cout << "Unrecognized user input :(\n";
    }
}