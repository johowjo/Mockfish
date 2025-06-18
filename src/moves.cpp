#include "moves.h"
namespace Moves {
Bitboard rook_squares(Bitboard rook_pos) {
  Bitboard bb = 0ull;
  for (int i = 0; i < 7; i++) {
    rook_pos = shift<NORTH>(rook_pos);
    bb &= rook_pos;
  }
  rook_pos = shift<NORTH>(rook_pos);
  for (int i = 0; i < 7; i++) {
    rook_pos = shift<EAST>(rook_pos);
    bb &= rook_pos;
  }

  return bb;
}
}
