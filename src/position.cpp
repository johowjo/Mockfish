#include "position.h"
#include "board.h"
#include "pieces.h"

namespace Positions {
Position::Position(Position parent, Move move) {
  color_to_move = opposite_color(parent.color_to_move);
  // Piece **board = new Piece*[BOARD_SIZE];

  board[move.next.file][move.next.rank] = parent.board[move.prev.file][move.prev.rank];
  board[move.prev.file][move.prev.rank] = Piece {.type =  EMPTY, .color = WHITE};
}

Bitboard Position::get_occupied_squares() {
  return occupied_squares;
}

Piece Position::get_piece(Square square) {
  return board[square.file][square.rank];
}

// initial position
Position::Position() {
  color_to_move = WHITE;
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      if (i > RANK_2 && i < RANK_7) {
        board[j][i] = Piece {.type = EMPTY};
      } else if (i == RANK_2) {
        board[j][i] = Piece {.type = PAWN, .color = WHITE};
      } else if (i == RANK_7) {
        board[j][i] = Piece {.type = PAWN, .color = BLACK};
      } else if (i == RANK_1) {
        if (j == FILE_A || j == FILE_H) {
          board[j][i] = Piece {.type = ROOK, .color = WHITE};
        } else if (j == FILE_B || j == FILE_G) {
          board[j][i] = Piece {.type = KNIGHT, .color = WHITE};
        } else if (j == FILE_C || j == FILE_F) {
          board[j][i] = Piece {.type = BISHOP, .color = WHITE};
        } else if (j == FILE_D) {
          board[j][i] = Piece {.type = QUEEN, .color = WHITE};
        } else if (j == FILE_E) {
          board[j][i] = Piece {.type = KING, .color = WHITE};
        }
      } else if (i == RANK_8) {
        if (j == FILE_A || j == FILE_H) {
          board[j][i] = Piece {.type = ROOK, .color = BLACK};
        } else if (j == FILE_B || j == FILE_G) {
          board[j][i] = Piece {.type = KNIGHT, .color = BLACK};
        } else if (j == FILE_C || j == FILE_F) {
          board[j][i] = Piece {.type = BISHOP, .color = BLACK};
        } else if (j == FILE_D) {
          board[j][i] = Piece {.type = QUEEN, .color = BLACK};
        } else if (j == FILE_E) {
          board[j][i] = Piece {.type = KING, .color = BLACK};
        }
      }
    }
  }
}

}
