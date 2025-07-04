#ifndef _POSITION_H
#define _POSITION_H
#include "board.h"
#include "pieces.h"
#include "move.h"

using namespace Board;
using namespace Moves;
using namespace Pieces;

namespace Positions {
class Position {
public:
  Bitboard get_occupied_squares();
  Position(Position parent, Move move);
  Position();
  ~Position();

private:
  Color color_to_move;
  // [file][rank]
  Piece board[BOARD_SIZE][BOARD_SIZE];
  Bitboard occupied_squares;


  Piece get_piece(Square square);

  // std::vector<Move> list_possible_moves();
};

}
#endif
