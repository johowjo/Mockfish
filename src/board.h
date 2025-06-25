#ifndef _BOARD_H
#define _BOARD_H
#include <cstdint>
#include <iostream>
#define BOARD_SIZE 8
namespace Board {
using Bitboard = uint64_t;
enum Color {
  WHITE,
  BLACK,
};

enum File {
  FILE_A,
  FILE_B,
  FILE_C,
  FILE_D,
  FILE_E,
  FILE_F,
  FILE_G,
  FILE_H,
};

enum Rank {
  RANK_1,
  RANK_2,
  RANK_3,
  RANK_4,
  RANK_5,
  RANK_6,
  RANK_7,
  RANK_8,
};

struct Square {
  File file;
  Rank rank;
};

void show_bitboard(Bitboard bb);

Square bb_to_square(Bitboard bb);

Bitboard square_to_bb(Square square);

inline Color opposite_color(Color color) {
  return color == WHITE ? BLACK : WHITE;
}

}
#endif
