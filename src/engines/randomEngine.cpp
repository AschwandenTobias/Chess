#include "randomEngine.h"
#include <random>

std::pair<int, int> RandomEngine::selectRandomMove(std::vector<std::pair<int, int>> allMoves, bool isWhite) {
    std::random_device rd;                        
    std::mt19937 gen(rd());                      
    std::uniform_int_distribution<> dis(0, allMoves.size() - 1); 
    int randomIndex = dis(gen);
    return allMoves[randomIndex];
}