#include "move.h"

#include <iostream>

std::ostream& operator<<(std::ostream& os, MoveType type) {
    switch (type) {
        case MoveType::NORMAL:            return os << "NORMAL";
        case MoveType::CAPTURE:           return os << "CAPTURE";
        case MoveType::PROMOTION:         return os << "PROMOTION";
        case MoveType::PROMOTION_CAPTURE: return os << "PROMOTION_CAPTURE";
        case MoveType::CASTLE_KINGSIDE:   return os << "CASTLE_KINGSIDE";
        case MoveType::CASTLE_QUEENSIDE:  return os << "CASTLE_QUEENSIDE";
        case MoveType::EN_PASSANT:        return os << "EN_PASSANT";
        case MoveType::DOUBLE_PAWN_MOVE:   return os << "DOUBLE_PAWN_MOVE";
    }
    return os << "UNKNOWN";
}