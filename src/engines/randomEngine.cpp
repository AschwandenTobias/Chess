#include "randomEngine.h"
#include <iostream>
#include <random>

std::pair<int, int> RandomEngine::selectRandomMove(std::vector<std::pair<int, int>> allMoves, bool isWhite) {
    std::random_device rd;                        
    std::mt19937 gen(rd());                      
    std::uniform_int_distribution<> dis(0, allMoves.size() - 1); 
    int randomIndex = dis(gen);
    /*for (const auto& move : allMoves) {
        std::cout << "Start: " << move.first << ", End: " << move.second << std::endl;
    }<*/
    //std::cout << "Random Index: " << randomIndex << "\n";
    std::pair<int, int> randomMove = allMoves[randomIndex];
    //std::cout << "Random Move: " << randomMove.first << ", " << randomMove.second << "\n";
    return randomMove;
}