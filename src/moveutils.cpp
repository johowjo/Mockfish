#include "moveutils.h"
#include "board.h"
#include <algorithm>
#include <iostream>
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

  Square square = Board::bb_to_square(pos);

  // std::cout << square.file << ' ' << square.rank << '\n';

  iterate_direction(NORTH, bb, pos, 7 - square.rank);
  iterate_direction(SOUTH, bb, pos, square.rank);
  iterate_direction(EAST, bb, pos, 7 - square.file);
  iterate_direction(WEST, bb, pos, square.file);

  return bb;
}

Bitboard bishop_squares(Bitboard pos) {
  Bitboard bb = 0ull;

  Square square = Board::bb_to_square(pos);

  // std::cout << square.file << ' ' << square.rank << '\n';

  iterate_direction(NORTH_EAST, bb, pos, 7 - std::max(int(square.rank), int(square.file)));
  iterate_direction(NORTH_WEST, bb, pos, std::min(int(square.file), 7 - int(square.rank)));
  iterate_direction(SOUTH_EAST, bb, pos, std::min(7 - int(square.file), int(square.rank)));
  iterate_direction(SOUTH_WEST, bb, pos, std::min(int(square.rank), int(square.file)));

  return bb;
}

Bitboard queen_squares(Bitboard pos) {
  Bitboard bb = 0ull;

  Square square = Board::bb_to_square(pos);

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

Bitboard black_pawn_move_squares(Bitboard pos) {
  Bitboard bb = shift(SOUTH, pos);
  if (bb_to_square(pos).rank == Board::RANK_7) {
    bb |= shift(SOUTH, bb);
  }
  return bb;
}

Bitboard white_pawn_move_squares(Bitboard pos) {
  Bitboard bb = shift(NORTH, pos);
  if (bb_to_square(pos).rank == Board::RANK_2) {
    bb |= shift(NORTH, bb);
  }
  return bb;
}

Bitboard black_pawn_capture_squares(Bitboard pos) {
  return (shift(SOUTH_EAST, pos) | shift(SOUTH_WEST, pos));
}

Bitboard white_pawn_capture_squares(Bitboard pos) {
  return (shift(NORTH_EAST, pos) | shift(NORTH_WEST, pos));
}

Bitboard knight_squares(Bitboard pos) {
  Square square = bb_to_square(pos);
  int left_distance = int(square.file - FILE_A);
  int right_distance = int(FILE_H - square.file);
  int lower_distance = int(square.rank - RANK_1);
  int upper_distance = int(RANK_8 - square.rank);

  Bitboard bb = 0ull;

  bool left_2 = left_distance >= 2;
  bool left_1 = left_distance >= 1;
  bool right_2 = right_distance > 2;
  bool right_1 = right_distance >= 1;
  bool lower_2 = lower_distance >= 2;
  bool lower_1 = lower_distance >= 1;
  bool upper_2 = upper_distance >= 2;
  bool upper_1 = upper_distance >= 1;

  if (left_1) {
    if (upper_1) {
      Bitboard nw = shift(NORTH_WEST, pos);
      if (left_2) {
        bb |= shift(WEST, nw);
      }
      if (upper_2) {
        bb |= shift(NORTH, nw);
      }
    }

    if (lower_1) {
      Bitboard sw = shift(SOUTH_WEST, pos);
      if (left_2) {
        bb |= shift(WEST, sw);
      }
      if (lower_2) {
        bb |= shift(SOUTH, sw);
      }
    }
  }

  if (right_1) {
    if (upper_1) {
      Bitboard ne = shift(NORTH_EAST, pos);
      if (right_2) {
        bb |= shift(EAST, ne);
      }
      if (upper_2) {
        bb |= shift(NORTH, ne);
      }
    }

    if (lower_1) {
      Bitboard se = shift(SOUTH_EAST, pos);
      if (left_2) {
        bb |= shift(EAST, se);
      }
      if (lower_2) {
        bb |= shift(SOUTH, se);
      }
    }
  }

  return bb;
}

}
