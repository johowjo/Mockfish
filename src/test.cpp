#include "board.h"
#include <iostream>

void test_bitboard() {
  Board::Bitboard bb = 1ull;
  Board::show_bitboard(bb);
  return;
}

int main() {
  std::cout << "bitboard test\n";
  test_bitboard();
  return 0;
}
