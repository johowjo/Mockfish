#ifndef _POSITION_H
#define _POSITION_H
#include "board.h"
#include "pieces.h"
#include "move.h"
#include <vector>
using namespace Board;
using namespace Moves;
using namespace Pieces;
namespace Positions {
class Position {
public:
  Bitboard get_occupied_squares();
private:
  Color color_to_move;
  Piece board[BOARD_SIZE][BOARD_SIZE];
  Bitboard occupied_squares;

  Position(Position parent, Move move);
  
  ~Position();

  Piece get_piece(Square square);

  // std::vector<Move> list_possible_moves();
};

}
#endif
