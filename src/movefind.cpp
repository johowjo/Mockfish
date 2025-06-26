#include "movefind.h"
#include "moveutils.h"
#include <assert.h>

namespace Moves {

std::vector<Move> find_pawn_quiet_moves(Position position, Piece pawn) {
  assert(pawn.type == PAWN);
  std::vector<Move> moves;
  Bitboard piece_position = square_to_bb(pawn.square);
  Bitboard bb = pawn.color == WHITE ? white_pawn_move_squares(piece_position) : black_pawn_move_squares(piece_position);

  bb = bitboard_diff(bb, position.get_occupied_squares());
  std::vector<Square> available_squares = bb_to_squares(bb);
  
  for (Square sq : available_squares) {
    moves.push_back(Move {.type = QUIET, .prev = pawn.square, .next = sq});
  }

  return moves;
}




}
