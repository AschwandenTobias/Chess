#ifndef CHESSBOARD_H
#define CHESSBOARD_H
#include <string>
#include "position.h"

class Chessboard {
public:
    Chessboard();
    Position position;
    
    std::string toString() const;
};
#endif