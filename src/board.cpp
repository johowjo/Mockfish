#include "board.h"
#include <iostream>
namespace Board {
void show_bitboard(Bitboard bb) {
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      int bit = 56 - 8 * i + j;
      // printf("%x ", bit);
      std::cout << (((bb >> bit) & 1ull) ? '1' : '0');
    }
    std::cout << '\n';
  }
}
}
