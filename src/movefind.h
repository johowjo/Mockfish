#ifndef _MOVEFIND_H
#define _MOVEFIND_H
#include "move.h"
#include "pieces.h"
#include "position.h"
#include <vector>

using namespace Pieces;
using namespace Board;
using namespace Positions;

namespace Moves {

std::vector<Move> find_pawn_quiet_moves(Position position, Piece pawn);
std::vector<Move> find_pawn_capture_moves(Position position, Piece pawn);
std::vector<Move> find_pawn_promote_moves(Position position, Piece pawn);
std::vector<Move> find_pawn_enpassant_moves(Position position, Piece pawn);
std::vector<Move> find_knight_quiet_moves(Position position, Piece knight);
std::vector<Move> find_knight_capture_moves(Position position, Piece knight);
std::vector<Move> find_bishop_quiet_moves(Position position, Piece bishop);
std::vector<Move> find_bishop_capture_moves(Position position, Piece bishop);
std::vector<Move> find_queen_quiet_moves(Position position, Piece queen);
std::vector<Move> find_queen_capture_moves(Position position, Piece queen);
std::vector<Move> find_king_quiet_moves(Position position, Piece king);
std::vector<Move> find_king_capture_moves(Position position, Piece king);
std::vector<Move> find_king_castle_moves(Position position, Piece king);


std::vector<Move> find_all_moves(Position position);
}



#endif
