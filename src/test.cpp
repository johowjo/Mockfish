#include "board.h"
#include "moveutils.h"
#include "position.h"
#include <iostream>
#define DEBUG

// void test_bitboard() {
//   Board::Bitboard bb = 0x800ull;
//   Board::Bitboard _bb;
//   Board::show_bitboard(bb);
//   _bb = Moves::rook_squares(bb);
//   Board::show_bitboard(_bb);
//   _bb = Moves::bishop_squares(bb);
//   Board::show_bitboard(_bb);
//   _bb = Moves::queen_squares(bb);
//   Board::show_bitboard(_bb);
//   _bb = Moves::knight_squares(bb);
//   Board::show_bitboard(_bb);
//   _bb = Moves::black_pawn_move_squares(bb);
//   Board::show_bitboard(_bb);
//   _bb = Moves::white_pawn_move_squares(bb);
//   Board::show_bitboard(_bb);
//   return;
// }
void test_move_find() {
  Positions::Position pos;
}


int main() {
  std::cout << "move test\n";
  return 0;
}
