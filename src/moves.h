#ifndef _MOVES_H
#include "board.h"
namespace Moves {
using namespace Board;
enum Direction {
  NORTH,
  SOUTH,
  EAST,
  WEST,
  NORTH_EAST,
  NORTH_WEST,
  SOUTH_EAST,
  SOUTH_WEST,
};

template <Direction dir>
Bitboard shift (Bitboard bb) {
  if (dir == NORTH) {
    return bb << 8;
  } else if (dir == SOUTH) {
    return bb >> 8;
  } else if (dir == EAST) {
    return bb << 1;
  } else if (dir == WEST) {
    return bb >> 1;
  } else if (dir == NORTH_EAST) {
    return bb << 7;
  } else if (dir == NORTH_WEST) {
    return bb << 9;
  } else if (dir == SOUTH_EAST) {
    return bb >> 9;
  } else if (dir == SOUTH_WEST) {
    return bb >> 7;
  } else {
    std::cerr << "invalid shift direction\n";
    return -1;
  }
}


// return available squares for a rook
Bitboard rook_squares(Bitboard rook_pos);

// return available squares for a bishop
Bitboard bishop_squares(Bitboard bishop_pos);

// return available squares for a queen
Bitboard queen_squares(Bitboard queen_pos);

// return available squares for a knight
Bitboard knight_squares(Bitboard knight_pos);

// return available squares for a king
Bitboard king_squares(Bitboard king_pos);

// return available squares for a pawn
Bitboard pawn_squares(Bitboard pawn_pos);


}

#endif
