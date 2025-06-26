#ifndef _PIECES_H
#define _PIECES_H
#include "board.h"
#include <algorithm>
using namespace Board;
namespace Pieces{

enum PieceType {
  PAWN,
  KNIGHT,
  BISHOP,
  QUEEN,
  KING,
  EMPTY,
};

struct Piece {
  PieceType type;
  Color color;
  Square square;
};

// class Piece {
//   PieceType Type;
//   Color color;
//   Square square;
// };
}
#endif
