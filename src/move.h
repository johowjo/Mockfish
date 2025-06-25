#ifndef _MOVES_H
#define _MOVES_H
#include "board.h"
namespace Moves {
using namespace Board;

enum MoveType {
  CAPTURE,
  CASTLE,
  QUIET,
  ENPASSANT,
  PROMOTE,
};

struct Move {
  MoveType type;
  Square prev;
  Square next;
};
}

#endif
