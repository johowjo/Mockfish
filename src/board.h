#ifndef _BOARD_H
#define _BOARD_H
#include <cstdint>
#include <iostream>
namespace Board {
using Bitboard = uint64_t;
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
}
#endif
