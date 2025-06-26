#include "board.h"
#include <iostream>
namespace Board {
void show_bitboard(Bitboard bb) {
  std::cout << "number of bitboard: " << bb << '\n';
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      int bit = 56 - 8 * i + j;
      // printf("%x ", bit);
      std::cout << (((bb >> bit) & 1ull) ? '1' : '0');
    }
    std::cout << '\n';
  }
}

Square bb_to_square(Bitboard bb) {
  int bit = 0;
  while (true) {
    if ((bb >> bit) & 1ull) {
      break;
    }
    bit++;
  }

  return Square(bit % 8, bit / 8);
}

std::vector<Square> bb_to_squares(Bitboard bb) {
  std::vector<Square> v;
  int bit = 0;
  while (true) {
    if ((bb >> bit) & 1ull) {
      break;
    }
    bit++;
    v.push_back(Square(bit % 8, bit / 8));
  }

  return v;
}

Square::Square(int f, int r) {
  rank = Rank(r);
  file = File(f);
}

Bitboard square_to_bb(Square square) {
  int bit = 8 * square.file + square.rank;
  return Bitboard(1 << bit);
}

}
