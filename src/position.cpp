#include "positions.h"
#include "board.h"
#include "pieces.h"

namespace Positions {
Position::Position(Position parent, Move move) {
  color_to_move = opposite_color(parent.color_to_move);
  // Piece **board = new Piece*[BOARD_SIZE];

  board[move.next.file][move.next.rank] = parent.board[move.prev.file][move.prev.rank];
  board[move.prev.file][move.prev.rank] = Piece {.type =  EMPTY, .color = WHITE};
}

Piece Position::get_piece(Square square) {
  return board[square.file][square.rank];
}

}
