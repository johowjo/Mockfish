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

Bitboard shift (Direction dir, const Bitboard bb);


// returns available squares for a piece from its position
// assuming empty board
Bitboard rook_squares(Bitboard pos);

Bitboard bishop_squares(Bitboard pos);

Bitboard queen_squares(Bitboard pos);

Bitboard knight_squares(Bitboard pos);

Bitboard king_squares(Bitboard pos);

// returns available squares for a piece to move to (not capture)
// assuming empty board
Bitboard black_pawn_move_squares(Bitboard pos);

Bitboard white_pawn_move_squares(Bitboard pos);

// returns available squares for a piece to capture at
// assuming empty board
Bitboard black_pawn_capture_squares(Bitboard pos);

Bitboard white_pawn_capture_squares(Bitboard pos);


}

#endif
