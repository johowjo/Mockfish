#include "moves.h"
#include "board.h"
#include <algorithm>
namespace Moves {

Bitboard shift (Direction dir, const Bitboard bb) {
  if (dir == NORTH) {
    return bb << 8;
  } else if (dir == SOUTH) {
    return bb >> 8;
  } else if (dir == EAST) {
    return bb << 1;
  } else if (dir == WEST) {
    return bb >> 1;
  } else if (dir == NORTH_EAST) {
    return bb << 9;
  } else if (dir == NORTH_WEST) {
    return bb << 7;
  } else if (dir == SOUTH_EAST) {
    return bb >> 7;
  } else if (dir == SOUTH_WEST) {
    return bb >> 9;
  } else {
    std::cerr << "invalid shift direction\n";
    return -1;
  }
}

void iterate_direction(Direction dir, Bitboard &bb, const Bitboard pos, int steps) {
  Bitboard _bb = shift(dir, pos);
  for (int i = 0; i < steps; i++) {
    bb |= _bb;
    _bb = shift(dir, _bb);
  }
}

Bitboard rook_squares(Bitboard pos) {
  Bitboard bb = 0ull;

  Square square = Board::get_square(pos);

  // std::cout << square.file << ' ' << square.rank << '\n';

  iterate_direction(NORTH, bb, pos, 7 - square.rank);
  iterate_direction(SOUTH, bb, pos, square.rank);
  iterate_direction(EAST, bb, pos, 7 - square.file);
  iterate_direction(WEST, bb, pos, square.file);

  return bb;
}

Bitboard bishop_squares(Bitboard pos) {
  Bitboard bb = 0ull;

  Square square = Board::get_square(pos);

  // std::cout << square.file << ' ' << square.rank << '\n';

  iterate_direction(NORTH_EAST, bb, pos, 7 - std::max(int(square.rank), int(square.file)));
  iterate_direction(NORTH_WEST, bb, pos, std::min(int(square.file), 7 - int(square.rank)));
  iterate_direction(SOUTH_EAST, bb, pos, std::min(7 - int(square.file), int(square.rank)));
  iterate_direction(SOUTH_WEST, bb, pos, std::min(int(square.rank), int(square.file)));

  return bb;
}

Bitboard queen_squares(Bitboard pos) {
  Bitboard bb = 0ull;

  Square square = Board::get_square(pos);

  // std::cout << square.file << ' ' << square.rank << '\n';

  iterate_direction(NORTH, bb, pos, 7 - square.rank);
  iterate_direction(SOUTH, bb, pos, square.rank);
  iterate_direction(EAST, bb, pos, 7 - square.file);
  iterate_direction(WEST, bb, pos, square.file);

  iterate_direction(NORTH_EAST, bb, pos, 7 - std::max(int(square.rank), int(square.file)));
  iterate_direction(NORTH_WEST, bb, pos, std::min(int(square.file), 7 - int(square.rank)));
  iterate_direction(SOUTH_EAST, bb, pos, std::min(7 - int(square.file), int(square.rank)));
  iterate_direction(SOUTH_WEST, bb, pos, std::min(int(square.rank), int(square.file)));

  return bb;
}

}
